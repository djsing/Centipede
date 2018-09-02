#include "MainMenu.h"
#include "GamePlay.h"
#include "Game.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	MainMenu::MainMenu(DataPtr data):
	_data(data)
	{
		if (sf::VideoMode().getDesktopMode() > sf::VideoMode(1920, 1080))
		{
			_data->window.create(sf::VideoMode(1920, 1080), WINDOW_TITLE, 
				sf::Style::Close);
		} else 
		{
			_data->window.create(sf::VideoMode().getDesktopMode(),
				WINDOW_TITLE, sf::Style::None);
		}
		_data->window.setVerticalSyncEnabled(true);
	}

	void MainMenu::Initialise()
	{
		_data->resources.LoadTexture("Menu Screen Background", MENU_BACKGROUND_FILEPATH);
		_background.setTexture(_data->resources.GetTexture("Menu Screen Background"));

		_data->resources.LoadTexture("Menu Screen Title", GAME_TITLE_FILEPATH);
		_title.setTexture(_data->resources.GetTexture("Menu Screen Title"));
		_title.setPosition((SCREEN_WIDTH/2)-(_title.getGlobalBounds().width/2),
			_title.getGlobalBounds().height/2);
	}

	void MainMenu::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) ||
				(event.type == sf::Event::Closed))
			{
				_data->window.close();
			}

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
				// if player presses space, start game 
				_data->statehandler.AddState(StatePtr(new GamePlay(_data)));
			}
		}
	}

	void MainMenu::Update(float dt)
	{

	}

	void MainMenu::Draw()
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