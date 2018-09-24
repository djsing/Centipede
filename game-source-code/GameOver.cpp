#include "DEFINITIONS.h"
#include "GameOver.h"
#include "GamePlay.h"

namespace GameEngine
{
	GameOver::GameOver ( DataPtr data )
		: data_ ( data )
	{
		data_->resources.LoadTexture ( "Game Over Sprite", GAME_OVER_FILEPATH );
		data_->resources.LoadTexture ( "Press F12 Restart", GAME_OVER_RESTART_FILEPATH );

		game_over_.setTexture ( data_->resources.GetTexture ( "Game Over Sprite" ) );
		press_f12_to_restart_.setTexture ( data_->resources.GetTexture ( "Press F12 Restart" ) );

		game_over_.setPosition ( SCREEN_WIDTH / 2 - game_over_.getGlobalBounds().width / 2,
		                        SCREEN_HEIGHT / 2 - game_over_.getGlobalBounds().height );

		press_f12_to_restart_.setPosition ( SCREEN_WIDTH / 2 - press_f12_to_restart_.getGlobalBounds().width / 2,
		                                 SCREEN_HEIGHT / 2 );
	}

	void GameOver::HandleInput()
	{
		sf::Event event;

		while ( data_->window.pollEvent ( event ) && event.type == sf::Event::KeyPressed )
		{
			if ( event.key.code == sf::Keyboard::Escape )
			{
				data_->window.close();
			}

			else if ( event.key.code == sf::Keyboard::F12 )
			{
				// if player presses f12 after losing, start a new instance of the game
				data_->lives.ResetLives();
				data_->statehandler.AddState ( StatePtr ( new GamePlay ( data_ ) ) );
			}
		}
	}

	void GameOver::Update ( float dt )
	{
	}

	void GameOver::Draw()
	{
		// clear screen to update data
		data_->window.clear();
		data_->window.draw ( game_over_ );
		data_->window.draw ( press_f12_to_restart_ );
		// display updated data
		data_->window.display();
	}
} // namespace GameEngine
