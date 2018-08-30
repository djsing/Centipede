#include "SplashScreen.h"
#include "MainMenu.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	SplashScreen::SplashScreen(DataPtr data):
	_data(data)
	{}

	void SplashScreen::Initialise()
	{
		_data->resources.LoadTexture("Splash Screen Background", SPLASH_BACKGROUND_FILEPATH);
		_background.setTexture(_data->resources.GetTexture("Splash Screen Background"));
	}

	void SplashScreen::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			{
				_data->window.close();
			}
		}
	}

	void SplashScreen::Update(float dt)
	{
		if (_watch.getElapsedTime() > SPLASH_TIME)
		{
			_data->statehandler.AddState(StatePtr(new MainMenu(_data)));
		}
	}

	void SplashScreen::Draw(float interpolation)
	{
		// clear screen to update data
		_data->window.clear();
		// draw background sprite with background texture loaded
		_data->window.draw(_background);
		// display updated data
		_data->window.display();
	}
}