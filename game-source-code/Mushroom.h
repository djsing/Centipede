#ifndef MUSHROOM_H
#define MUSHROOM_H

#include <SFML/Graphics.hpp>
#include "Region.h"
#include "Game.h"

namespace GameEngine
{
	class Mushroom
	{
	public:
		Mushroom(DataPtr data, float xpos, float ypos, Region region, Region subregion);

		// Accessor functions
		sf::Sprite &GetMushroomSprite();
		float GetTopLeftXPosition();
		float GetTopLeftYPosition();
		Region GetRegion();
		Region GetSubRegion();
		float GetMushroomCenterXPosition();
		float GetMushroomCenterYPosition();

	private:
		DataPtr _data;
		sf::Sprite _mushroom;
		float _topLeftXPosition;
		float _topLeftYPosition;
		Region _region;
		Region _subregion;
		bool isPoisoned;
		bool isDead;
	};
}

#endif