#ifndef SPIDER_H
#define SPIDER_H

#include "Entity.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class Spider : public Entity
	{
	public:
		Spider();
		void SetTopLeftXPosition ( float xpos );
		void SetTopLeftYPosition ( float ypos );
	};
} // namespace GameEngine

#endif
