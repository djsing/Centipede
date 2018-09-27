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
GamePlay::GamePlay(DataPtr data) : data_(data)
{
    // Centipede pointers
    centipede_ = std::make_shared<Centipede>();
    centipede_logic_ = std::make_unique<CentipedeLogic>(data_, centipede_);
    centipede_renderer_ = std::make_unique<CentipedeRendering>(data_, centipede_);
    // Turret pointers
    turret_ = std::make_shared<Turret>();
    turret_logic_ = std::make_unique<TurretLogic>(data_, turret_);
    turret_renderer_ = std::make_unique<TurretRendering>(data_, turret_);
    // bullet pointers
    bullet_logic_ = std::make_unique<BulletLogic>(turret_->GetBullets());
    bullet_renderer_ = std::make_unique<BulletRendering>(data_, turret_->GetBullets());
    // pointer to field container
    field_ = std::make_shared<GameField>();
    // mushroom pointers
    mush_logic_ = std::make_unique<MushroomLogic>(field_);
    mush_renderer_ = std::make_unique<MushroomRendering>(data_, field_);
    // spider pointers
    spider_logic_ = std::make_unique<SpiderLogic>(field_);
    spider_renderer_ = std::make_unique<SpiderRendering>(data_, field_);
    // scorpion pointers
    scorpion_logic_ = std::make_unique<ScorpionLogic>(field_);
    scorpion_renderer_ = std::make_unique<ScorpionRendering>(data_, field_);
    // interface pointer
    input_handler_ = std::make_shared<InputHandler>(data_);
    // collision checking pointer
    collision_handler_ = std::make_shared<CollisionHandler>(data_, turret_, centipede_, field_);
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
    DeleteDeadEntities();
}

void GamePlay::Draw()
{
    // clear screen to draw sprites
    data_->window.clear();
    // draw all entities
    mush_renderer_->Draw();
    centipede_renderer_->Draw();
    scorpion_renderer_->Draw();
    bullet_renderer_->Draw();
    turret_renderer_->Draw();
    spider_renderer_->Draw();
    // displays all drawn entities
    data_->window.display();
}

void GamePlay::SpawnEntities()
{
    mush_logic_->Spawn();
    scorpion_logic_->Spawn();
    spider_logic_->Spawn();
    centipede_logic_->Spawn();
    turret_logic_->Spawn();  // spawn bullets
}

void GamePlay::MoveEntities(float dt)
{
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

void GamePlay::DeleteDeadEntities()
{
    // deletes dead bullets, ends game if 0 lives remaining, resets game if turret isDead
    turret_logic_->CollisionHandle();
    // deletes dead segments, ends game if entire centipede is deleted
    centipede_logic_->CollisionHandle();
    // deletes remaining dead entities
    bullet_logic_->CollisionHandle();
    spider_logic_->CollisionHandle();
    mush_logic_->CollisionHandle();
}
}  // namespace GameEngine
