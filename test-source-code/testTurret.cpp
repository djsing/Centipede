#include "../game-source-code/Turret.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::Turret;
using GameEngine::Direction;

#include <doctest.h>

TEST_CASE("Turret was initialized properly")
{
	auto data = std::make_shared<GameData>();
	auto turret = Turret{data};
	CHECK(turret.GetTopLeftXPosition() == SCREEN_WIDTH/2- TURRET_SPRITE_SIDE_SIZE/2);
	CHECK(turret.GetTopLeftYPosition() == SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
	CHECK(turret.GetDirection() == Direction::HOVER);
}
