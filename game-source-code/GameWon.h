#ifndef GAMEWON_H
#define GAMEWON_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"

namespace GameEngine
{
	class GameWon: public GameState
	{
	public:
		GameWon(DataPtr data);

		void HandleInput() override;
		void Update(float dt) override;
		void Draw() override;

	private:
		DataPtr _data;
		sf::Sprite _background;
		sf::Sprite _gameWon;
		sf::Sprite _pressF12ToRestart;
	};
}

#endif