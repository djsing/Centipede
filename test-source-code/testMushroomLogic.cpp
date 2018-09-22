#include "../game-source-code/MushroomLogic.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::GameField;
using GameEngine::MushroomLogic;

#include <doctest.h>

TEST_CASE("Check that size of mushroom vector is the same as MUSHROOMS_SPAWNED")
{
	auto data = std::make_shared<GameData>();
	auto field = std::make_shared<GameField>();
	auto mushroomLogic = std::make_unique<MushroomLogic>(field, data);
	mushroomLogic->Spawn();

	CHECK(field->GetMushrooms().size() == MUSHROOMS_SPAWNED);

	field->GetMushrooms().at(0).SetDead(true);
	mushroomLogic->CollisionHandle();

	CHECK(field->GetMushrooms().size() == MUSHROOMS_SPAWNED - 1);
}