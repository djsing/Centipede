#include "DEFINITIONS.h"
#include "StateRenderer.h"

namespace GameEngine
{
StateRenderer::StateRenderer(DataPtr data) : data_(data)
{
    // load textures
    data_->resources.LoadTexture("Splash Screen Background", SPLASH_BACKGROUND_FILEPATH_);
    data_->resources.LoadTexture("Game Win Sprite", GAME_WON_);
    data_->resources.LoadTexture("Press F12 Restart", GAME_OVER_RESTART_FILEPATH_);
    data_->resources.LoadTexture("Game Over Sprite", GAME_OVER_FILEPATH_);
    data_->resources.LoadTexture("Menu Screen Title", GAME_TITLE_FILEPATH_);
    data_->resources.LoadTexture("Subtitle", GAME_SUBTITLE_FILEPATH_);
    data_->resources.LoadTexture("Instructions", GAME_INSTRUCTIONS_);
    data_->resources.LoadTexture("Game Paused Sprite", PAUSE_FILEPATH_);
    data_->resources.LoadTexture("Press Enter Resume", PAUSE_ENTER_FILEPATH_);
    data_->resources.LoadTexture("Press Enter Pause", PRESS_ENTER_TO_PAUSE_FILEPATH_);
    data_->resources.LoadTexture("Highscore", HIGHSCORE_FILEPATH_);
    data_->resources.LoadTexture("New Highscore", NEW_HIGHSCORE_FILEPATH_);

    // bind textures to sprites
    press_f12_to_restart_.setTexture(data_->resources.GetTexture("Press F12 Restart"));
    press_enter_to_resume_.setTexture(data_->resources.GetTexture("Press Enter Resume"));
    game_paused_.setTexture(data_->resources.GetTexture("Game Paused Sprite"));
    game_over_.setTexture(data_->resources.GetTexture("Game Over Sprite"));
    game_won_.setTexture(data_->resources.GetTexture("Game Win Sprite"));
    title_.setTexture(data_->resources.GetTexture("Menu Screen Title"));
    subtitle_.setTexture(data_->resources.GetTexture("Subtitle"));
    instructions_.setTexture(data_->resources.GetTexture("Instructions"));
    background_.setTexture(data_->resources.GetTexture("Splash Screen Background"));
    press_enter_to_pause_.setTexture(data_->resources.GetTexture("Press Enter Pause"));
    high_score_.setTexture(data_->resources.GetTexture("Highscore"));
    new_high_score_.setTexture(data_->resources.GetTexture("New Highscore"));

    // create pause background
    resume_background_.create(data_->window.getSize().x, data_->window.getSize().y);
    resume_background_.update(data_->window);
    resume_background_sprite_.setTexture(resume_background_);
    // set up game pause screen
    game_paused_.setPosition(SCREEN_WIDTH / 2 - game_paused_.getGlobalBounds().width / 2,
                             SCREEN_HEIGHT / 2 - game_paused_.getGlobalBounds().height);
    press_enter_to_resume_.setPosition(SCREEN_WIDTH / 2 - press_enter_to_resume_.getGlobalBounds().width / 2,
                                       SCREEN_HEIGHT / 2);
    // set up HIGHSCORE/NEW HIGHSCORE
    high_score_.setPosition(SCREEN_WIDTH / 2 - high_score_.getGlobalBounds().width / 2, WINDOW_TOP);
    new_high_score_.setPosition(SCREEN_WIDTH / 2 - high_score_.getGlobalBounds().width / 2, WINDOW_TOP);
    // set up loss screen
    game_over_.setPosition(SCREEN_WIDTH / 2 - game_over_.getGlobalBounds().width / 2,
                           SCREEN_HEIGHT / 2 - game_over_.getGlobalBounds().height);
    // set up game win screen
    game_won_.setPosition(SCREEN_WIDTH / 2 - game_won_.getGlobalBounds().width / 2,
                          SCREEN_HEIGHT / 2 - game_won_.getGlobalBounds().height);
    // set up menu screen
    title_.setPosition((SCREEN_WIDTH / 2) - (title_.getGlobalBounds().width / 2),
                       SCREEN_HEIGHT / 2 - title_.getGlobalBounds().height);
    subtitle_.setPosition((SCREEN_WIDTH / 2) - (subtitle_.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2);
    instructions_.setPosition((SCREEN_WIDTH / 2) - (instructions_.getGlobalBounds().width / 2),
                              SCREEN_HEIGHT / 2 + subtitle_.getGlobalBounds().height);
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
    press_f12_to_restart_.setPosition(SCREEN_WIDTH / 2 - press_f12_to_restart_.getGlobalBounds().width / 2,
                                      SCREEN_HEIGHT / 2);
    // draw game loss sprites to screen
    if(data_->score_manager.HighScoreSurpassed())
	{
	    data_->window.draw(new_high_score_);
	}
    else
	{
	    data_->window.draw(high_score_);
	}

    data_->window.draw(game_over_);
    data_->window.draw(press_f12_to_restart_);
}

void StateRenderer::DisplayWin()
{
    press_f12_to_restart_.setPosition(SCREEN_WIDTH / 2 - press_f12_to_restart_.getGlobalBounds().width / 2,
                                      SCREEN_HEIGHT / 2);
    // draw game win sprites to screen
    if(data_->score_manager.HighScoreSurpassed())
	{
	    data_->window.draw(new_high_score_);
	}
    else
	{
	    data_->window.draw(high_score_);
	}

    data_->window.draw(game_won_);
    data_->window.draw(press_f12_to_restart_);
}

void StateRenderer::DisplayPause()
{
    data_->window.draw(resume_background_sprite_);
    data_->window.draw(game_paused_);
    data_->window.draw(press_enter_to_resume_);
}

void StateRenderer::DisplayMenu()
{
    // draw menu sprites to screen
    data_->window.draw(title_);
    data_->window.draw(subtitle_);
    data_->window.draw(instructions_);
}

void StateRenderer::DisplaySplashScreen()
{
    data_->window.draw(background_);
}

}  // namespace GameEngine