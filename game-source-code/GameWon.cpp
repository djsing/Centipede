#include "DEFINITIONS.h"
#include "GamePlay.h"
#include "GameWon.h"

namespace GameEngine
{
GameWon::GameWon(DataPtr data) : data_(data)
{
    renderer_ = std::make_shared<StateRenderer>(data_);
}

void GameWon::HandleInput()
{
    sf::Event event;

    while(data_->window.pollEvent(event) && event.type == sf::Event::KeyPressed)
	{
	    if(event.key.code == sf::Keyboard::Escape)
		{
		    data_->window.close();
		}

	    if(event.key.code == sf::Keyboard::F12)
		{
		    // if player presses space after winning, start a new instance of the game
		    data_->lives.ResetLives();
		    // reset score from previous instances
		    data_->score_manager.ResetScore();
		    data_->statehandler.AddState(StatePtr(new GamePlay(data_)));
		}
	}
}

void GameWon::Update(float dt)
{
    data_->score_manager.UpdateHighScore();
}

void GameWon::Draw()
{
    // clear screen to update data
    data_->window.clear();
    renderer_->DisplayWin();
    renderer_->DisplayHighScore();
    // display updated data
    data_->window.display();
}
}  // namespace GameEngine
