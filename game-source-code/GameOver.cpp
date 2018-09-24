#include "DEFINITIONS.h"
#include "GameOver.h"
#include "GamePlay.h"

namespace GameEngine
{
	GameOver::GameOver ( DataPtr data )
		: _data ( data )
	{
		//_data->resources.LoadTexture("Game Over Screen Background", GAME_OVER_BACKGROUND_FILEPATH);
		//_background.setTexture(_data->resources.GetTexture("Game Over Screen Background"));
		_data->resources.LoadTexture ( "Game Over Sprite", GAME_OVER_FILEPATH );
		_data->resources.LoadTexture ( "Press F12 Restart", GAME_OVER_RESTART_FILEPATH );

		_gameOver.setTexture ( _data->resources.GetTexture ( "Game Over Sprite" ) );
		_pressF12ToRestart.setTexture ( _data->resources.GetTexture ( "Press F12 Restart" ) );

		_gameOver.setPosition ( SCREEN_WIDTH / 2 - _gameOver.getGlobalBounds().width / 2,
		                        SCREEN_HEIGHT / 2 - _gameOver.getGlobalBounds().height );

		_pressF12ToRestart.setPosition ( SCREEN_WIDTH / 2 - _pressF12ToRestart.getGlobalBounds().width / 2,
		                                 SCREEN_HEIGHT / 2 );
	}

	void GameOver::HandleInput()
	{
		sf::Event event;

		while ( _data->window.pollEvent ( event ) && event.type == sf::Event::KeyPressed )
		{
			if ( event.key.code == sf::Keyboard::Escape )
			{
				_data->window.close();
			}

			else if ( event.key.code == sf::Keyboard::F12 )
			{
				// if player presses f12 after losing, start a new instance of the game
				_data->lives.ResetLives();
				_data->statehandler.AddState ( StatePtr ( new GamePlay ( _data ) ) );
			}
		}
	}

	void GameOver::Update ( float dt )
	{
	}

	void GameOver::Draw()
	{
		// clear screen to update data
		_data->window.clear();
		// draw background sprite with background texture loaded
		//_data->window.draw(_background);
		_data->window.draw ( _gameOver );
		_data->window.draw ( _pressF12ToRestart );
		// display updated data
		_data->window.display();
	}
} // namespace GameEngine
