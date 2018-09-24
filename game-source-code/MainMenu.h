#ifndef MAINMENU_H
#define MAINMENU_H

#include "Game.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class MainMenu : public GameState
	{
	public:
		MainMenu ( DataPtr data );

		void HandleInput() override;
		void Update ( float dt ) override;
		void Draw() override;

	private:
		DataPtr data_;
		sf::Sprite background_;
		sf::Sprite title_;
		sf::Sprite subtitle_;
		sf::Sprite instructions_;
	};

} // namespace GameEngine
#endif
