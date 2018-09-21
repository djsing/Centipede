#include "../game-source-code/Spider.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::Spider;

#include <doctest.h>

TEST_CASE("Check that spider is initialised with correct values.")
{
	auto data = std::make_shared<GameData>();
	auto spider = Spider(data);
	CHECK(spider.GetTopLeftXPosition() == SCREEN_WIDTH/2 - SPIDER_SPRITE_SIZE/2);
	// check within 1% accuracy
	CHECK(spider.GetTopLeftYPosition() == doctest::Approx(TURRET_SCREEN_FRACTION*SCREEN_HEIGHT).epsilon(0.01));
}