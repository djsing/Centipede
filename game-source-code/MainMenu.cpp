#include "DEFINITIONS.h"
#include "GamePlay.h"
#include "MainMenu.h"

namespace GameEngine
{
	MainMenu::MainMenu ( DataPtr data )
		: data_ ( data )
	{
		data_->window.create ( sf::VideoMode ( SCREEN_WIDTH, SCREEN_HEIGHT ), WINDOW_TITLE, sf::Style::None );
		data_->window.setVerticalSyncEnabled ( true );
		data_->window.setPosition ( sf::Vector2i ( sf::VideoMode().getDesktopMode().width / 3, 0 ) );

		data_->resources.LoadTexture ( "Menu Screen Title", GAME_TITLE_FILEPATH );
		data_->resources.LoadTexture ( "Subtitle", GAME_SUBTITLE_FILEPATH );
		data_->resources.LoadTexture ( "Instructions", GAME_INSTRUCTIONS );

		title_.setTexture ( data_->resources.GetTexture ( "Menu Screen Title" ) );
		title_.setPosition ( ( SCREEN_WIDTH / 2 ) - ( title_.getGlobalBounds().width / 2 ),
		                     SCREEN_HEIGHT / 2 - title_.getGlobalBounds().height );

		subtitle_.setTexture ( data_->resources.GetTexture ( "Subtitle" ) );
		subtitle_.setPosition ( ( SCREEN_WIDTH / 2 ) - ( subtitle_.getGlobalBounds().width / 2 ), SCREEN_HEIGHT / 2 );

		instructions_.setTexture ( data_->resources.GetTexture ( "Instructions" ) );
		instructions_.setPosition ( ( SCREEN_WIDTH / 2 ) - ( instructions_.getGlobalBounds().width / 2 ),
		                            SCREEN_HEIGHT / 2 + subtitle_.getGlobalBounds().height );
	}

	void MainMenu::HandleInput()
	{
		sf::Event event;

		while ( data_->window.pollEvent ( event ) && event.type == sf::Event::KeyPressed )
		{
			if (  event.key.code == sf::Keyboard::Escape )
			{
				data_->window.close();
			}

			else if  ( event.key.code == sf::Keyboard::Space )
			{
				// if player presses space, start game
				data_->statehandler.AddState ( StatePtr ( new GamePlay ( data_ ) ) );
			}
		}
	}

	void MainMenu::Update ( float dt )
	{
	}

	void MainMenu::Draw()
	{
		// clear screen to update data
		data_->window.clear();
		// draw all menu sprites
		data_->window.draw ( background_ );
		data_->window.draw ( title_ );
		data_->window.draw ( subtitle_ );
		data_->window.draw ( instructions_ );
		// display updated data
		data_->window.display();
	}
} // namespace GameEngine
