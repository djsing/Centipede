#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"

namespace GameEngine
{
	class MainMenu: public GameState
	{
	public:
		MainMenu(DataPtr data);

		void Initialise();
		void HandleInput();
		void Update(float dt);
		void Draw(float interpolation);

	private:
		DataPtr _data;
		sf::Sprite _background, _title, _playbutton;
	};

}
#endif