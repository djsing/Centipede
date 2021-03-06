#include "../game-source-code/ScorpionLogic.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameField;
using GameEngine::ScorpionLogic;

#include <doctest.h>

TEST_CASE ( "Check that scorpion deaths are handled correctly." )
{
	auto field = std::make_shared<GameField>();
	auto scorpionLogic = std::make_unique<ScorpionLogic> ( field );

	// check that field object created an empty scorpion container
	CHECK ( field->GetScorpions().size() == 0 );
	// spawn a scorpion
	scorpionLogic->Spawn();
	// check that there is one scorpion in the container
	CHECK ( field->GetScorpions().size() == 1 );

	// check that if the scorpion is killed (setDead = true), as if by collision,
	// the scorpion object is deleted from the container.
	field->GetScorpions().at ( 0 ).SetDead ( true );
	// check that the scorpion is set as dead
	CHECK ( field->GetScorpions().at ( 0 ).IsDead() );

	// delete all dead scorpions
	scorpionLogic->CollisionHandle();
	// check that scorpion container is empty
	CHECK ( field->GetScorpions().size() == 0 );
}

TEST_CASE ( "Check that scorpion is bounded by the turret-box ceiling." )
{
	auto field = std::make_shared<GameField>();
	auto scorpionLogic = std::make_unique<ScorpionLogic> ( field );
	scorpionLogic->Spawn();

	// set the scorpion below the ceiling of the turret box
	field->GetScorpions().at ( 0 ).SetTopLeftYPosition ( TURRET_SCREEN_FRACTION * SCREEN_HEIGHT + SCORPION_SPRITE_SIZE );

	// check that move() sets the position of the scorpion above the ceiling of the turret box
	scorpionLogic->Move ( 0.01 );
	// check that it resets to a random position that is above the turret box
	CHECK ( field->GetScorpions().at ( 0 ).GetTopLeftYPosition() <= TURRET_SCREEN_FRACTION * SCREEN_HEIGHT );
}

TEST_CASE ( "Check that scorpion is bounded by the screen ceiling." )
{
	auto field = std::make_shared<GameField>();
	auto scorpionLogic = std::make_unique<ScorpionLogic> ( field );
	scorpionLogic->Spawn();

	// set the scorpion below the ceiling of the turret box
	field->GetScorpions().at ( 0 ).SetTopLeftYPosition ( -SCORPION_SPRITE_SIZE );

	// check that move() sets the position of the scorpion above the ceiling of the turret box
	scorpionLogic->Move ( 0.01 );
	// check that it resets to a random position that is above the turret box
	CHECK ( field->GetScorpions().at ( 0 ).GetTopLeftYPosition() > SCREEN_TOP );
}
