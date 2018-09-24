#ifndef PAUSEGAME_H
#define PAUSEGAME_H

#include "Game.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class PauseGame : public GameState
	{
	public:
		PauseGame ( DataPtr data );

		void HandleInput() override;
		void Update ( float dt ) override;
		void Draw() override;

	private:
		DataPtr _data;
		sf::Sprite _GAMEPAUSED;
		sf::Sprite _PRESSSPACETORESUME;
		sf::Sprite _BACKGROUND;
		sf::Texture _resumeBackground;
	};
} // namespace GameEngine

#endif
