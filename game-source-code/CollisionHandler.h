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
		void CheckTurretSegmentCollisions();
	private:
		DataPtr _data;
		TurretPtr _turret;
		CentPtr _centipede;
		FieldPtr _field;
		float CheckDistanceBetweenEntities(Entity &entity1, Entity &entity2);
	};

	typedef std::shared_ptr<CollisionHandler> CollisionHandlerPtr;
}

#endif