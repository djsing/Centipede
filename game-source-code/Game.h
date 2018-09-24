#ifndef GAME_H
#define GAME_H

#include "KeyboardControlsHandler.h"
#include "LivesHandler.h"
#include "ResourceManager.h"
#include "StateHandler.h"
#include "StopWatch.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

namespace GameEngine
{
	struct GameData
	{
		StateHandler statehandler;
		sf::RenderWindow window;
		ResourceManager resources;
		KeyboardControlsHandler keyboard;
		LivesHandler lives;
	};

	using DataPtr = std::shared_ptr<GameData>;

	class Game
	{
	public:
		Game ( int width, int height, std::string windowTitle );

	private:
		const float dt_ = 1.0f / 120.0f;
		StopWatch watch_;
		DataPtr data_ = std::make_shared<GameData>();
		// Starts game loop
		void Run();
	};
} // namespace GameEngine

#endif
