#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Turret.h"
#include "Centipede.h"

namespace GameEngine
{
	class CollisionHandler
	{
	public:
		CollisionHandler();
		void CheckBulletCollisions(Turret *turret);
		void CheckCentipedeSegmentCollisions(Centipede *Centipede);
	};
}

#endif