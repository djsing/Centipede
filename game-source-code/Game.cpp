#include "Game.h"
#include "SplashScreen.h"

namespace GameEngine
{
	Game::Game(int width, int height, std::string windowTitle)
	{
		_data->window.create(sf::VideoMode(width, height),
			windowTitle, sf::Style::None);
		_data->statehandler.AddState(StatePtr(new SplashScreen(_data)));
		Run();
	}

	void Game::Run()
	{
		auto newTime = 0.f;
		auto frameTime = 0.f;
		auto currentTime = _watch.getElapsedTime();
		auto accumulator = 0.f;

		while (_data->window.isOpen())
		{
			_data->statehandler.ProcessStateChanges();

			newTime = _watch.getElapsedTime();
			frameTime = newTime - currentTime;
			currentTime = newTime;
			accumulator += frameTime;

			while ((accumulator >= _dt) && (_data->window.isOpen()))
			{
				_data->statehandler.GetActiveGameState()->HandleInput();
				_data->statehandler.GetActiveGameState()->Update(_dt);
				accumulator -= _dt;
			}

			_data->statehandler.GetActiveGameState()->Draw();
		}
	}
}