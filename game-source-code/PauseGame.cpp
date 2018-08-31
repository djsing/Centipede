#include "PauseGame.h"
#include "GamePlay.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	PauseGame::PauseGame(DataPtr data):
	_data(data)
	{}

	void PauseGame::Initialise()
	{
		_data->resources.LoadTexture("Pause Screen Background", PAUSE_BACKGROUND_FILEPATH);
		_background.setTexture(_data->resources.GetTexture("Pause Screen Background"));
	}

	void PauseGame::HandleInput()
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
				// if player presses space in pause screen, resume game
				_data->statehandler.RemoveState();
			}
		}
	}

	void PauseGame::Update(float dt)
	{
		
	}

	void PauseGame::Draw(float interpolation)
	{
		// clear screen to update data
		_data->window.clear();
		// draw background sprite with background texture loaded
		_data->window.draw(_background);
		// display updated data
		_data->window.display();
	}
}