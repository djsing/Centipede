#include "DEFINITIONS.h"
#include "GameOver.h"
#include "GamePlay.h"

namespace GameEngine
{
GameOver::GameOver(DataPtr data) : data_(data)
{
    renderer_ = std::make_unique<StateRenderer>(data_);
}

void GameOver::HandleInput()
{
    sf::Event event;

    while(data_->window.pollEvent(event) && event.type == sf::Event::KeyPressed)
	{
	    if(event.key.code == sf::Keyboard::Escape)
		{
		    data_->window.close();
		}

	    else if(event.key.code == sf::Keyboard::F12)
		{
		    // if player presses f12 after losing, start a new instance of the game
		    data_->lives.ResetLives();
		    // reset score from previous instances
		    data_->score_manager.ResetScore();
		    data_->statehandler.AddState(StatePtr(new GamePlay(data_)));
		}
	}
}

void GameOver::Update(float dt)
{
    data_->score_manager.UpdateHighScore();
}

void GameOver::Draw()
{
    // clear screen to update data
    data_->window.clear();
    renderer_->DisplayLoss();
    renderer_->DisplayScore(false, false);
    // display updated data
    data_->window.display();
}
}  // namespace GameEngine
