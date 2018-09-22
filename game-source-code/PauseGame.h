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

		void HandleInput() override;
		void Update(float dt) override;
		void Draw() override;

	private:
		DataPtr _data;
		sf::Sprite _GAMEPAUSED;
		sf::Sprite _PRESSSPACETORESUME;
	};
}

#endif