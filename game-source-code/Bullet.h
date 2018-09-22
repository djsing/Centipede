#ifndef BULLET_H
#define BULLET_H

#include "Game.h"
#include "Region.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class Bullet: public Entity
	{
	public:
		Bullet(DataPtr data, float xpos, float ypos);

		// Mutator Functions
		void SetTopLeftXPosition(float ypos);
		void SetTopLeftYPosition(float ypos);

	private:
		// pointer to GameData layer
		DataPtr _data;
	};
}

#endif