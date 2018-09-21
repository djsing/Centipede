#include "../game-source-code/DEFINITIONS.h"
#include "../game-source-code/KeyboardControlsHandler.h"

using GameEngine::KeyboardControlsHandler;
using GameEngine::Direction;

#include <doctest.h>

TEST_CASE("Initialised correct.")
{	
	auto trial_Keyboard = KeyboardControlsHandler();
	CHECK(trial_Keyboard.GetDirection() == Direction::HOVER);
	CHECK_FALSE(trial_Keyboard.IsShooting());
}

TEST_CASE("isShooting function works with SetShooting function.")
{
	auto trial_Keyboard = KeyboardControlsHandler();
	trial_Keyboard.SetShooting(true);
	CHECK(trial_Keyboard.IsShooting());
	trial_Keyboard.SetShooting(false);
	CHECK_FALSE(trial_Keyboard.IsShooting());
}

TEST_CASE("GetDirection function returns the answer given from the SetDirection")
{
	auto trial_Keyboard = KeyboardControlsHandler();
	trial_Keyboard.SetDirection(Direction::UP);
	CHECK(trial_Keyboard.GetDirection() == Direction::UP);
	trial_Keyboard.SetDirection(Direction::DOWN);
	CHECK(trial_Keyboard.GetDirection() == Direction::DOWN);
	trial_Keyboard.SetDirection(Direction::LEFT);
	CHECK(trial_Keyboard.GetDirection() == Direction::LEFT);
	trial_Keyboard.SetDirection(Direction::RIGHT);
	CHECK(trial_Keyboard.GetDirection() == Direction::RIGHT);
	trial_Keyboard.SetDirection(Direction::HOVER);
	CHECK(trial_Keyboard.GetDirection() == Direction::HOVER);
}