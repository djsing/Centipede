#include <memory>
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
	{
		//load resources
		//_data->resources.LoadTexture("Game Screen Background", GAME_BACKGROUND_FILEPATH);
		//_background.setTexture(_data->resources.GetTexture("Game Screen Background"));
		_data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
		_data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
		_data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
		_data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);

		_centipede = std::make_shared<Centipede>(_data);
		_turret = std::make_shared<Turret>(_data);
		_inputHandler = std::make_shared<InputHandler>(_data);
		_collisionhandler = std::make_shared<CollisionHandler>(_turret, _centipede);
	}

	void GamePlay::Initialise()
	{
		// Spawn initial CentipedeSegment with correct 'head' sprite
		_centipede->SpawnCentipedeSegments(true);
		_numberOfCentipedeSegments++;
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

		if (_data->keyboard.IsShooting() && 
			( _turret->GetTopLeftYPosition() >= (_turret->GetLastBulletYPosition() + BULLET_HEIGHT) ))
		{
			_turret->SpawnBullets();
			_data->keyboard.SetShooting(false);
		}

		// move entities
		_centipede->MoveCentipede(dt);
		_turret->MoveTurret(dt);
		_turret->MoveBullets(dt);
		// check collisions
		_collisionhandler->CheckBulletCollisions();
		_collisionhandler->CheckCentipedeSegmentCollisions();
		// delete destroyed entities
		_turret->DestroyBullets();
		_centipede->DestroyCentipedeSegments();
	}

	void GamePlay::Draw()
	{
		// clear screen to update data
		_data->window.clear();
		// draw background sprite with background texture loaded
		//_data->window.draw(_background);
		// display updated data
		_centipede->DrawCentipedeSegments();
		_turret->DrawBullets();
		_turret->DrawTurret();

		_data->window.display();
	}
}