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
		: data_ ( data )
	{
		// initialise Centipede pointers
		centipede_ = std::make_shared<Centipede> ();
		centipede_logic_ = std::make_unique<CentipedeLogic> ( data_, centipede_ );
		centipede_renderer_ = std::make_unique<CentipedeRendering> ( data_, centipede_ );
		// initialise Turret pointers
		turret_ = std::make_shared<Turret> ();
		turret_logic_ = std::make_unique<TurretLogic> ( data_, turret_ );
		turret_renderer_ = std::make_unique<TurretRendering> ( data_, turret_ );
		// initialise mushroom pointers
		field_ = std::make_shared<GameField>();
		mush_logic_ptr = std::make_unique<MushroomLogic> ( field_ );
		mush_renderer_ = std::make_unique<MushroomRendering> ( data_, field_ );
		// spider logic pointers
		spider_logic_ = std::make_unique<SpiderLogic> ( field_ );
		spider_renderer_ = std::make_unique<SpiderRendering> ( data_, field_ );
		scorpion_logic_ = std::make_unique<ScorpionLogic> ( field_ );
		scorpion_renderer_ = std::make_unique<ScorpionRendering> ( data_, field_ );
		// initialise interface/collision pointers
		input_handler_ = std::make_shared<InputHandler> ( data_ );
		collision_handler_ = std::make_shared<CollisionHandler> ( data_, turret_, centipede_, field_ );
	}

	void GamePlay::HandleInput()
	{
		sf::Event event;

		while ( data_->window.pollEvent ( event ) && ( event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased ) )
		{
			// if user presses escape, close the window
			if ( event.key.code == sf::Keyboard::Escape )
			{
				data_->window.close();
			}

			else if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter )
			{
				// if user presses f12, pause game
				data_->statehandler.AddState ( StatePtr ( new PauseGame ( data_ ) ), false );
			}

			else // handle control keys
				input_handler_->SetControls ( event );
		}
	}

	void GamePlay::Update ( float dt )
	{
		// spawn entities
		mush_logic_ptr->Spawn();
		scorpion_logic_->Spawn();
		spider_logic_->Spawn();
		centipede_logic_->Spawn();
		turret_logic_->Spawn(); // spawn bullets

		// move entities
		centipede_logic_->Move ( dt );
		spider_logic_->Move ( dt );
		scorpion_logic_->Move ( dt );
		turret_logic_->Move ( dt );
		turret_logic_->MoveProjectiles ( dt ); // move bullets

		// check collisions
		collision_handler_->CheckCollisions();

		// delete after bullet/segment collisions, ends game if turret isDead
		turret_logic_->CollisionHandle();
		// deletes segments after bullet/segment collisions
		centipede_logic_->CollisionHandle();
		spider_logic_->CollisionHandle();
		mush_logic_ptr->CollisionHandle();
	}

	void GamePlay::Draw()
	{
		// clear screen to update data
		data_->window.clear();
		// draws mushrooms
		mush_renderer_->Draw();
		// draw top section of game screen
		centipede_renderer_->Draw();
		scorpion_renderer_->Draw();
		// draw bottom section of game screen
		turret_renderer_->Draw();
		spider_renderer_->Draw();
		data_->window.display();
	}
} // namespace GameEngine
