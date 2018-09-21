#include "../game-source-code/CollisionHandler.h"
#include "../game-source-code/DEFINITIONS.h"
#include "../game-source-code/TurretLogic.h"
#include "../game-source-code/CentipedeLogic.h"
#include "../game-source-code/RegionHandler.h"
#include "../game-source-code/MushroomLogic.h"
#include "../game-source-code/SpiderLogic.h"
#include "../game-source-code/ScorpionLogic.h"
#include <memory>

using GameEngine::DataPtr;
using GameEngine::GameData;
using GameEngine::LogicPtr;
using GameEngine::CentPtr;
using GameEngine::Centipede;
using GameEngine::CentipedeLogic;
using GameEngine::Turret;
using GameEngine::TurretPtr;
using GameEngine::TurretLogic;
using GameEngine::GameField;
using GameEngine::FieldPtr;
using GameEngine::CollisionHandler;
using GameEngine::CollisionHandlerPtr;
using GameEngine::RegionHandler;
using GameEngine::MushroomLogic;
using GameEngine::Mushroom;
using GameEngine::Direction;
using GameEngine::Trajectory;
using GameEngine::SpiderLogic;
using GameEngine::ScorpionLogic;

#include <doctest.h>

TEST_CASE("Check that bullet-segment collisions are handled correctly.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	TurretPtr turret = std::make_shared<Turret>(data);
	LogicPtr turretLogic = std::make_unique<TurretLogic>(data, turret);
	FieldPtr field = std::make_shared<GameField>();
	CollisionHandlerPtr collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

	CHECK(turret->GetBullets().empty());
	CHECK(centipede->GetCentipede().empty());

	// spawn 
	centipedeLogic->Spawn();
	turretLogic->Spawn();

	CHECK(turret->GetBullets().size() == 1);
	CHECK(centipede->GetCentipede().size() == 1);

	CHECK_FALSE(turret->GetBullets().at(0).IsDead());
	CHECK_FALSE(centipede->GetCentipede().at(0).IsDead());

	while (turret->GetBullets().at(0).GetTopLeftYPosition() != SCREEN_TOP)
	{
		turretLogic->MoveProjectiles(0.001);
	}

	CHECK(centipede->GetCentipede().at(0).GetTopLeftYPosition() == turret->GetBullets().at(0).GetTopLeftYPosition());

	// move the centipede into the bullet space, and check for collisions
	while (centipede->GetCentipede().at(0).GetTopLeftXPosition() < turret->GetBullets().at(0).GetTopLeftXPosition())
	{
		centipedeLogic->Move(0.001);
		// detect collisions
		collisionhandler->CheckBulletSegmentCollisions();
	}

	CHECK(turret->GetBullets().at(0).IsDead());
	CHECK(centipede->GetCentipede().at(0).IsDead());

	centipedeLogic->CollisionHandle();
	turretLogic->CollisionHandle();

	CHECK(turret->GetBullets().empty());
	CHECK(centipede->GetCentipede().empty());
}

TEST_CASE("Check that segment-mushroom collisions are handled correctly when trajectory is downward.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	TurretPtr turret = std::make_shared<Turret>(data);
	LogicPtr turretLogic = std::make_unique<TurretLogic>(data, turret);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr mushLogic = std::make_unique<MushroomLogic>(field, data);
	CollisionHandlerPtr collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

	CHECK(field->GetMushrooms().empty());
	CHECK(centipede->GetCentipede().empty());

	centipedeLogic->Spawn();
	CHECK(centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::DOWNWARD);

	// spawn a mushroom 2 centipede segment distances away
	auto mushroom = Mushroom(data, 2*CENTIPEDE_SPRITE_SIDE_SIZE, 0);
	field->GetMushrooms().push_back(mushroom);

	CHECK(field->GetMushrooms().size() == 1);
	CHECK(centipede->GetCentipede().size() == 1);

	while (centipede->GetCentipede().at(0).GetDirection() == Direction::RIGHT)
	{
		centipedeLogic->Move(0.001);
		// detect collisions
		collisionhandler->CheckSegmentMushroomCollisions();
	}

	// check that when the collision is detected, the direction changes to DOWN
	CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::DOWN);
}

