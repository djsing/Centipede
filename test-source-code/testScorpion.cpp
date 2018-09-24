#include "../game-source-code/Scorpion.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::Scorpion;

#include <doctest.h>

TEST_CASE ( "Check that scorpion is initialised with correct values." )
{
	auto scorpion = Scorpion();

	CHECK ( scorpion.GetTopLeftXPosition() == SCREEN_WIDTH / 2 - SCORPION_SPRITE_SIZE / 2 );
	// check within 1% accuracy
	CHECK ( scorpion.GetTopLeftYPosition() == doctest::Approx ( SCORPION_STARTING_Y_POSITION_FRACTION * SCREEN_HEIGHT ).epsilon ( 0.01 ) );
}

TEST_CASE ( "Check that scorpion wraps around from the left to right screen side." )
{
	auto scorpion = Scorpion();

	scorpion.SetTopLeftXPosition ( SCREEN_LHS - 2 * SCORPION_SPRITE_SIZE );
	CHECK ( scorpion.GetTopLeftXPosition() == SCREEN_WIDTH + SCORPION_SPRITE_SIZE );
}

TEST_CASE ( "Check that scorpion wraps around from the right to left screen side." )
{
	auto scorpion = Scorpion();

	scorpion.SetTopLeftXPosition ( SCREEN_WIDTH + 2 * SCORPION_SPRITE_SIZE );
	CHECK ( scorpion.GetTopLeftXPosition() == SCREEN_LHS - SCORPION_SPRITE_SIZE );
}
