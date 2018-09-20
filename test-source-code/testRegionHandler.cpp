#include "../game-source-code/RegionHandler.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::RegionHandler;
using GameEngine::Region;

#include <doctest.h>

TEST_CASE("Testing regions of top horizontal Quarter of the screen.")
{
	auto regionHandle = RegionHandler(0,0);
	CHECK(regionHandle.GetRegion() == Region::TOP_LEFT);
	CHECK(regionHandle.GetSubRegion() == Region::TOP_LEFT);

	regionHandle = RegionHandler(SCREEN_WIDTH/2 - CENTIPEDE_SPRITE_SIDE_SIZE, 0);
	CHECK(regionHandle.GetRegion() == Region::TOP_LEFT);
	CHECK(regionHandle.GetSubRegion() == Region::TOP_RIGHT);

	regionHandle = RegionHandler(SCREEN_WIDTH/2 + CENTIPEDE_SPRITE_SIDE_SIZE, 0);
	CHECK(regionHandle.GetRegion() == Region::TOP_RIGHT);
	CHECK(regionHandle.GetSubRegion() == Region::TOP_LEFT);

	regionHandle = RegionHandler(SCREEN_WIDTH*3/4 + CENTIPEDE_SPRITE_SIDE_SIZE, 0);
	CHECK(regionHandle.GetRegion() == Region::TOP_RIGHT);
	CHECK(regionHandle.GetSubRegion() == Region::TOP_RIGHT);
}

TEST_CASE("Testing regions of second horizontal Quarter of the screen.")
{
	auto regionHandle = RegionHandler(0, SCREEN_HEIGHT/4 + CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::TOP_LEFT);
	CHECK(regionHandle.GetSubRegion() == Region::BOTTOM_LEFT);

	regionHandle = RegionHandler(SCREEN_WIDTH/2 - CENTIPEDE_SPRITE_SIDE_SIZE,
		SCREEN_HEIGHT/4 + CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::TOP_LEFT);
	CHECK(regionHandle.GetSubRegion() == Region::BOTTOM_RIGHT);

	regionHandle = RegionHandler(SCREEN_WIDTH/2 + CENTIPEDE_SPRITE_SIDE_SIZE,
		SCREEN_HEIGHT/4 + CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::TOP_RIGHT);
	CHECK(regionHandle.GetSubRegion() == Region::BOTTOM_LEFT);

	regionHandle = RegionHandler(SCREEN_WIDTH*3/4 + CENTIPEDE_SPRITE_SIDE_SIZE,
		SCREEN_HEIGHT/4 + CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::TOP_RIGHT);
	CHECK(regionHandle.GetSubRegion() == Region::BOTTOM_RIGHT);
}

TEST_CASE("Testing regions of third horizontal Quarter of the screen.")
{
	auto regionHandle = RegionHandler(0, SCREEN_HEIGHT/2 + CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::BOTTOM_LEFT);
	CHECK(regionHandle.GetSubRegion() == Region::TOP_LEFT);

	regionHandle = RegionHandler(SCREEN_WIDTH/2 - CENTIPEDE_SPRITE_SIDE_SIZE,
		SCREEN_HEIGHT/2 + CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::BOTTOM_LEFT);
	CHECK(regionHandle.GetSubRegion() == Region::TOP_RIGHT);

	regionHandle = RegionHandler(SCREEN_WIDTH/2 + CENTIPEDE_SPRITE_SIDE_SIZE,
		SCREEN_HEIGHT/2 + CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::BOTTOM_RIGHT);
	CHECK(regionHandle.GetSubRegion() == Region::TOP_LEFT);

	regionHandle = RegionHandler(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE,
		SCREEN_HEIGHT/2 + CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::BOTTOM_RIGHT);
	CHECK(regionHandle.GetSubRegion() == Region::TOP_RIGHT);
}

TEST_CASE("Testing regions of fourth horizontal Quarter of the screen.")
{
	auto regionHandle = RegionHandler(0, SCREEN_HEIGHT - CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::BOTTOM_LEFT);
	CHECK(regionHandle.GetSubRegion() == Region::BOTTOM_LEFT);

	regionHandle = RegionHandler(SCREEN_WIDTH/2 - CENTIPEDE_SPRITE_SIDE_SIZE,
		SCREEN_HEIGHT - CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::BOTTOM_LEFT);
	CHECK(regionHandle.GetSubRegion() == Region::BOTTOM_RIGHT);

	regionHandle = RegionHandler(SCREEN_WIDTH/2 + CENTIPEDE_SPRITE_SIDE_SIZE,
		SCREEN_HEIGHT - CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::BOTTOM_RIGHT);
	CHECK(regionHandle.GetSubRegion() == Region::BOTTOM_LEFT);

	regionHandle = RegionHandler(SCREEN_WIDTH*3/4 + CENTIPEDE_SPRITE_SIDE_SIZE,
		SCREEN_HEIGHT - CENTIPEDE_SPRITE_SIDE_SIZE);
	CHECK(regionHandle.GetRegion() == Region::BOTTOM_RIGHT);
	CHECK(regionHandle.GetSubRegion() == Region::BOTTOM_RIGHT);
}