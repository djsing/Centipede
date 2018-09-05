#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <memory>
#include "../game-source-code/CentipedeSegment.h"
#include "../game-source-code/Game.h"
#include "../game-source-code/Direction.h"
#include "../game-source-code/Trajectory.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::DataPtr;
using GameEngine::CentipedeSegment;
using GameEngine::Direction;
using GameEngine::Trajectory;

TEST_CASE("Centipede Segment Initialised with correct values")
{
	
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	auto segment = CentipedeSegment(data, true);
	// check that sprite moves to the right and towards the bottom
	// of the screen
	CHECK(segment.GetDirection() == Direction::RIGHT);
	CHECK(segment.GetTrajectory() == Trajectory::DOWNWARD);
	// check that position tracker initalised 
	// with top left corner at (0,0)
	CHECK(segment.GetTopLeftXPosition() == 0);
	CHECK(segment.GetTopLeftYPosition() == 0);
	// since sprite size is 20x20, the center should be (10,10)
	// if initialised at (0,0)
	CHECK(segment.GetCenterXPosition() == 10);
	CHECK(segment.GetCenterYPosition() == 10);
}

TEST_CASE("Check if centipede turns downward at the right wall for downward trajectory")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	auto segment = CentipedeSegment(data, true);
	segment.MoveCentipedeSegments(SCREEN_WIDTH);
	//This moves it passed the edge of the screen
	segment.MoveCentipedeSegments(1);
	//Now the program registers that the segment is out of bounds,needs to set the direction to downward and position to edge of screen
	CHECK(segment.GetDirection()==Direction::DOWN);
	CHECK(segment.GetTopLeftXPosition()==SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);
}

TEST_CASE("Check if cenitpede moves to the left once it hits right wall for downward trajectory.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	auto segment = CentipedeSegment(data, true);
	segment.MoveCentipedeSegments(SCREEN_WIDTH);
	//This moves it passed the edge of the screen
	segment.MoveCentipedeSegments(1);
	//Now the program registers that the segment is out of bounds,needs to set the direction to downward and position to edge of screen
	segment.MoveCentipedeSegments(1);
	//Expect the direction to change Left
	CHECK(segment.GetDirection()==Direction::LEFT);
}

TEST_CASE("Left wall boundary behaviour for downward trajectory")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	auto segment = CentipedeSegment(data, true);
	segment.MoveCentipedeSegments(SCREEN_WIDTH);
	//This moves it passed the edge of the screen
	segment.MoveCentipedeSegments(1);
	//Now the program registers that the segment is out of bounds,needs to set the direction to downward and position to edge of screen
	segment.MoveCentipedeSegments(1);
	//Expect the direction to change Left
	segment.MoveCentipedeSegments(SCREEN_WIDTH);//The segement is now pushed passed the left hand side of screen
	segment.MoveCentipedeSegments(1);//Expect the segment to drop to the next level and position it at the left boundary 
	CHECK(segment.GetDirection()==Direction::DOWN);
	CHECK(segment.GetTopLeftXPosition()==0);
	segment.MoveCentipedeSegments(1);//Expect the segment to change direction to Right
	CHECK(segment.GetDirection()==Direction::RIGHT);
}

TEST_CASE("Segemnt right wall behaviour for upward trajectory")
{
		DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	auto segment = CentipedeSegment(data, true);
	for (int i=0;i<(SCREEN_HEIGHT);i++)
	{
		segment.MoveCentipedeSegments(SCREEN_WIDTH);
		segment.MoveCentipedeSegments(1);
		if (segment.GetTrajectory()==Trajectory::UPWARD)
			{
				//only if the segment reaches bottom right of game screen
				CHECK(segment.GetTrajectory()==Trajectory::UPWARD);
				segment.MoveCentipedeSegments(1);//Move a level up
				CHECK(segment.GetTopLeftYPosition()<SCREEN_HEIGHT);
				CHECK(segment.GetDirection()==Direction::LEFT);//Check if the direction is Left
				break;
			}
	}
}

TEST_CASE("Segment's left wall behaviour for upward trajectory")
{
		DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	auto segment = CentipedeSegment(data, true);
	for (int i=0;i<(SCREEN_HEIGHT);i++)
	{
		segment.MoveCentipedeSegments(SCREEN_WIDTH);
		segment.MoveCentipedeSegments(1);
		if (segment.GetTrajectory()==Trajectory::UPWARD)
			{
				//only if the segment reaches bottom right of game screen
				CHECK(segment.GetTrajectory()==Trajectory::UPWARD);
				segment.MoveCentipedeSegments(1);//Move a level up and direction is Left
				break;
			}
	}
	//Segement moving towards the left wall
	segment.MoveCentipedeSegments(SCREEN_WIDTH);//Moves segment passed left wall
	segment.MoveCentipedeSegments(1);//Sets direction upward, and sprite's left postion to left wall boundary
	CHECK(segment.GetDirection()==Direction::UP);
	CHECK(segment.GetTopLeftXPosition()==0);
	segment.MoveCentipedeSegments(1);//After level up expect segement to move in the Right direction
	CHECK(segment.GetDirection()==Direction::RIGHT);
}

TEST_CASE("Segment on upward trajectory and reaches the upper boundary of game screen")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
	data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	auto segment = CentipedeSegment(data, true);
	for (int i=0;i<(SCREEN_HEIGHT);i++)
	{
		segment.MoveCentipedeSegments(SCREEN_WIDTH);
		segment.MoveCentipedeSegments(1);
		if (segment.GetTrajectory()==Trajectory::UPWARD)
			{
				//only if the segment reaches bottom right of game screen
				CHECK(segment.GetTrajectory()==Trajectory::UPWARD);
				segment.MoveCentipedeSegments(1);//Move a level up and direction is Left
				break;
			}
	}
	//Centipede needs to be pushed up to the roof
	for (int i=0;i<(SCREEN_HEIGHT);i++)
	{
		segment.MoveCentipedeSegments(SCREEN_WIDTH);
		segment.MoveCentipedeSegments(1);
		if (segment.GetTrajectory()==Trajectory::DOWNWARD)
			{
				//only if the segment reaches bottom right of game screen
				segment.MoveCentipedeSegments(1);//Move a level up and direction is Left
				break;
			}
	}
	CHECK(segment.GetTrajectory()==Trajectory::DOWNWARD);
}