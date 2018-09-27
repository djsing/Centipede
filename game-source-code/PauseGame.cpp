#include "DEFINITIONS.h"
#include "GamePlay.h"
#include "PauseGame.h"

namespace GameEngine
{
PauseGame::PauseGame(DataPtr data) : data_(data)
{
    // create pause background
    resume_background_.create(data_->window.getSize().x, data_->window.getSize().y);
    resume_background_.update(data_->window);
    background_.setTexture(resume_background_);
    // load pause sprites
    data_->resources.LoadTexture("Game Paused Sprite", PAUSE_FILEPATH);
    data_->resources.LoadTexture("Press Space Resume", PAUSE_SPACE_FILEPATH);
    // set pause sprites
    game_paused_.setTexture(data_->resources.GetTexture("Game Paused Sprite"));
    press_space_to_resume_.setTexture(data_->resources.GetTexture("Press Space Resume"));
    // set pause sprite positions
    game_paused_.setPosition(SCREEN_WIDTH / 2 - game_paused_.getGlobalBounds().width / 2,
                             SCREEN_HEIGHT / 2 - game_paused_.getGlobalBounds().height);
    press_space_to_resume_.setPosition(SCREEN_WIDTH / 2 - press_space_to_resume_.getGlobalBounds().width / 2,
                                       SCREEN_HEIGHT / 2);
}

void PauseGame::HandleInput()
{
    sf::Event event;

    while(data_->window.pollEvent(event) && event.type == sf::Event::KeyPressed)
	{
	    if(event.key.code == sf::Keyboard::Escape)
		{
		    // if player presses escape in pause screen, close window
		    data_->window.close();
		}

	    else if(event.key.code == sf::Keyboard::Enter)
		{
		    // if player presses space in pause screen, resume game
		    data_->statehandler.RemoveState();
		}
	}
}

void PauseGame::Update(float dt)
{
}

void PauseGame::Draw()
{
    data_->window.clear();
    data_->window.draw(background_);
    // draw background sprite with background texture loaded
    data_->window.draw(game_paused_);
    data_->window.draw(press_space_to_resume_);
    // display updated data
    data_->window.display();
}
}  // namespace GameEngine
