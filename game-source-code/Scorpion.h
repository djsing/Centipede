#ifndef SCORPION_H
#define SCORPION_H

#include "Entity.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class Scorpion: public Entity
	{
	public:
		Scorpion(DataPtr data);
		void SetTopLeftXPosition(float xpos);
		void SetTopLeftYPosition(float ypos);
		void SetRegion(Region region);
		void SetSubRegion(Region subregion);
		void SetDead(bool isDead);

	private:
		DataPtr _data;
	};
}

#endif