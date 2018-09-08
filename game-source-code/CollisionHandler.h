#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Game.h"
#include "Turret.h"
#include "Centipede.h"
#include "GameField.h"

namespace GameEngine
{
	class CollisionHandler
	{
	public:
		CollisionHandler(DataPtr data, TurretPtr turret, CentPtr centipede, FieldPtr field);
		void CheckBulletSegmentCollisions();
		void CheckSegmentMushroomCollisions();
	private:
		DataPtr _data;
		TurretPtr _turret;
		CentPtr _centipede;
		FieldPtr _field;
		float CheckDistanceBetweenBulletsAndSegments(unsigned int bulletIndex, 
			unsigned int centipedeSegmentIndex);
		float CheckDistanceBetweenSegmentsAndMushrooms(unsigned int mushroomIndex, 
			unsigned int centipedeSegmentIndex);
	};

	typedef std::shared_ptr<CollisionHandler> CollisionHandlerPtr;
}

#endif