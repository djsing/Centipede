#include "../game-source-code/Mushroom.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::Region;
using GameEngine::Mushroom;

#include <doctest.h>

TEST_CASE("Mushroom Initialised with correct values when created")
{
	auto data = std::make_shared<GameData>();
	auto mushroom = Mushroom{data, 0, 0};
	// check that position tracker initalised with top left corner at (0,0)
	CHECK(mushroom.GetRegion() == Region::TOP_LEFT);
	CHECK(mushroom.GetSubRegion() == Region::TOP_LEFT);
	CHECK(mushroom.GetTopLeftXPosition() == 0);
	CHECK(mushroom.GetTopLeftYPosition() == 0);
	// since sprite size is 20x20, the center should be (10,10) if initialised at (0,0)
	CHECK(mushroom.GetCenterXPosition() == 10);
	CHECK(mushroom.GetCenterYPosition() == 10);
	CHECK_FALSE(mushroom.IsDead());
	CHECK_FALSE(mushroom.IsPoisoned());
}