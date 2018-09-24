#include "CentipedeLogic.h"
#include "CentipedeRendering.h"
#include "DEFINITIONS.h"
#include "GamePlay.h"
#include "GameWon.h"
#include "MushroomLogic.h"
#include "MushroomRendering.h"
#include "PauseGame.h"
#include "ScorpionLogic.h"
#include "ScorpionRendering.h"
#include "SpiderLogic.h"
#include "SpiderRendering.h"
#include "TurretLogic.h"
#include "TurretRendering.h"

namespace GameEngine
{
	GamePlay::GamePlay ( DataPtr data )
		: _data ( data )
	{
		// initialise Centipede pointers
		_centipede = std::make_shared<Centipede> ( _data );
		_centipedeLogic = std::make_unique<CentipedeLogic> ( _data, _centipede );
		_centipedeRenderer = std::make_unique<CentipedeRendering> ( _data, _centipede );
		// initialise Turret pointers
		_turret = std::make_shared<Turret> ( _data );
		_turretLogic = std::make_unique<TurretLogic> ( _data, _turret );
		_turretRenderer = std::make_unique<TurretRendering> ( _data, _turret );
		// initialise mushroom pointers
		_field = std::make_shared<GameField>();
		_mushLogicPtr = std::make_unique<MushroomLogic> ( _field, _data );
		_mushRenderer = std::make_unique<MushroomRendering> ( _data, _field );
		// spider logic pointers
		_spiderLogic = std::make_unique<SpiderLogic> ( _field, _data );
		_spiderRenderer = std::make_unique<SpiderRendering> ( _data, _field );
		_scorpionLogic = std::make_unique<ScorpionLogic> ( _field, _data );
		_scorpionRenderer = std::make_unique<ScorpionRendering> ( _data, _field );
		// initialise interface/collision pointers
		_inputHandler = std::make_shared<InputHandler> ( _data );
		_collisionhandler = std::make_shared<CollisionHandler> ( _data, _turret, _centipede, _field );
	}

	void GamePlay::HandleInput()
	{
		sf::Event event;

		while ( _data->window.pollEvent ( event ) && ( event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased ) )
		{
			// if user presses escape, close the window
			if ( event.key.code == sf::Keyboard::Escape )
			{
				_data->window.close();
			}

			else if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter )
			{
				// if user presses f12, pause game
				_data->statehandler.AddState ( StatePtr ( new PauseGame ( _data ) ), false );
			}

			else // handle control keys
				_inputHandler->SetControls ( event );
		}
	}

	void GamePlay::Update ( float dt )
	{
		// spawn entities
		_mushLogicPtr->Spawn();
		_scorpionLogic->Spawn();
		_spiderLogic->Spawn();
		_centipedeLogic->Spawn();
		_turretLogic->Spawn(); // spawn bullets

		// move entities
		_centipedeLogic->Move ( dt );
		_spiderLogic->Move ( dt );
		_scorpionLogic->Move ( dt );
		_turretLogic->Move ( dt );
		_turretLogic->MoveProjectiles ( dt ); // move bullets

		// check collisions
		_collisionhandler->CheckCollisions();

		// delete after bullet/segment collisions, ends game if turret isDead
		_turretLogic->CollisionHandle();
		// deletes segments after bullet/segment collisions
		_centipedeLogic->CollisionHandle();
		_spiderLogic->CollisionHandle();
		_mushLogicPtr->CollisionHandle();
	}

	void GamePlay::Draw()
	{
		// clear screen to update data
		_data->window.clear();

		// draw background sprite with background texture loaded
		//_data->window.draw(_background);

		// draws mushrooms
		_mushRenderer->Draw();
		// draw top section of game screen
		_centipedeRenderer->Draw();
		_scorpionRenderer->Draw();
		// draw bottom section of game screen
		_turretRenderer->Draw();
		_spiderRenderer->Draw();
		_data->window.display();
	}
} // namespace GameEngine
