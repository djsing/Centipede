#include "DEFINITIONS.h"
#include "StateRenderer.h"

namespace GameEngine
{
StateRenderer::StateRenderer(DataPtr data) : data_(data)
{
    data_->resources.LoadTexture("Splash Screen Background", SPLASH_BACKGROUND_FILEPATH_);
    data_->resources.LoadTexture("Game Win Sprite", GAME_WON_);
    data_->resources.LoadTexture("Press F12 Restart", GAME_OVER_RESTART_FILEPATH_);
    data_->resources.LoadTexture("Game Over Sprite", GAME_OVER_FILEPATH_);
    data_->resources.LoadTexture("Menu Screen Title", GAME_TITLE_FILEPATH_);
    data_->resources.LoadTexture("Subtitle", GAME_SUBTITLE_FILEPATH_);
    data_->resources.LoadTexture("Instructions", GAME_INSTRUCTIONS_);
    // load pause sprites
    data_->resources.LoadTexture("Game Paused Sprite", PAUSE_FILEPATH_);
    data_->resources.LoadTexture("Press Space Resume", PAUSE_SPACE_FILEPATH_);
    // create pause background
    resume_background_.create(data_->window.getSize().x, data_->window.getSize().y);
    resume_background_.update(data_->window);
    resume_background_sprite_.setTexture(resume_background_);
}

void StateRenderer::DisplayHighScore()
{
    auto score = data_->score_manager.GetHighScore();
    for(unsigned int i = 0; i < score.size(); i++)
	{
	    switch(score.at(i))
		{
		case '0':
		    score_digit_.setTexture(data_->resources.GetTexture("0"));
		    break;
		case '1':
		    score_digit_.setTexture(data_->resources.GetTexture("1"));
		    break;
		case '2':
		    score_digit_.setTexture(data_->resources.GetTexture("2"));
		    break;
		case '3':
		    score_digit_.setTexture(data_->resources.GetTexture("3"));
		    break;
		case '4':
		    score_digit_.setTexture(data_->resources.GetTexture("4"));
		    break;
		case '5':
		    score_digit_.setTexture(data_->resources.GetTexture("5"));
		    break;
		case '6':
		    score_digit_.setTexture(data_->resources.GetTexture("6"));
		    break;
		case '7':
		    score_digit_.setTexture(data_->resources.GetTexture("7"));
		    break;
		case '8':
		    score_digit_.setTexture(data_->resources.GetTexture("8"));
		    break;
		case '9':
		    score_digit_.setTexture(data_->resources.GetTexture("9"));
		default:
		    break;
		}
	    score_digit_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
	                             WINDOW_TOP + 2 * NUMBER_SIZE);
	    data_->window.draw(score_digit_);
	}
}

void StateRenderer::DisplayLoss()
{
    // set up loss screen
    game_over_.setTexture(data_->resources.GetTexture("Game Over Sprite"));
    press_f12_to_restart_.setTexture(data_->resources.GetTexture("Press F12 Restart"));
    game_over_.setPosition(SCREEN_WIDTH / 2 - game_over_.getGlobalBounds().width / 2,
                           SCREEN_HEIGHT / 2 - game_over_.getGlobalBounds().height);
    press_f12_to_restart_.setPosition(SCREEN_WIDTH / 2 - press_f12_to_restart_.getGlobalBounds().width / 2,
                                      SCREEN_HEIGHT / 2);
    // draw game loss sprites to screen
    data_->window.draw(game_over_);
    data_->window.draw(press_f12_to_restart_);
}

void StateRenderer::DisplayWin()
{
    // set up game win screen
    game_won_.setTexture(data_->resources.GetTexture("Game Win Sprite"));
    press_f12_to_restart_.setTexture(data_->resources.GetTexture("Press F12 Restart"));
    game_won_.setPosition(SCREEN_WIDTH / 2 - game_won_.getGlobalBounds().width / 2,
                          SCREEN_HEIGHT / 2 - game_won_.getGlobalBounds().height);
    press_f12_to_restart_.setPosition(SCREEN_WIDTH / 2 - press_f12_to_restart_.getGlobalBounds().width / 2,
                                      SCREEN_HEIGHT / 2);
    // draw game win sprites to screen
    data_->window.draw(game_won_);
    data_->window.draw(press_f12_to_restart_);
}

void StateRenderer::DisplayPause()
{
    // set pause sprites
    game_paused_.setTexture(data_->resources.GetTexture("Game Paused Sprite"));
    press_enter_to_resume_.setTexture(data_->resources.GetTexture("Press Space Resume"));
    // set pause sprite positions
    game_paused_.setPosition(SCREEN_WIDTH / 2 - game_paused_.getGlobalBounds().width / 2,
                             SCREEN_HEIGHT / 2 - game_paused_.getGlobalBounds().height);
    press_enter_to_resume_.setPosition(SCREEN_WIDTH / 2 - press_enter_to_resume_.getGlobalBounds().width / 2,
                                       SCREEN_HEIGHT / 2);
    data_->window.draw(resume_background_sprite_);
    data_->window.draw(game_paused_);
    data_->window.draw(press_enter_to_resume_);
}

void StateRenderer::DisplayMenu()
{
    // set up menu screen
    title_.setTexture(data_->resources.GetTexture("Menu Screen Title"));
    title_.setPosition((SCREEN_WIDTH / 2) - (title_.getGlobalBounds().width / 2),
                       SCREEN_HEIGHT / 2 - title_.getGlobalBounds().height);
    subtitle_.setTexture(data_->resources.GetTexture("Subtitle"));
    subtitle_.setPosition((SCREEN_WIDTH / 2) - (subtitle_.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2);
    instructions_.setTexture(data_->resources.GetTexture("Instructions"));
    instructions_.setPosition((SCREEN_WIDTH / 2) - (instructions_.getGlobalBounds().width / 2),
                              SCREEN_HEIGHT / 2 + subtitle_.getGlobalBounds().height);
    // draw menu sprites to screen
    data_->window.draw(title_);
    data_->window.draw(subtitle_);
    data_->window.draw(instructions_);
}

void StateRenderer::DisplaySplashScreen()
{
    background_.setTexture(data_->resources.GetTexture("Splash Screen Background"));
    data_->window.draw(background_);
}

}  // namespace GameEngine