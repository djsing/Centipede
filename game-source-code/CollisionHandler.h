#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Turret.h"
#include "Centipede.h"

namespace GameEngine
{
	class CollisionHandler
	{
	public:
		CollisionHandler(TurretPtr turret, CentPtr centipede);
		void CheckBulletCollisions();
		void CheckCentipedeSegmentCollisions();
		float CheckDistanceBetweenBulletsAndSegments();
	private:
		TurretPtr _turret;
		CentPtr _centipede;
	};

	typedef std::shared_ptr<CollisionHandler> CollisionHandlerPtr;
}

#endif