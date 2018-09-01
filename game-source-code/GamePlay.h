#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"
#include "Centipede.h"

namespace GameEngine
{
	class GamePlay: public GameState
	{
	public:
		GamePlay(DataPtr data);

		void Initialise();
		void HandleInput();
		void Update(float dt);
		void Draw(float interpolation);

	private:
		DataPtr _data;
		sf::Sprite _background;
		Centipede *_centipede;
	};

}

#endif