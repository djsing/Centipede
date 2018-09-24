#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"
#include "Game.h"
#include "Region.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class Bullet : public Entity
	{
	public:
		Bullet ( float xpos, float ypos );

		// Mutator Functions
		void SetTopLeftXPosition ( float ypos );
		void SetTopLeftYPosition ( float ypos );
	};
} // namespace GameEngine

#endif
