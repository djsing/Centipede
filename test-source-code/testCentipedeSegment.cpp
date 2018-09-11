#include <memory>
#include <vector>
#include "../game-source-code/Centipede.h"
#include "../game-source-code/CentipedeLogic.h"
#include "../game-source-code/Game.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::DataPtr;
using GameEngine::LogicPtr;
using GameEngine::CentipedeSegment;
using GameEngine::Direction;
using GameEngine::Trajectory;
using GameEngine::CentPtr;
using GameEngine::Centipede;
using GameEngine::CentipedeLogic;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

TEST_CASE("Centipede Segment Initialised with correct values")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	centipedeLogic->Spawn();

	// check that position tracker initalised with top left corner at (0,0)
	CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::RIGHT);
	CHECK(centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::DOWNWARD);
	CHECK(centipede->GetCentipede().at(0).GetTopLeftXPosition() == 0);
	CHECK(centipede->GetCentipede().at(0).GetTopLeftYPosition() == 0);
	// since sprite size is 20x20, the center should be (10,10) if initialised at (0,0)
	CHECK(centipede->GetCentipede().at(0).GetCenterXPosition() == 10);
	CHECK(centipede->GetCentipede().at(0).GetCenterYPosition() == 10);
}

TEST_CASE("Check if centipede turns downward at the right wall for downward trajectory")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	centipedeLogic->Spawn();

	// since sprite is already moving RIGHT, set sprite to right edge of screen
	centipede->GetCentipede().at(0).SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);
	// move sprite slightly off screen
	centipedeLogic->Move(0.01);

	// Now the program registers that the segment is out of bounds, needs to set the direction to downward and position to edge of screen
	CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::DOWN);
	CHECK(centipede->GetCentipede().at(0).GetTopLeftXPosition() == SCREEN_WIDTH- CENTIPEDE_SPRITE_SIDE_SIZE);
}

TEST_CASE("Check if cenitpede moves to the left once it hits right wall for downward trajectory.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	centipedeLogic->Spawn();

	// since sprite is already moving RIGHT, set sprite to right edge of screen
	centipede->GetCentipede().at(0).SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);
	// move sprite slightly off screen
	centipedeLogic->Move(0.01);
	// sprite should be moving down at this point, so a further move should be to the left
	centipedeLogic->Move(0.01);

	// sprite should be moving left
	CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::LEFT);
}

TEST_CASE("Check if cenitpede moves to the right once it hits left wall for downward trajectory.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	centipedeLogic->Spawn();

	// since sprite is already moving RIGHT, set sprite to right edge of screen
	centipede->GetCentipede().at(0).SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);
	// move sprite slightly off screen
	centipedeLogic->Move(0.01);
	// sprite should be moving down at this point, so a further move should be to the left
	centipedeLogic->Move(0.01);
	// sprite should be moving LEFT at this point, so set to the left edge of the screen
	centipede->GetCentipede().at(0).SetTopLeftXPosition(0);
	// move the segment off screen on the left hand side
	centipedeLogic->Move(0.01);

	// program should register a left move off screen, and change the direction to down
	CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::DOWN);
	CHECK(centipede->GetCentipede().at(0).GetTopLeftXPosition() == 0);

	// the next move should move the segment to the right
	centipedeLogic->Move(0.01);

	// check if segment is moving to the right
	CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::RIGHT);
}

TEST_CASE("Segment left and right wall behaviour for upward trajectory.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	centipedeLogic->Spawn();

	// manually move the segment across the screen in steps which measure CENTIPEDE_SPEED units in length,
	// to achieve this, use a time step of 1
	while (centipede->GetCentipede().at(0).GetTrajectory() != Trajectory::UPWARD)
	{ 
		centipedeLogic->Move(1);
	}
	// check that sprite is at the bottom of the screen
	CHECK(centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::UPWARD);

	centipedeLogic->Move(1);	// Move a level up

	// check that sprite is not set off screen at the bottom
	CHECK(centipede->GetCentipede().at(0).GetTopLeftYPosition() < SCREEN_HEIGHT - CENTIPEDE_SPRITE_SIDE_SIZE);

	// if at right side of the screen
	if (centipede->GetCentipede().at(0).GetTopLeftXPosition() == SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE)
	{
		CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::LEFT);	// Check if the direction changes to Left
	}
	// if at left side of the screen
	else if (centipede->GetCentipede().at(0).GetTopLeftXPosition() == 0)
	{
		CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::RIGHT);	// Check if the direction changes to right
	}
	// save previous direction
	auto prevDirection = centipede->GetCentipede().at(0).GetDirection();
	
	// move segment to opposite side of wall
	while (centipede->GetCentipede().at(0).GetDirection() != Direction::UP)
	{ 
		centipedeLogic->Move(1);
	}

	centipedeLogic->Move(1);	// Move a level up

	CHECK_FALSE(centipede->GetCentipede().at(0).GetDirection() == Direction::DOWN);
	CHECK_FALSE(centipede->GetCentipede().at(0).GetDirection() == Direction::UP);

	if (prevDirection == Direction::LEFT)
	{
		CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::RIGHT);
	}
	else if (prevDirection == Direction::RIGHT)
	{
		CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::LEFT);
	}
}

TEST_CASE("Segment on upward trajectory and reaches the upper boundary of game screen")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	CentPtr centipede = std::make_shared<Centipede>(data);
	LogicPtr centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
	centipedeLogic->Spawn();

	// move segment to bottom of the screen
	while (centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::DOWNWARD)
	{
		centipedeLogic->Move(1);
	}

	// move segment to top of screen
	while (centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::UPWARD)
	{
		centipedeLogic->Move(1);
	}

	// check that trajectory changes to downward when segment reaches the top
	CHECK(centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::DOWNWARD);

	// check that segment is not moving vertically
	CHECK_FALSE(centipede->GetCentipede().at(0).GetDirection() == Direction::DOWN);
	CHECK_FALSE(centipede->GetCentipede().at(0).GetDirection() == Direction::UP);
	// check that centipede is either at left side or right side of screen
	bool atEitherSide = ((centipede->GetCentipede().at(0).GetTopLeftXPosition() == 0) || 
		(centipede->GetCentipede().at(0).GetTopLeftXPosition() == SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE));
	CHECK(atEitherSide);

	// check that segment is moving in the correct direction
	if (centipede->GetCentipede().at(0).GetTopLeftXPosition() == SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE)
	{
		CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::LEFT);
	}
	else CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::RIGHT);
}