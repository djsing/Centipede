#include "DEFINITIONS.h"
#include "GamePlay.h"
#include "GameWon.h"

namespace GameEngine
{
	GameWon::GameWon ( DataPtr data )
		: data_ ( data )
	{
		data_->resources.LoadTexture ( "Game Win Sprite", GAME_WON );
		data_->resources.LoadTexture ( "Press F12 Restart", GAME_WIN_RESTART_FILEPATH );

		game_won_.setTexture ( data_->resources.GetTexture ( "Game Win Sprite" ) );
		press_f12_to_restart_.setTexture ( data_->resources.GetTexture ( "Press F12 Restart" ) );

		game_won_.setPosition ( SCREEN_WIDTH / 2 - game_won_.getGlobalBounds().width / 2,
		                       SCREEN_HEIGHT / 2 - game_won_.getGlobalBounds().height );

		press_f12_to_restart_.setPosition ( SCREEN_WIDTH / 2 - press_f12_to_restart_.getGlobalBounds().width / 2,
		                                 SCREEN_HEIGHT / 2 );
	}

	void GameWon::HandleInput()
	{
		sf::Event event;

		while ( data_->window.pollEvent ( event ) && event.type == sf::Event::KeyPressed )
		{
			if ( event.key.code == sf::Keyboard::Escape )
			{
				data_->window.close();
			}

			if ( event.key.code == sf::Keyboard::F12 )
			{
				// if player presses space after winning, start a new instance of the game
				data_->lives.ResetLives();
				data_->statehandler.AddState ( StatePtr ( new GamePlay ( data_ ) ) );
			}
		}
	}

	void GameWon::Update ( float dt )
	{
	}

	void GameWon::Draw()
	{
		// clear screen to update data
		data_->window.clear();
		data_->window.draw ( game_won_ );
		data_->window.draw ( press_f12_to_restart_ );
		// display updated data
		data_->window.display();
	}
} // namespace GameEngine