TEST_CASE("Check that segment-mushroom collisions are handled correctly when trajectory is upward.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	TurretPtr turret = std::make_shared<Turret>(data);
	LogicPtr turretLogic = std::make_unique<TurretLogic>(data, turret);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr mushLogic = std::make_unique<MushroomLogic>(field, data);
	CollisionHandlerPtr collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

	CHECK(field->GetMushrooms().empty());
	CHECK(centipede->GetCentipede().empty());

	centipedeLogic->Spawn();

	// spawn a mushroom 2 centipede segment distances away
	auto mushroom = Mushroom(data, 2*CENTIPEDE_SPRITE_SIDE_SIZE, 2*CENTIPEDE_SPRITE_SIDE_SIZE);
	field->GetMushrooms().push_back(mushroom);

	CHECK(field->GetMushrooms().size() == 1);
	CHECK(centipede->GetCentipede().size() == 1);

	// move segment until the segment reaches the bottom of the screen
	while (centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::DOWNWARD)
	{
		centipedeLogic->Move(0.001);
	}

	CHECK(centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::UPWARD);

	while (centipede->GetCentipede().at(0).GetDirection() == Direction::RIGHT ||
		(centipede->GetCentipede().at(0).GetDirection() == Direction::LEFT))
	{
		centipedeLogic->Move(0.001);
		// detect collisions
		collisionhandler->CheckSegmentMushroomCollisions();
	}

	// check that when the collision is detected, the direction changes to UP
	CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::UP);
}

TEST_CASE("Check that segment/poisoned-mushroom collisions are handled correctly.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	TurretPtr turret = std::make_shared<Turret>(data);
	LogicPtr turretLogic = std::make_unique<TurretLogic>(data, turret);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr mushLogic = std::make_unique<MushroomLogic>(field, data);
	CollisionHandlerPtr collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

	CHECK(field->GetMushrooms().empty());
	CHECK(centipede->GetCentipede().empty());

	centipedeLogic->Spawn();
	CHECK(centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::DOWNWARD);

	// spawn a mushroom 2 centipede segment distances away
	auto mushroom = Mushroom(data, 2*CENTIPEDE_SPRITE_SIDE_SIZE, 0);
	mushroom.SetPoisoned(true);
	field->GetMushrooms().push_back(mushroom);

	CHECK(field->GetMushrooms().size() == 1);
	CHECK(centipede->GetCentipede().size() == 1);

	// when mushroom is poisoned, no collision has been detected
	while (field->GetMushrooms().at(0).IsPoisoned())
	{
		centipedeLogic->Move(0.001);
		// detect collisions
		collisionhandler->CheckSegmentMushroomCollisions();
	}

	// check that when the collision is detected, the centipede is poisoned
	CHECK(centipede->GetCentipede().at(0).IsPoisoned());
	CHECK_FALSE(field->GetMushrooms().at(0).IsPoisoned());
}

TEST_CASE("Check if turret loses a life when it collides with a segment.")
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

