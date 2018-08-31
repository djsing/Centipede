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
		void Draw(float interpolation);

	private:
		DataPtr _data;
		sf::Sprite _background;
	};
}
#endif