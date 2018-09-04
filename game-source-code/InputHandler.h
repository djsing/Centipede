#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Game.h"
#include "Direction.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class InputHandler
	{
	public:
		InputHandler(DataPtr data);
		void SetControls(sf::Event event);
		bool IsShooting();
	private:
		DataPtr _data;
		bool _isShooting;
		Direction _direction;
	};
}

#endif