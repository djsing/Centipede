#ifndef MUSHROOM_H
#define MUSHROOM_H

#include <SFML/Graphics.hpp>
#include "Region.h"
#include "Game.h"
#include "Entity.h"

namespace GameEngine
{
	class Mushroom: public Entity
	{
	public:
		Mushroom(DataPtr data, float xpos, float ypos);

		// Address Accessor functions
		sf::Sprite &GetMushroomSprite();

	private:
		DataPtr _data;
		sf::Sprite _mushroom;
		bool _isPoisoned;
	};
}

#endif