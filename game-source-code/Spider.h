#ifndef SPIDER_H
#define SPIDER_H

#include "Entity.h"

namespace GameEngine
{
	class Spider: public Entity
	{
	public:
		Spider();
		void SetDirection(Direction direction);
		void SetTopLeftXPosition(float xpos);
		void SetTopLeftYPosition(float ypos);
		void SetRegion(Region region);
		void SetSubRegion(Region subregion);
		void SetDead(bool isDead);
	};
}

#endif