#include <string>
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
    data_->resources.LoadTexture("score", SCORE_FILEPATH_);
    // load score related textures
    data_->resources.LoadTexture("0", NUMBER_0);
    data_->resources.LoadTexture("1", NUMBER_1);
    data_->resources.LoadTexture("2", NUMBER_2);
    data_->resources.LoadTexture("3", NUMBER_3);
    data_->resources.LoadTexture("4", NUMBER_4);
    data_->resources.LoadTexture("5", NUMBER_5);
    data_->resources.LoadTexture("6", NUMBER_6);
    data_->resources.LoadTexture("7", NUMBER_7);
    data_->resources.LoadTexture("8", NUMBER_8);
    data_->resources.LoadTexture("9", NUMBER_9);

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
    score_.setTexture(data_->resources.GetTexture("score"));
    // bind texture related to scores
    zero_.setTexture(data_->resources.GetTexture("0"));
    one_.setTexture(data_->resources.GetTexture("1"));
    two_.setTexture(data_->resources.GetTexture("2"));
    three_.setTexture(data_->resources.GetTexture("3"));
    four_.setTexture(data_->resources.GetTexture("4"));
    five_.setTexture(data_->resources.GetTexture("5"));
    six_.setTexture(data_->resources.GetTexture("6"));
    seven_.setTexture(data_->resources.GetTexture("7"));
    eight_.setTexture(data_->resources.GetTexture("8"));
    nine_.setTexture(data_->resources.GetTexture("9"));

    // create pause background
    resume_background_.create(data_->window.getSize().x, data_->window.getSize().y);
    resume_background_.update(data_->window);
    resume_background_sprite_.setTexture(resume_background_);
    // set up game pause screen
    game_paused_.setPosition(SCREEN_WIDTH / 2 - game_paused_.getGlobalBounds().width / 2,
                             SCREEN_HEIGHT / 2 - game_paused_.getGlobalBounds().height);
    press_enter_to_resume_.setPosition(SCREEN_WIDTH / 2 - press_enter_to_resume_.getGlobalBounds().width / 2,
                                       SCREEN_HEIGHT / 2);
    // set up SCORE/HIGHSCORE/NEW HIGHSCORE
    score_.setPosition(SCREEN_WIDTH / 2 - score_.getGlobalBounds().width / 2, WINDOW_TOP);
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
    press_enter_to_pause_.setPosition((SCREEN_WIDTH / 2) - (press_enter_to_pause_.getGlobalBounds().width / 2),
                                      SCREEN_HEIGHT - press_enter_to_pause_.getGlobalBounds().height);
}

void StateRenderer::DisplayScore(bool highscore, bool play)
{
    auto score = std::to_string(data_->score_manager.GetScore());
    if(highscore)
	{
	    score = data_->score_manager.GetHighScore();
	}

    for(unsigned int i = 0; i < score.size(); i++)
	{
	    if(play)
		{
		    switch(score.at(i))
			{
			case '0':
			    zero_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
			    data_->window.draw(zero_);
			    break;
			case '1':
			    one_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
			    data_->window.draw(one_);
			    break;
			case '2':
			    two_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
			    data_->window.draw(two_);
			    break;
			case '3':
			    three_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
			    data_->window.draw(three_);
			    break;
			case '4':
			    four_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
			    data_->window.draw(four_);
			    break;
			case '5':
			    five_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
			    data_->window.draw(five_);
			    break;
			case '6':
			    six_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
			    data_->window.draw(six_);
			    break;
			case '7':
			    seven_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
			    data_->window.draw(seven_);
			    break;
			case '8':
			    eight_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
			    data_->window.draw(eight_);
			    break;
			case '9':
			    nine_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
			    data_->window.draw(nine_);
			default:
			    break;
			}
		}
	    else
		{
		    switch(score.at(i))
			{
			case '0':
			    zero_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
			                      WINDOW_TOP + 2 * NUMBER_SIZE);
			    data_->window.draw(zero_);
			    break;
			case '1':
			    one_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
			                     WINDOW_TOP + 2 * NUMBER_SIZE);
			    data_->window.draw(one_);
			    break;
			case '2':
			    two_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
			                     WINDOW_TOP + 2 * NUMBER_SIZE);
			    data_->window.draw(two_);
			    break;
			case '3':
			    three_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
			                       WINDOW_TOP + 2 * NUMBER_SIZE);
			    data_->window.draw(three_);
			    break;
			case '4':
			    four_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
			                      WINDOW_TOP + 2 * NUMBER_SIZE);
			    data_->window.draw(four_);
			    break;
			case '5':
			    five_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
			                      WINDOW_TOP + 2 * NUMBER_SIZE);
			    data_->window.draw(five_);
			    break;
			case '6':
			    six_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
			                     WINDOW_TOP + 2 * NUMBER_SIZE);
			    data_->window.draw(six_);
			    break;
			case '7':
			    seven_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
			                       WINDOW_TOP + 2 * NUMBER_SIZE);
			    data_->window.draw(seven_);
			    break;
			case '8':
			    eight_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
			                       WINDOW_TOP + 2 * NUMBER_SIZE);
			    data_->window.draw(eight_);
			    break;
			case '9':
			    nine_.setPosition(SCREEN_WIDTH / 2 - NUMBER_SIZE * score.size() / 2 + i * NUMBER_SIZE,
			                      WINDOW_TOP + 2 * NUMBER_SIZE);
			    data_->window.draw(nine_);
			default:
			    break;
			}
		}
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
	    data_->window.draw(score_);
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
	    data_->window.draw(score_);
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
    data_->window.draw(high_score_);
    DisplayScore(true, false);
    data_->window.draw(title_);
    data_->window.draw(subtitle_);
    data_->window.draw(instructions_);
    data_->window.draw(press_enter_to_pause_);
}

void StateRenderer::DisplaySplashScreen()
{
    data_->window.draw(background_);
}

}  // namespace GameEngine