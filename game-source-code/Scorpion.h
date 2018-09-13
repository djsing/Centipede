#ifndef SCORPION_H
#define SCORPION_H

#include "Entity.h"

namespace GameEngine
{
	class Scorpion: public Entity
	{
	public:
		Scorpion();
		void SetDirection(Direction direction);
		void SetTopLeftXPosition(float xpos);
		void SetTopLeftYPosition(float ypos);
		void SetRegion(Region region);
		void SetSubRegion(Region subregion);
		void SetDead(bool isDead);
	};
}

#endif