#include "BombLogic.h"
#include "CentipedeLogic.h"
#include "DEFINITIONS.h"
#include "GamePlay.h"
#include "GameWon.h"
#include "MushroomLogic.h"
#include "PauseGame.h"
#include "ScorpionLogic.h"
#include "SpiderLogic.h"
#include "TurretLogic.h"

namespace GameEngine
{
GamePlay::GamePlay(DataPtr data) : data_(data)
{
    // interface pointer
    input_handler_ = std::make_shared<InputHandler>(data_);
    // Centipede pointers
    centipede_ = std::make_shared<Centipede>();
    centipede_logic_ = std::make_unique<CentipedeLogic>(data_, centipede_);
    // Turret pointers
    turret_ = std::make_shared<Turret>();
    turret_logic_ = std::make_unique<TurretLogic>(data_, turret_);
    // bullet pointers
    bullet_logic_ = std::make_unique<BulletLogic>(turret_->GetBullets());
    // pointer to field container
    field_ = std::make_shared<GameField>();
    // mushroom pointers
    mush_logic_ = std::make_unique<MushroomLogic>(field_);
    // spider pointers
    spider_logic_ = std::make_unique<SpiderLogic>(field_);
    // scorpion pointers
    scorpion_logic_ = std::make_unique<ScorpionLogic>(field_);
    // bombs pointers
    bombs_logic_ = std::make_unique<BombLogic>(field_);
    // collision checking pointer
    collision_handler_ = std::make_shared<CollisionHandler>(data_, turret_, centipede_, field_);
    // Rendering pointer
    renderer_ = std::make_unique<EntityRendering>(data_, turret_, centipede_, field_);
}

void GamePlay::HandleInput()
{
    sf::Event event;

    while(data_->window.pollEvent(event) &&
          (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased))
	{
	    // if user presses escape, close the window
	    if(event.key.code == sf::Keyboard::Escape)
		{
		    data_->window.close();
		}

	    else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
		{
		    // if user presses Enter, pause game
		    data_->statehandler.AddState(StatePtr(new PauseGame(data_)), false);
		}

	    else  // handle control keys
		input_handler_->SetControls(event);
	}
}

void GamePlay::Update(float dt)
{
    SpawnEntities();
    MoveEntities(dt);
    CheckCollisions();
    HandleCollisions();
}

void GamePlay::Draw()
{
    // clear screen to draw sprites
    data_->window.clear();
    // draw all entities
    renderer_->Draw();
    // displays all drawn entities
    data_->window.display();
}

void GamePlay::SpawnEntities()
{
    mush_logic_->Spawn();
    bombs_logic_->Spawn();
    scorpion_logic_->Spawn();
    // spider_logic_->Spawn();
    centipede_logic_->Spawn();
    turret_logic_->Spawn();  // spawn bullets
}

void GamePlay::MoveEntities(float dt)
{
    bombs_logic_->Move(dt);
    centipede_logic_->Move(dt);
    spider_logic_->Move(dt);
    scorpion_logic_->Move(dt);
    turret_logic_->Move(dt);
    bullet_logic_->Move(dt);
}

void GamePlay::CheckCollisions()
{
    collision_handler_->CheckCollisions();
}

void GamePlay::HandleCollisions()
{
    // deletes dead bullets, ends game if 0 lives remaining, resets game if turret isDead
    turret_logic_->CollisionHandle();
    // deletes dead segments, ends game if entire centipede is deleted
    centipede_logic_->CollisionHandle();
    // deletes remaining dead entities, sets non-death related flags triggered by collisions.
    bullet_logic_->CollisionHandle();
    spider_logic_->CollisionHandle();
    mush_logic_->CollisionHandle();
    bombs_logic_->CollisionHandle();
}
}  // namespace GameEngine
