#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateHandler.h"
#include "ResourceManager.h"
#include "StopWatch.h"

namespace GameEngine
{
	struct GameData
	{
		StateHandler statehandler;
		sf::RenderWindow window;
		ResourceManager resources;
	};

	typedef std::shared_ptr<GameData> DataPtr;

	class Game
	{
	public:
		Game(int width, int height, std::string windowTitle);

	private:
		const float _dt = 1.0f/120.0f;
		StopWatch watch;
		DataPtr _data = std::make_shared<GameData>();
		// Starts game loop
		void Run();
	};
}

#endif