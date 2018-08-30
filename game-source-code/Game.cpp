#include "Game.h"
#include "SplashScreen.h"

namespace GameEngine
{
	Game::Game(int width, int height, std::string windowTitle)
	{
		_data->window.create(sf::VideoMode(800, 600),
			windowTitle, sf::Style::None);
		_data->statehandler.AddState(StatePtr(new SplashScreen(_data)));
		Run();
	}
	
	void Game::Run()
	{
		float newTime, frameTime, interpolation;
		auto currentTime = watch.getElapsedTime();
		auto accumulator = 0.f;

		while (_data->window.isOpen())
		{
			_data->statehandler.ProcessStateChanges();
			newTime = watch.getElapsedTime();
			frameTime = newTime - currentTime;
			//limit fps not to drop below 4
			//if (frameTime > 0.25f)
			//{
			//	frameTime = 0.25f;
			//}

			currentTime = newTime;
			accumulator += frameTime;
			while (accumulator >= _dt)
			{
				_data->statehandler.GetActiveGameState()->HandleInput();
				_data->statehandler.GetActiveGameState()->Update(_dt);
				accumulator -= _dt;
			}
			interpolation = accumulator/_dt;
			_data->statehandler.GetActiveGameState()->Draw(interpolation);
		}
	}
}