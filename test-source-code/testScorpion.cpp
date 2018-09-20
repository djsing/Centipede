#include "../game-source-code/Scorpion.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::DataPtr;
using GameEngine::Scorpion;

#include <doctest.h>

TEST_CASE("Check that scorpion is initialised with correct values.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Scorpion sprite", SCORPION_FILEPATH);
	auto scorpion = Scorpion(data);
	CHECK(scorpion.GetTopLeftXPosition() == SCREEN_WIDTH/2 - SCORPION_SPRITE_SIZE/2);
	// check within 1% accuracy
	CHECK(scorpion.GetTopLeftYPosition() == doctest::Approx(SCORPION_STARTING_Y_POSITION_FRACTION*SCREEN_HEIGHT).epsilon(0.01));
}