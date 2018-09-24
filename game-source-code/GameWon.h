#ifndef GAMEWON_H
#define GAMEWON_H

#include "Game.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class GameWon : public GameState
	{
	public:
		GameWon ( DataPtr data );

		void HandleInput() override;
		void Update ( float dt ) override;
		void Draw() override;

	private:
		DataPtr data_;
		sf::Sprite background_;
		sf::Sprite game_won_;
		sf::Sprite press_f12_to_restart_;
	};
} // namespace GameEngine

#endif
