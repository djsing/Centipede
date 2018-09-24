#include "../game-source-code/Spider.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::Spider;

#include <doctest.h>

TEST_CASE ( "Check that spider is initialised with correct values." )
{
	auto spider = Spider();

	CHECK ( spider.GetTopLeftXPosition() == SCREEN_WIDTH / 2 - SPIDER_SPRITE_SIZE / 2 );
	// check within 1% accuracy
	CHECK ( spider.GetTopLeftYPosition() == doctest::Approx ( TURRET_SCREEN_FRACTION * SCREEN_HEIGHT ).epsilon ( 0.01 ) );
}

TEST_CASE ( "Check that spider wraps around from the left to right screen side." )
{
	auto spider = Spider();

	spider.SetTopLeftXPosition ( SCREEN_LHS - 2 * SPIDER_SPRITE_SIZE );
	CHECK ( spider.GetTopLeftXPosition() == SCREEN_WIDTH + SPIDER_SPRITE_SIZE );
}

TEST_CASE ( "Check that spider wraps around from the right to left screen side." )
{
	auto spider = Spider();

	spider.SetTopLeftXPosition ( SCREEN_WIDTH + 2 * SPIDER_SPRITE_SIZE );
	CHECK ( spider.GetTopLeftXPosition() == SCREEN_LHS - SPIDER_SPRITE_SIZE );
}
