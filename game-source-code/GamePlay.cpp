#include "GamePlay.h"
#include "PauseGame.h"
#include "DEFINITIONS.h"
#include "CentipedeSegment.h"
#include "Centipede.h"
#include "Turret.h"
#include "Direction.h"
#include "InputHandler.h"
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
		delete _turret;
	}

	void GamePlay::Initialise()
	{
		// for now keep black screen
		//_data->resources.LoadTexture("Game Screen Background", GAME_BACKGROUND_FILEPATH);

		//_background.setTexture(_data->resources.GetTexture("Game Screen Background"));
		_data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
		_data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
		_data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
		_centipede = new Centipede(_data);
		_centipede->SpawnCentipedeSegments(true);
		_numberOfCentipedeSegments++;

		_data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
		_turret = new Turret(_data);

		_inputHandler = new InputHandler(_data);
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
			// if user presses f12, pause game
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F12))
			{
				_data->statehandler.AddState(StatePtr(new PauseGame(_data)), false);
			}
			// handle control keys
			_inputHandler->SetControls(event);
		}
	}

	void GamePlay::Update(float dt)
	{
		// inital spawning of 12 centipede segments when the game begins
		if ((_centipede->GetLastSpriteXPosition() >= CENTIPEDE_SPRITE_SIDE_SIZE) 
				&& (_numberOfCentipedeSegments < 12 ))
		{
			_centipede->SpawnCentipedeSegments();
			_numberOfCentipedeSegments++;
		}
		_centipede->MoveCentipede(dt);
		_turret->MoveTurret(dt);
	}

	void GamePlay::Draw()
	{
		// clear screen to update data
		_data->window.clear();
		// draw background sprite with background texture loaded
		//_data->window.draw(_background);
		// display updated data
		_centipede->DrawCentipedeSegments();
		_turret->DrawTurret();
		_data->window.display();
	}
}