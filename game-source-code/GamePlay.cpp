#include "GamePlay.h"
#include "PauseGame.h"
#include "DEFINITIONS.h"
#include "CentipedeSegment.h"
#include "Centipede.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	GamePlay::GamePlay(DataPtr data):
	_data(data),
	_numberOfCentipedeSegments(0)
	{}

	GamePlay::~GamePlay()
	{
		delete _centipede;
	}

	void GamePlay::Initialise()
	{
		// for now keep black screen
		//_data->resources.LoadTexture("Game Screen Background", GAME_BACKGROUND_FILEPATH);

		//_background.setTexture(_data->resources.GetTexture("Game Screen Background"));
		_data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
		_centipede = new Centipede(_data);
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
			// if user presses f12, pasue game
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F12))
			{
				_data->statehandler.AddState(StatePtr(new PauseGame(_data)), false);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				_centipede->SpawnCentipedeSegments();
			}
		}
	}

	void GamePlay::Update(float dt)
	{
		_centipede->MoveCentipede(dt);
	}

	void GamePlay::Draw()
	{
		// clear screen to update data
		_data->window.clear();
		// draw background sprite with background texture loaded
		//_data->window.draw(_background);
		// display updated data
		_centipede->DrawCentipedeSegments();
		_data->window.display();
	}
}