#include "GamePlay.h"
#include "PauseGame.h"
#include "DEFINITIONS.h"

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

		// initialise Centipede pointers
		_centipede = std::make_shared<Centipede>(_data);
		_centipedeLogic = std::make_unique<CentipedeLogic>(_data, _centipede);
		_centipedeRenderer = std::make_unique<CentipedeRendering>(_data, _centipede);
		// initialise Turret pointers
		_turret = std::make_shared<Turret>(_data);
		_turretLogic = std::make_unique<TurretLogic>(_data, _turret);
		_turretRenderer = std::make_unique<TurretRendering>(_data, _turret);
		// initialise interface/collision pointers
		_inputHandler = std::make_shared<InputHandler>(_data);
		_collisionhandler = std::make_shared<CollisionHandler>(_turret, _centipede);
	}

	void GamePlay::Initialise()
	{
		// Spawn initial CentipedeSegment with correct 'head' sprite
		_centipedeLogic->Spawn();
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
		// inital spawning of INITIAL_CENTIPEDE_NUMBER centipede segments when the game begins
		if ((_centipede->GetLastSpriteXPosition() >= CENTIPEDE_SPRITE_SIDE_SIZE) 
				&& (_numberOfCentipedeSegments < INITIAL_CENTIPEDE_NUMBER ))
		{
			//_centipede->SpawnCentipedeSegments();
			_centipedeLogic->Spawn();
			_numberOfCentipedeSegments++;
		}

		if (_data->keyboard.IsShooting() && 
			( _turret->GetTopLeftYPosition() >= (_turret->GetLastBulletYPosition() + BULLET_HEIGHT) ))
		{
			_turretLogic->Spawn();
			_data->keyboard.SetShooting(false);
		}

		// move entities
		_centipedeLogic->Move(dt);
		_turretLogic->Move(dt);
		_turretLogic->MoveProjectiles(dt);	// move bullets

		// check collisions
		_collisionhandler->CheckBulletCollisions();
		_collisionhandler->CheckCentipedeSegmentCollisions();

		// delete destroyed entities
		_turretLogic->CollisionHandle();
		_centipedeLogic->CollisionHandle();
		//--------------------STILL TO BE REPLACED WITH LAYERING----------------
		_centipede->DestroyCentipedeSegments();
	}

	void GamePlay::Draw()
	{
		// clear screen to update data
		_data->window.clear();

		// draw background sprite with background texture loaded
		//_data->window.draw(_background);

		// draws centipede segments
		_centipedeRenderer->Draw();
		// Draws turret as well as bullets
		_turretRenderer->Draw();

		_data->window.display();
	}
}