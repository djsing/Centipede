#ifndef PAUSEGAME_H
#define PAUSEGAME_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"

namespace GameEngine
{
	class PauseGame: public GameState
	{
	public:
		PauseGame(DataPtr data);

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