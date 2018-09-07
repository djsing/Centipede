#include "GameOver.h"
#include "GamePlay.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	GameOver::GameOver(DataPtr data):
	_data(data)
	{}

	void GameOver::Initialise()
	{
		_data->resources.LoadTexture("Game Over Screen Background", GAME_OVER_BACKGROUND_FILEPATH);
		_background.setTexture(_data->resources.GetTexture("Game Over Screen Background"));
	}

	void GameOver::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))||
				(event.type == sf::Event::Closed))
			{
				_data->window.close();
			}

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
				// if player presses space after losing, start a new instance of the game 
				_data->statehandler.AddState(StatePtr(new GamePlay(_data)));
			}
		}
	}

	void GameOver::Update(float dt)
	{
		
	}

	void GameOver::Draw()
	{
		// clear screen to update data
		_data->window.clear();
		// draw background sprite with background texture loaded
		_data->window.draw(_background);
		// display updated data
		_data->window.display();
	}
}