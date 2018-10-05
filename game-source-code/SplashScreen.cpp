#include "DEFINITIONS.h"
#include "MainMenu.h"
#include "SplashScreen.h"

namespace GameEngine
{
SplashScreen::SplashScreen(DataPtr data) : data_(data)
{
    renderer_ = std::make_shared<StateRenderer>(data_);
}

void SplashScreen::HandleInput()
{
    sf::Event event;

    while(data_->window.pollEvent(event) && event.type == sf::Event::KeyPressed)
	{
	    if(event.key.code == sf::Keyboard::Escape)
		{
		    data_->window.close();
		}
	}
}

void SplashScreen::Update(float dt)
{
    if(_watch.getElapsedTime() > SPLASH_TIME)
	{
	    data_->statehandler.AddState(StatePtr(new MainMenu(data_)));
	}
}

void SplashScreen::Draw()
{
    // clear screen to update data
    data_->window.clear();
    renderer_->DisplaySplashScreen();
    // display updated data
    data_->window.display();
}
}  // namespace GameEngine
