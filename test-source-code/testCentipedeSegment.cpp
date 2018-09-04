#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "CentipedeSegment.h"
#include "Game.h"
#include "Direction.h"
#include "Trajectory.h"
#include <memory>

TEST_CASE("Centipede Segment Initialised with correct values")
{
	GameEngine::CentipedeSegment segment(true);
}