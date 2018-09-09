#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"

namespace GameEngine
{
	class GameOver: public GameState
	{
	public:
		GameOver(DataPtr data);

		void Initialise();
		void HandleInput();
		void Update(float dt);
		void Draw();

	private:
		DataPtr _data;
		sf::Sprite _background;
		sf::Sprite _gameOver;
		sf::Sprite _pressF12ToRestart;
	};
}
#endif