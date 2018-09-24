#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Game.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class GameOver : public GameState
	{
	public:
		GameOver ( DataPtr data );

		void HandleInput() override;
		void Update ( float dt ) override;
		void Draw() override;

	private:
		DataPtr data_;
		sf::Sprite game_over_;
		sf::Sprite press_f12_to_restart_;
	};
} // namespace GameEngine
#endif
