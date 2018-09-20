#include <memory>
#include "../game-source-code/Turret.h"
#include "../game-source-code/TurretLogic.h"
#include "../game-source-code/Game.h"
#include "../game-source-code/DEFINITIONS.h"
#include "../game-source-code/KeyboardControlsHandler.h"
#include "../game-source-code/GameField.h"
#include "../game-source-code/Centipede.h"
#include "../game-source-code/CentipedeLogic.h"
#include "../game-source-code/CollisionHandler.h"
#include "../game-source-code/RegionHandler.h"
#include "../game-source-code/GameState.h"

using GameEngine::GameData;
using GameEngine::GameState;
using GameEngine::DataPtr;
using GameEngine::Turret;
using GameEngine::TurretLogic;
using GameEngine::Direction;
using GameEngine::KeyboardControlsHandler;
using GameEngine::GameField;
using GameEngine::Centipede;
using GameEngine::CentipedeLogic;
using GameEngine::CollisionHandler;
using GameEngine::RegionHandler;

#include <doctest.h>

TEST_CASE("Check if turret stays within the confines of the left/right wall, the bottom of the game screen, and the fraction of the screen height that is permitted.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	auto turret = std::make_shared<Turret>(data);
	auto turretLogic = std::make_unique<TurretLogic>(data, turret);
	data->keyboard.SetDirection(Direction::LEFT);

	// move 10x500 units to the left, check if turret is stopped at a x position of 0
	for (unsigned int i = 0; i < 10; i++)
	{
		turretLogic->Move(1);
	}

	CHECK(turret->GetTopLeftXPosition() == 0);

	data->keyboard.SetDirection(Direction::RIGHT);
	// move 10x500 units to the right, check if turret is stopped at a x position of SCREEN_WIDTH
	for (unsigned int i = 0; i < 10; i++)
	{
		turretLogic->Move(1);
	}

	CHECK(turret->GetTopLeftXPosition() == SCREEN_WIDTH - TURRET_SPRITE_SIDE_SIZE);

	data->keyboard.SetDirection(Direction::UP);
	// move 10x500 units UP, check if turret is stopped at a y position of TURRET_SCREEN_FRACTION*SCREEN_HEIGHT
	for (unsigned int i = 0; i < 10; i++)
	{
		turretLogic->Move(1);
	}

	// allow for a 1% error as a result of floating point accuracy
	CHECK(doctest::Approx(turret->GetTopLeftYPosition()).epsilon(0.01) == TURRET_SCREEN_FRACTION*SCREEN_HEIGHT);

	data->keyboard.SetDirection(Direction::DOWN);
	// move 10x500 units DOWN, check if turret is stopped at a y position of SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE
	for (unsigned int i = 0; i < 10; i++)
	{
		turretLogic->Move(1);
	}

	CHECK(turret->GetTopLeftYPosition() == SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
}

TEST_CASE("Check that bullets are automatically deleted when it hits the boundary.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	auto turret = std::make_shared<Turret>(data);
	auto turretLogic = std::make_unique<TurretLogic>(data, turret);

	// emulate the spacebar being pressed
	data->keyboard.SetShooting(true);
	// spawn a bullet
	turretLogic->Spawn();
	// check that bullet has spawned
	CHECK(turret->GetBullets().size() == 1);
	// check that turret is at correct spawn position
	CHECK(turret->GetTopLeftYPosition() == SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
	// check that bullet has spawned at the same y position as turret
	CHECK(turret->GetBullets().at(0).GetTopLeftYPosition() == turret->GetTopLeftYPosition());
	// move 40 units up
	turretLogic->MoveProjectiles(0.02);
	// check that turret hasn't moved
	CHECK(turret->GetTopLeftYPosition() == SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
	// check that bullet has moved
	CHECK(turret->GetBullets().at(0).GetTopLeftYPosition() == turret->GetTopLeftYPosition() - 40);
	// spawn another bullet
	turretLogic->Spawn();

	// move bullets to one bullet height away from the top of the screen
	while (turret->GetBullets().at(0).GetTopLeftYPosition() > BULLET_HEIGHT)
	{
		turretLogic->MoveProjectiles(0.001);
	}

	//check that both bullets are present
	CHECK(turret->GetBullets().size() == 2);
	// move until first bullet reaches the end of the screen
	while (turret->GetBullets().at(0).GetTopLeftYPosition() != SCREEN_TOP)
	{
		turretLogic->MoveProjectiles(0.001);
	}

	// check that first bullet is at the top of the screen
	CHECK(turret->GetBullets().at(0).GetTopLeftYPosition() == SCREEN_TOP);
	// move first bullet off screen
	turretLogic->MoveProjectiles(0.001);
	// check that first bullet is marked as dead, but not the second
	CHECK(turret->GetBullets().at(0).IsDead() == true);
	CHECK(turret->GetBullets().at(1).IsDead() == false);
	// handle collisions
	turretLogic->CollisionHandle();
	// check if there is one bullet after collisions are handled, i.e. the first bullet is deleted, but the second is not
	CHECK(turret->GetBullets().size() == 1);
}

TEST_CASE("Check if turret is set to dead when it collides with a centipede after losing 3 lives.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	auto turret = std::make_shared<Turret>(data);
	auto turretLogic = std::make_unique<TurretLogic>(data, turret);
	auto centipede = std::make_shared<Centipede>(data);
	auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	auto field = std::make_shared<GameField>();
	auto collision = std::make_unique<CollisionHandler>(data, turret, centipede, field);
	// spawn centipede segment directly above turret
	centipedeLogic->Spawn();
	centipede->GetCentipede().at(0).SetTopLeftXPosition(turret->GetTopLeftXPosition());
	CHECK(centipede->GetCentipede().at(0).GetTopLeftXPosition() == turret->GetTopLeftXPosition());

	centipede->GetCentipede().at(0).SetTopLeftYPosition(turret->GetTopLeftYPosition() - TURRET_SPRITE_SIDE_SIZE);
	CHECK(centipede->GetCentipede().at(0).GetTopLeftYPosition() == turret->GetTopLeftYPosition() - TURRET_SPRITE_SIDE_SIZE);

	// move turret into segment
	data->keyboard.SetDirection(Direction::UP);
	while (turret->GetTopLeftYPosition() != (centipede->GetCentipede().at(0).GetTopLeftYPosition()))
	{
		turretLogic->Move(0.001);
	}

	// check that objects are collided
	CHECK(turret->GetTopLeftXPosition() == centipede->GetCentipede().at(0).GetTopLeftXPosition());
	CHECK(turret->GetTopLeftYPosition() == centipede->GetCentipede().at(0).GetTopLeftYPosition());
	// set region of entities
	auto regionHandler = RegionHandler(turret->GetCenterXPosition(), turret->GetCenterYPosition());
	turret->SetRegion(regionHandler.GetRegion());
	turret->SetSubRegion(regionHandler.GetSubRegion());
	regionHandler = RegionHandler(centipede->GetCentipede().at(0).GetCenterXPosition(), centipede->GetCentipede().at(0).GetCenterXPosition());
	centipede->GetCentipede().at(0).SetRegion(regionHandler.GetRegion());
	centipede->GetCentipede().at(0).SetSubRegion(regionHandler.GetSubRegion());
	// before any collisions, check that turret has 3 lives
	CHECK(turret->GetLivesRemaining() == 3);
	// register a collision with a segment
	collision->CheckTurretSegmentCollisions();
	// check that turret resets position to spawn position after losing a life
	CHECK(turret->GetTopLeftYPosition() == SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
	CHECK(turret->GetTopLeftXPosition() == SCREEN_WIDTH/2- TURRET_SPRITE_SIDE_SIZE/2);
	// check that turret loses a life after registering a collision
	CHECK(turret->GetLivesRemaining() == 2);

	// move turret into segment
	while (turret->GetTopLeftYPosition() != (centipede->GetCentipede().at(0).GetTopLeftYPosition()))
	{
		turretLogic->Move(0.001);
	}
	collision->CheckTurretSegmentCollisions();
	CHECK(turret->GetLivesRemaining() == 1);

	// move turret into segment
	while (turret->GetTopLeftYPosition() != (centipede->GetCentipede().at(0).GetTopLeftYPosition()))
	{
		turretLogic->Move(0.001);
	}
	collision->CheckTurretSegmentCollisions();
	CHECK(turret->GetLivesRemaining() == 0);
	// check that the turret dies after losing three lives
	CHECK(turret->IsDead() == true);
}