TEST_CASE("Check if turret loses a life when it collides with a spider.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	auto turret = std::make_shared<Turret>(data);
	auto turretLogic = std::make_unique<TurretLogic>(data, turret);
	auto centipede = std::make_shared<Centipede>(data);
	auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	auto field = std::make_shared<GameField>();
	auto spiderLogic = std::make_unique<SpiderLogic>(field, data);
	auto collision = std::make_unique<CollisionHandler>(data, turret, centipede, field);
	// spawn spider directly above turret
	spiderLogic->Spawn();
	CHECK(field->GetSpiders().size() == 1);

	// move turret into spider
	data->keyboard.SetDirection(Direction::UP);
	while (turret->GetTopLeftYPosition() != (field->GetSpiders().at(0).GetTopLeftYPosition()))
	{
		turretLogic->Move(0.001);
	}

	// check that objects are collided
	CHECK(turret->GetTopLeftXPosition() == field->GetSpiders().at(0).GetTopLeftXPosition());
	CHECK(turret->GetTopLeftYPosition() == field->GetSpiders().at(0).GetTopLeftYPosition());
	// set region of entities
	auto regionHandler = RegionHandler(turret->GetCenterXPosition(), turret->GetCenterYPosition());
	turret->SetRegion(regionHandler.GetRegion());
	turret->SetSubRegion(regionHandler.GetSubRegion());
	regionHandler = RegionHandler(field->GetSpiders().at(0).GetCenterXPosition(), field->GetSpiders().at(0).GetCenterXPosition());
	field->GetSpiders().at(0).SetRegion(regionHandler.GetRegion());
	field->GetSpiders().at(0).SetSubRegion(regionHandler.GetSubRegion());
	// before any collisions, check that turret has 3 lives
	CHECK(turret->GetLivesRemaining() == 3);
	// register a collision with a segment
	collision->CheckTurretSpiderCollisions();
	// check that turret resets position to spawn position after losing a life
	CHECK(turret->GetTopLeftXPosition() == SCREEN_WIDTH/2- TURRET_SPRITE_SIDE_SIZE/2);
	CHECK(turret->GetTopLeftYPosition() == SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
	// check that turret loses a life after registering a collision
	CHECK(turret->GetLivesRemaining() == 2);
}

TEST_CASE("Check if turret is set to dead when it collides with a centipede after losing 3 lives.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	auto turret = std::make_shared<Turret>(data);
	auto turretLogic = std::make_unique<TurretLogic>(data, turret);
	auto centipede = std::make_shared<Centipede>(data);
	auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	auto field = std::make_shared<GameField>();
	auto spiderLogic = std::make_unique<SpiderLogic>(field, data);
	auto collision = std::make_unique<CollisionHandler>(data, turret, centipede, field);
	// spawn spider directly above turret
	spiderLogic->Spawn();
	CHECK(field->GetSpiders().size() == 1);

	// move turret into spider
	data->keyboard.SetDirection(Direction::UP);
	while (turret->GetTopLeftYPosition() != (field->GetSpiders().at(0).GetTopLeftYPosition()))
	{
		turretLogic->Move(0.001);
	}

	// check that objects are collided
	CHECK(turret->GetTopLeftXPosition() == field->GetSpiders().at(0).GetTopLeftXPosition());
	CHECK(turret->GetTopLeftYPosition() == field->GetSpiders().at(0).GetTopLeftYPosition());
	// set region of entities
	auto regionHandler = RegionHandler(turret->GetCenterXPosition(), turret->GetCenterYPosition());
	turret->SetRegion(regionHandler.GetRegion());
	turret->SetSubRegion(regionHandler.GetSubRegion());
	regionHandler = RegionHandler(field->GetSpiders().at(0).GetCenterXPosition(), field->GetSpiders().at(0).GetCenterXPosition());
	field->GetSpiders().at(0).SetRegion(regionHandler.GetRegion());
	field->GetSpiders().at(0).SetSubRegion(regionHandler.GetSubRegion());
	// before any collisions, check that turret has 3 lives
	CHECK(turret->GetLivesRemaining() == 3);
	// register a collision with a segment
	collision->CheckTurretSpiderCollisions();
	// check that turret resets position to spawn position after losing a life
	CHECK(turret->GetTopLeftXPosition() == SCREEN_WIDTH/2- TURRET_SPRITE_SIDE_SIZE/2);
	CHECK(turret->GetTopLeftYPosition() == SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
	// check that turret loses a life after registering a collision
	CHECK(turret->GetLivesRemaining() == 2);

	// move turret into spider
	while (turret->GetTopLeftYPosition() != (field->GetSpiders().at(0).GetTopLeftYPosition()))
	{
		turretLogic->Move(0.001);
	}
	collision->CheckTurretSpiderCollisions();
	CHECK(turret->GetLivesRemaining() == 1);

	// move turret into segment
	while (turret->GetTopLeftYPosition() != (field->GetSpiders().at(0).GetTopLeftYPosition()))
	{
		turretLogic->Move(0.001);
	}
	collision->CheckTurretSpiderCollisions();
	CHECK(turret->GetLivesRemaining() == 0);
	// check that the turret dies after losing three lives
	CHECK(turret->IsDead() == true);
}

TEST_CASE("Check that scorpion-mushroom collisions are handled correctly.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
	data->resources.LoadTexture("Scorpion sprite", SCORPION_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	TurretPtr turret = std::make_shared<Turret>(data);
	LogicPtr turretLogic = std::make_unique<TurretLogic>(data, turret);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr mushLogic = std::make_unique<MushroomLogic>(field, data);
	auto scorpionLogic = std::make_unique<ScorpionLogic>(field, data);
	CollisionHandlerPtr collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

	CHECK(field->GetMushrooms().empty());
	CHECK(field->GetScorpions().empty());
	scorpionLogic->Spawn();
	CHECK(field->GetScorpions().size() == 1);

	// move scorpion
	scorpionLogic->Move(0.001);
	// spawn a mushroom at position of scorpion
	auto mushroom = Mushroom(data, field->GetScorpions().at(0).GetTopLeftXPosition(),
		field->GetScorpions().at(0).GetTopLeftYPosition());
	field->GetMushrooms().push_back(mushroom);
	CHECK(field->GetMushrooms().size() == 1);
	collisionhandler->CheckMushroomScorpionCollisions();

	CHECK(field->GetMushrooms().at(0).IsPoisoned());
}

TEST_CASE("Check that spider-mushroom collisions are handled correctly.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
	data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	TurretPtr turret = std::make_shared<Turret>(data);
	LogicPtr turretLogic = std::make_unique<TurretLogic>(data, turret);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr mushLogic = std::make_unique<MushroomLogic>(field, data);
	auto spiderLogic = std::make_unique<SpiderLogic>(field, data);
	CollisionHandlerPtr collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

	CHECK(field->GetMushrooms().empty());
	CHECK(field->GetSpiders().empty());
	spiderLogic->Spawn();
	CHECK(field->GetSpiders().size() == 1);

	// move scorpion
	spiderLogic->Move(0.001);
	// spawn a mushroom at position of scorpion
	auto mushroom = Mushroom(data, field->GetSpiders().at(0).GetTopLeftXPosition(),
		field->GetSpiders().at(0).GetTopLeftYPosition());
	field->GetMushrooms().push_back(mushroom);
	CHECK(field->GetMushrooms().size() == 1);
	collisionhandler->CheckMushroomSpiderCollisions();
	mushLogic->CollisionHandle();
	CHECK(field->GetMushrooms().empty());
}

TEST_CASE("Check that bullet-spider collisions are handled correctly.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	TurretPtr turret = std::make_shared<Turret>(data);
	LogicPtr turretLogic = std::make_unique<TurretLogic>(data, turret);
	FieldPtr field = std::make_shared<GameField>();
	auto spiderLogic = std::make_unique<SpiderLogic>(field, data);
	CollisionHandlerPtr collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

	CHECK(turret->GetBullets().empty());
	CHECK(field->GetSpiders().empty());

	// spawn 
	spiderLogic->Spawn();
	turretLogic->Spawn();
	CHECK(turret->GetBullets().size() == 1);
	CHECK(field->GetSpiders().size() == 1);
	CHECK_FALSE(turret->GetBullets().at(0).IsDead());
	CHECK_FALSE(field->GetSpiders().at(0).IsDead());

	// move the bullet on the spider
	turret->GetBullets().at(0).SetTopLeftXPosition(field->GetSpiders().at(0).GetTopLeftXPosition());
	turret->GetBullets().at(0).SetTopLeftYPosition(field->GetSpiders().at(0).GetTopLeftYPosition());

	CHECK(field->GetSpiders().at(0).GetTopLeftXPosition() == turret->GetBullets().at(0).GetTopLeftXPosition());
	CHECK(field->GetSpiders().at(0).GetTopLeftYPosition() == turret->GetBullets().at(0).GetTopLeftYPosition());

	auto regionHandler = RegionHandler(field->GetSpiders().at(0).GetCenterXPosition(),
		field->GetSpiders().at(0).GetCenterYPosition());
	field->GetSpiders().at(0).SetRegion(regionHandler.GetRegion());
	field->GetSpiders().at(0).SetSubRegion(regionHandler.GetSubRegion());

	regionHandler = RegionHandler(turret->GetBullets().at(0).GetCenterXPosition(),
		turret->GetBullets().at(0).GetCenterYPosition());
	turret->GetBullets().at(0).SetRegion(regionHandler.GetRegion());
	turret->GetBullets().at(0).SetSubRegion(regionHandler.GetSubRegion());

	collisionhandler->CheckBulletSpiderCollisions();

	CHECK(turret->GetBullets().at(0).IsDead());
	CHECK(field->GetSpiders().at(0).IsDead());

	spiderLogic->CollisionHandle();
	turretLogic->CollisionHandle();

	CHECK(turret->GetBullets().empty());
	CHECK(field->GetSpiders().empty());
}

TEST_CASE("Check that bullet-mushroom collisions are handled correctly.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	TurretPtr turret = std::make_shared<Turret>(data);
	LogicPtr turretLogic = std::make_unique<TurretLogic>(data, turret);
	FieldPtr field = std::make_shared<GameField>();
	auto mushLogic = std::make_unique<MushroomLogic>(field, data);
	CollisionHandlerPtr collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

	CHECK(turret->GetBullets().empty());
	CHECK(field->GetMushrooms().empty());

	// spawn entities in known positions
	auto mushroom = Mushroom(data, 10, 10);
	field->GetMushrooms().push_back(mushroom);
	turretLogic->Spawn();
	CHECK(turret->GetBullets().size() == 1);
	CHECK(field->GetMushrooms().size() == 1);
	CHECK_FALSE(turret->GetBullets().at(0).IsDead());
	CHECK_FALSE(field->GetMushrooms().at(0).IsDead());

	// move the bullet onto the mushroom
	turret->GetBullets().at(0).SetTopLeftXPosition(field->GetMushrooms().at(0).GetTopLeftXPosition());
	turret->GetBullets().at(0).SetTopLeftYPosition(field->GetMushrooms().at(0).GetTopLeftYPosition());

	CHECK(field->GetMushrooms().at(0).GetTopLeftXPosition() == turret->GetBullets().at(0).GetTopLeftXPosition());
	CHECK(field->GetMushrooms().at(0).GetTopLeftYPosition() == turret->GetBullets().at(0).GetTopLeftYPosition());

	CHECK(field->GetMushrooms().at(0).GetLivesRemaining() == 4);
	
	collisionhandler->CheckBulletMushroomCollisions();

	CHECK(turret->GetBullets().at(0).IsDead());
	CHECK_FALSE(field->GetMushrooms().at(0).IsDead());

	CHECK(field->GetMushrooms().at(0).GetLivesRemaining() == 3);
	collisionhandler->CheckBulletMushroomCollisions();
	CHECK(field->GetMushrooms().at(0).GetLivesRemaining() == 2);
	collisionhandler->CheckBulletMushroomCollisions();
	CHECK(field->GetMushrooms().at(0).GetLivesRemaining() == 1);
	collisionhandler->CheckBulletMushroomCollisions();
	CHECK(field->GetMushrooms().at(0).GetLivesRemaining() == 0);

	CHECK(field->GetMushrooms().at(0).IsDead());
	mushLogic->CollisionHandle();
	CHECK(field->GetMushrooms().empty());

	turretLogic->CollisionHandle();
	CHECK(turret->GetBullets().empty());
}