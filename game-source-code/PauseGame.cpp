#include "PauseGame.h"
#include "GamePlay.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	PauseGame::PauseGame(DataPtr data):
	_data(data)
	{
		_data->resources.LoadTexture("Game Paused Sprite", PAUSE_FILEPATH);
		_data->resources.LoadTexture("Press Space Resume", PAUSE_SPACE_FILEPATH);
		_GAMEPAUSED.setTexture(_data->resources.GetTexture("Game Paused Sprite"));
		_PRESSSPACETORESUME.setTexture(_data->resources.GetTexture("Press Space Resume"));
	}

	void PauseGame::Initialise()
	{
		_GAMEPAUSED.setPosition(SCREEN_WIDTH/2 -_GAMEPAUSED.getGlobalBounds().width/2,
			SCREEN_HEIGHT/2 - _GAMEPAUSED.getGlobalBounds().height);

		_PRESSSPACETORESUME.setPosition(SCREEN_WIDTH/2 - _PRESSSPACETORESUME.getGlobalBounds().width/2 
			, SCREEN_HEIGHT/2);
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

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F12))
			{
				// if player presses space in pause screen, resume game
				_data->statehandler.RemoveState();
			}
		}
	}

	void PauseGame::Update(float dt)
	{
		
	}

	void PauseGame::Draw()
	{
		_data->window.clear();
		// draw background sprite with background texture loaded
		_data->window.draw(_GAMEPAUSED);
		_data->window.draw(_PRESSSPACETORESUME);
		// display updated data
		_data->window.display();
	}
}