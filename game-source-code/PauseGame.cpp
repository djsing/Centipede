#include "DEFINITIONS.h"
#include "GamePlay.h"
#include "PauseGame.h"

namespace GameEngine
{
	PauseGame::PauseGame ( DataPtr data )
		: _data ( data )
	{
		// create pause background
		_resumeBackground.create ( _data->window.getSize().x, _data->window.getSize().y );
		_resumeBackground.update ( _data->window );
		_BACKGROUND.setTexture ( _resumeBackground );
		// load pause sprites
		_data->resources.LoadTexture ( "Game Paused Sprite", PAUSE_FILEPATH );
		_data->resources.LoadTexture ( "Press Space Resume", PAUSE_SPACE_FILEPATH );
		// set pause sprites
		_GAMEPAUSED.setTexture ( _data->resources.GetTexture ( "Game Paused Sprite" ) );
		_PRESSSPACETORESUME.setTexture ( _data->resources.GetTexture ( "Press Space Resume" ) );
		// set pause sprite positions
		_GAMEPAUSED.setPosition ( SCREEN_WIDTH / 2 - _GAMEPAUSED.getGlobalBounds().width / 2,
		                          SCREEN_HEIGHT / 2 - _GAMEPAUSED.getGlobalBounds().height );
		_PRESSSPACETORESUME.setPosition ( SCREEN_WIDTH / 2 - _PRESSSPACETORESUME.getGlobalBounds().width / 2,
		                                  SCREEN_HEIGHT / 2 );
	}

	void PauseGame::HandleInput()
	{
		sf::Event event;

		while ( _data->window.pollEvent ( event ) && event.type == sf::Event::KeyPressed )
		{
			if ( event.key.code == sf::Keyboard::Escape )
			{
				// if player presses escape in pause screen, close window
				_data->window.close();
			}

			else if ( event.key.code == sf::Keyboard::Enter )
			{
				// if player presses space in pause screen, resume game
				_data->statehandler.RemoveState();
			}
		}
	}

	void PauseGame::Update ( float dt )
	{
	}

	void PauseGame::Draw()
	{
		_data->window.clear();
		_data->window.draw ( _BACKGROUND );
		// draw background sprite with background texture loaded
		_data->window.draw ( _GAMEPAUSED );
		_data->window.draw ( _PRESSSPACETORESUME );
		// display updated data
		_data->window.display();
	}
} // namespace GameEngine
