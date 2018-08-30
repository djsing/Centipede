#include "MainMenu.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace GameEngine
{
	MainMenu::MainMenu(DataPtr data):
	_data(data)
	{
		_data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
			WINDOW_TITLE, sf::Style::None);
	}

	void MainMenu::Initialise()
	{
		_data->resources.LoadTexture("Menu Screen Background", MENU_BACKGROUND_FILEPATH);
		_background.setTexture(_data->resources.GetTexture("Menu Screen Background"));

		//_data->resources.LoadTexture("Play Button", GAME_PLAY_BUTTON_FILEPATH);
		//_playbutton.setTexture(_data->resources.GetTexture("Play Button"));
		//_playbutton.setPosition((SCREEN_WIDTH/2)-(_playbutton.getGlobalBounds().width/2),
		//	(SCREEN_HEIGHT/2)-(_playbutton.getGlobalBounds().height));

		//_data->resources.LoadTexture("Menu Screen Title", GAME_TITLE_FILEPATH);
		//_title.setTexture(_data->resources.GetTexture("Menu Screen Title"));
		//_title.setPosition((SCREEN_WIDTH/2)-(_title.getGlobalBounds().width/2),
		//	_title.getGlobalBounds().height/2);
	}

	void MainMenu::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			{
				_data->window.close();
			}

			if (_data->mouseInput.IsSpriteClicked(_playbutton, sf::Mouse::Left, _data->window))
			{
				std::cout<<"Go to game screen" << std::endl;
			}
		}
	}

	void MainMenu::Update(float dt)
	{

	}

	void MainMenu::Draw(float interpolation)
	{
		// clear screen to update data
		_data->window.clear();
		// draw all menu sprites
		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playbutton);
		// display updated data
		_data->window.display();
	}
}