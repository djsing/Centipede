#include "DEFINITIONS.h"
#include "GamePlay.h"
#include "MainMenu.h"

namespace GameEngine
{
	MainMenu::MainMenu ( DataPtr data )
		: _data ( data )
	{
		_data->window.create ( sf::VideoMode ( SCREEN_WIDTH, SCREEN_HEIGHT ), WINDOW_TITLE, sf::Style::None );
		_data->window.setVerticalSyncEnabled ( true );
		_data->window.setPosition ( sf::Vector2i ( sf::VideoMode().getDesktopMode().width / 3, 0 ) );

		_data->resources.LoadTexture ( "Menu Screen Title", GAME_TITLE_FILEPATH );
		_data->resources.LoadTexture ( "Subtitle", GAME_SUBTITLE_FILEPATH );
		_data->resources.LoadTexture ( "Instructions", GAME_INSTRUCTIONS );

		_title.setTexture ( _data->resources.GetTexture ( "Menu Screen Title" ) );
		_title.setPosition ( ( SCREEN_WIDTH / 2 ) - ( _title.getGlobalBounds().width / 2 ),
		                     SCREEN_HEIGHT / 2 - _title.getGlobalBounds().height );

		_subtitle.setTexture ( _data->resources.GetTexture ( "Subtitle" ) );
		_subtitle.setPosition ( ( SCREEN_WIDTH / 2 ) - ( _subtitle.getGlobalBounds().width / 2 ), SCREEN_HEIGHT / 2 );

		_instructions.setTexture ( _data->resources.GetTexture ( "Instructions" ) );
		_instructions.setPosition ( ( SCREEN_WIDTH / 2 ) - ( _instructions.getGlobalBounds().width / 2 ),
		                            SCREEN_HEIGHT / 2 + _subtitle.getGlobalBounds().height );
	}

	void MainMenu::HandleInput()
	{
		sf::Event event;

		while ( _data->window.pollEvent ( event ) && event.type == sf::Event::KeyPressed )
		{
			if (  event.key.code == sf::Keyboard::Escape )
			{
				_data->window.close();
			}

			else if  ( event.key.code == sf::Keyboard::Space )
			{
				// if player presses space, start game
				_data->statehandler.AddState ( StatePtr ( new GamePlay ( _data ) ) );
			}
		}
	}

	void MainMenu::Update ( float dt )
	{
	}

	void MainMenu::Draw()
	{
		// clear screen to update data
		_data->window.clear();
		// draw all menu sprites
		_data->window.draw ( _background );
		_data->window.draw ( _title );
		_data->window.draw ( _subtitle );
		_data->window.draw ( _instructions );
		// display updated data
		_data->window.display();
	}
} // namespace GameEngine
