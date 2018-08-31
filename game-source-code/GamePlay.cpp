#include "GamePlay.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	GamePlay::GamePlay(DataPtr data):
	_data(data)
	{}

	void GamePlay::Initialise()
	{
		// for now keep black screen
		//_data->resources.LoadTexture("Game Screen Background", GAME_BACKGROUND_FILEPATH);
		//_background.setTexture(_data->resources.GetTexture("Game Screen Background"));
	}

	void GamePlay::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))||
				(event.type == sf::Event::Closed))
			{
				_data->window.close();
			}
		}
	}

	void GamePlay::Update(float dt)
	{
		
	}

	void GamePlay::Draw(float interpolation)
	{
		// clear screen to update data
		_data->window.clear();
		// draw background sprite with background texture loaded
		//_data->window.draw(_background);
		// display updated data
		_data->window.display();
	}
}