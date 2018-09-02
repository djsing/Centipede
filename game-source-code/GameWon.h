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

		void Initialise();
		void HandleInput();
		void Update(float dt);
		void Draw();

	private:
		DataPtr _data;
		sf::Sprite _background;
	};
}

#endif