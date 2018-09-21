#include "../game-source-code/SpiderLogic.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::DataPtr;
using GameEngine::GameData;
using GameEngine::FieldPtr;
using GameEngine::GameField;
using GameEngine::LogicPtr;
using GameEngine::SpiderLogic;

#include <doctest.h>

TEST_CASE("Check that spider deaths are handled correctly.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr spiderLogic = std::make_unique<SpiderLogic>(field, data);

	// check that field object created an empty scorpion container
	CHECK(field->GetSpiders().size() == 0);
	// spawn a scorpion
	spiderLogic->Spawn();
	// check that there is one scorpion in the container
	CHECK(field->GetSpiders().size() == 1);

	// check that if the scorpion is killed (setDead = true), as if by collision,
	// the scorpion object is deleted from the container.
	field->GetSpiders().at(0).SetDead(true);
	// check that the scorpion is set as dead
	CHECK(field->GetSpiders().at(0).IsDead());

	// delete all dead scorpions
	spiderLogic->CollisionHandle();
	// check that scorpion container is empty
	CHECK(field->GetSpiders().size() == 0);
}

TEST_CASE("Check that spider is bounded by the turret box ceiling.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr spiderLogic = std::make_unique<SpiderLogic>(field, data);
	spiderLogic->Spawn();

	// set the spider above the ceiling of the turret box
	field->GetSpiders().at(0).SetTopLeftYPosition(TURRET_SCREEN_FRACTION*SCREEN_HEIGHT - SPIDER_SPRITE_SIZE);

	// check that move() sets the position of the spider below the ceiling of the turret box
	spiderLogic->Move(0.01);
	// check that it resets to a random position that is below the turret box
	CHECK(field->GetSpiders().at(0).GetTopLeftYPosition() >= TURRET_SCREEN_FRACTION*SCREEN_HEIGHT);
}

TEST_CASE("Check that spider is bounded by the left wall.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr spiderLogic = std::make_unique<SpiderLogic>(field, data);
	spiderLogic->Spawn();

	// set the spider outside of the left wall
	field->GetSpiders().at(0).SetTopLeftXPosition(-SPIDER_SPRITE_SIZE);

	// check that move() sets the position of the spider outside of the left wall
	spiderLogic->Move(0.01);
	// check that it resets to a random position that is right of the left wall
	CHECK(field->GetSpiders().at(0).GetTopLeftXPosition() > SCREEN_LHS);
}

TEST_CASE("Check that spider is bounded by the right wall.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr spiderLogic = std::make_unique<SpiderLogic>(field, data);
	spiderLogic->Spawn();

	// set the spider outside of the right wall
	field->GetSpiders().at(0).SetTopLeftXPosition(SCREEN_WIDTH - SPIDER_SPRITE_SIZE);

	// check that move() sets the position of the spider outside of the left wall
	spiderLogic->Move(0.01);
	// check that it resets to a random position that is left of the right wall
	CHECK(field->GetSpiders().at(0).GetTopLeftXPosition() <= SCREEN_WIDTH - SPIDER_SPRITE_SIZE);
}

TEST_CASE("Check that spider is bounded by the screen floor.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr spiderLogic = std::make_unique<SpiderLogic>(field, data);
	spiderLogic->Spawn();

	// set the spider below the screen floor
	field->GetSpiders().at(0).SetTopLeftYPosition(SCREEN_HEIGHT + SPIDER_SPRITE_SIZE);

	// check that move() sets the position of the spider above the screen floor
	spiderLogic->Move(0.01);
	// check that it resets to a random position that is above the screen floor
	CHECK(field->GetSpiders().at(0).GetTopLeftYPosition() < SCREEN_HEIGHT);
}