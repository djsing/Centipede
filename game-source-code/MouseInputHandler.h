#ifndef MOUSEINPUTHANDLER_H
#define MOUSEINPUTHANDLER_H

#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class MouseInputHandler
	{
	public:
		MouseInputHandler(){}
		~MouseInputHandler(){}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, 
		sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}

#endif