#include "../game-source-code/CentipedeSegment.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::DataPtr;
using GameEngine::CentipedeSegment;
using GameEngine::Direction;
using GameEngine::Trajectory;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

TEST_CASE("Centipede Segment Initialised with correct values")
{
	DataPtr data = std::make_shared<GameData>();
	// single centipede head
	auto segment = CentipedeSegment(data, true);

	// check that position tracker initalised with top left corner at (0,0)
	CHECK(segment.GetDirection() == Direction::RIGHT);
	CHECK(segment.GetTrajectory() == Trajectory::DOWNWARD);
	CHECK(segment.GetTopLeftXPosition() == 0);
	CHECK(segment.GetTopLeftYPosition() == 0);
	// since sprite size is 20x20, the center should be (10,10) if initialised at (0,0)
	CHECK(segment.GetCenterXPosition() == 10);
	CHECK(segment.GetCenterYPosition() == 10);
}