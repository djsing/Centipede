#include "GameWon.h"
#include "GamePlay.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	GameWon::GameWon(DataPtr data):
	_data(data)
	{}

	void GameWon::Initialise()
	{
		_data->resources.LoadTexture("Game Win Screen Background", GAME_WIN_BACKGROUND_FILEPATH);
		_background.setTexture(_data->resources.GetTexture("Game Win Screen Background"));
	}

	void GameWon::HandleInput()
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
				// if player presses space after winning, start a new instance of the game 
				_data->statehandler.AddState(StatePtr(new GamePlay(_data)));
			}
		}
	}

	void GameWon::Update(float dt)
	{
		
	}

	void GameWon::Draw()
	{
		// clear screen to update data
		_data->window.clear();
		// draw background sprite with background texture loaded
		_data->window.draw(_background);
		// display updated data
		_data->window.display();
	}
}