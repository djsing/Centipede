#include "../game-source-code/InputHandler.h"
#include "../game-source-code/DEFINITIONS.h"
#include "../game-source-code/KeyboardControlsHandler.h"

using GameEngine::GameData;
using GameEngine::KeyboardControlsHandler;
using GameEngine::InputHandler;
using GameEngine::Direction;

#include <doctest.h>

TEST_CASE("Left key is pressed")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyPressed;
	trialEvent.key.code = sf::Keyboard::Left;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	CHECK(data->keyboard.GetDirection() == Direction::LEFT);
}

TEST_CASE("Right key is pressed")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyPressed;
	trialEvent.key.code = sf::Keyboard::Right;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	CHECK(data->keyboard.GetDirection() == Direction::RIGHT);
}

TEST_CASE("Up key is pressed")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyPressed;
	trialEvent.key.code = sf::Keyboard::Up;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	CHECK(data->keyboard.GetDirection() == Direction::UP);
}

TEST_CASE("Down key is pressed")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyPressed;
	trialEvent.key.code = sf::Keyboard::Down;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	CHECK(data->keyboard.GetDirection() == Direction::DOWN);
}

TEST_CASE("Space key is pressed for the first time")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyPressed;
	trialEvent.key.code = sf::Keyboard::Space;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	CHECK(data->keyboard.IsShooting());
}

TEST_CASE("Space key is being held down")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyPressed;
	trialEvent.key.code = sf::Keyboard::Space;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	Trial.SetControls(trialEvent);
	CHECK_FALSE(data->keyboard.IsShooting());
}

TEST_CASE("Left key is released")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyReleased;
	trialEvent.key.code = sf::Keyboard::Left;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	CHECK(data->keyboard.GetDirection() == Direction::HOVER);
}

TEST_CASE("Right key is released")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyReleased;
	trialEvent.key.code = sf::Keyboard::Right;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	CHECK(data->keyboard.GetDirection() == Direction::HOVER);
}

TEST_CASE("Up key is released")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyReleased;
	trialEvent.key.code = sf::Keyboard::Up;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	CHECK(data->keyboard.GetDirection() == Direction::HOVER);
}

TEST_CASE("Down key is released")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyReleased;
	trialEvent.key.code = sf::Keyboard::Down;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	CHECK(data->keyboard.GetDirection() == Direction::HOVER);
}

TEST_CASE("Space key is pressed for the first time and released")
{
	auto data = std::make_shared<GameData>();
	auto trialEvent = sf::Event();
	trialEvent.type = sf::Event::KeyPressed;
	trialEvent.key.code = sf::Keyboard::Space;
	InputHandler Trial(data);
	Trial.SetControls(trialEvent);
	trialEvent.type = sf::Event::KeyReleased;
	trialEvent.key.code = sf::Keyboard::Space;
	Trial.SetControls(trialEvent);
	CHECK_FALSE(data->keyboard.IsShooting());
}