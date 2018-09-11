#include <memory>
#include <vector>
#include "../game-source-code/Mushroom.h"
#include "../game-source-code/Game.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::DataPtr;
using GameEngine::Direction;
using GameEngine::Region;
using GameEngine::Mushroom;

#include <doctest.h>

TEST_CASE("Mushroom Initialised with correct values when created")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
	auto mushroom = Mushroom{data, 0, 0, Region::TOP_LEFT, Region::TOP_LEFT};
	// check that position tracker initalised with top left corner at (0,0)
	CHECK(mushroom.GetRegion() == Region::TOP_LEFT);
	CHECK(mushroom.GetSubRegion() == Region::TOP_LEFT);
	CHECK(mushroom.GetTopLeftXPosition() == 0);
	CHECK(mushroom.GetTopLeftYPosition() == 0);
	// since sprite size is 20x20, the center should be (10,10) if initialised at (0,0)
	CHECK(mushroom.GetMushroomCenterXPosition() == 10);
	CHECK(mushroom.GetMushroomCenterYPosition() == 10);
}