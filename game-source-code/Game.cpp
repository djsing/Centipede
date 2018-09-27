#include "Game.h"
#include "SplashScreen.h"

namespace GameEngine
{
Game::Game(int width, int height, std::string windowTitle)
{
    data_->window.create(sf::VideoMode(width, height), windowTitle, sf::Style::None);
    data_->statehandler.AddState(StatePtr(new SplashScreen(data_)));
    Run();
}

void Game::Run()
{
    auto newTime = 0.f;
    auto frameTime = 0.f;
    auto currentTime = watch_.getElapsedTime();
    auto accumulator = 0.f;

    while(data_->window.isOpen())
	{
	    data_->statehandler.ProcessStateChanges();

	    newTime = watch_.getElapsedTime();
	    frameTime = newTime - currentTime;
	    currentTime = newTime;
	    accumulator += frameTime;

	    while((accumulator >= dt_) && (data_->window.isOpen()))
		{
		    data_->statehandler.GetActiveGameState()->HandleInput();
		    data_->statehandler.GetActiveGameState()->Update(dt_);
		    accumulator -= dt_;
		}

	    data_->statehandler.GetActiveGameState()->Draw();
	}
}
}  // namespace GameEngine
