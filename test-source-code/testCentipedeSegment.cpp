#include "CentipedeSegment.h"
#include "Game.h"
#include "Direction.h"
#include "Trajectory.h"
#include <memory>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using GameEngine::DataPtr;
using GameEngine::GameData;

TEST_CASE("Centipede Segment Initialised with correct values")
{
	DataPtr _data = std::make_shared<GameData>();
}