#include <memory>
#include <vector>
#include "../game-source-code/MushroomLogic.h"
#include "../game-source-code/Game.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::DataPtr;
using GameEngine::LogicPtr;
using GameEngine::FieldPtr;
using GameEngine::GameField;
using GameEngine::MushroomLogic;

#include <doctest.h>

TEST_CASE("Check that size of mushroom vector is the same as MUSHROOMS_SPAWNED")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
	FieldPtr field = std::make_shared<GameField>();
	LogicPtr mushroomLogic = std::make_unique<MushroomLogic>(field, data);
	mushroomLogic->Spawn();

	CHECK(field->GetMushrooms().size() == MUSHROOMS_SPAWNED);
}