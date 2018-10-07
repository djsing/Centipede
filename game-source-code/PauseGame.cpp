#include "DEFINITIONS.h"
#include "GamePlay.h"
#include "PauseGame.h"

namespace GameEngine
{
PauseGame::PauseGame(DataPtr data) : data_(data)
{
    renderer_ = std::make_unique<StateRenderer>(data_);
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
    renderer_->DisplayPause();
    // display updated data
    data_->window.display();
}
}  // namespace GameEngine
