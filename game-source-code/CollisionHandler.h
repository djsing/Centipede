#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Centipede.h"
#include "Game.h"
#include "GameField.h"
#include "Turret.h"

namespace GameEngine
{
	class CollisionHandler
	{
	public:
		CollisionHandler ( DataPtr data, TurretPtr turret, CentPtr centipede, FieldPtr field );
		void CheckCollisions();

	private:
		DataPtr data_;
		TurretPtr turret_;
		CentPtr centipede_;
		FieldPtr field_;
		void CheckBulletSegmentCollisions();
		void CheckSegmentMushroomCollisions();
		void CheckTurretSegmentCollisions();
		void CheckTurretSpiderCollisions();
		void CheckMushroomScorpionCollisions();
		void CheckMushroomSpiderCollisions();
		void CheckBulletSpiderCollisions();
		void CheckBulletMushroomCollisions();
		float CheckDistanceBetweenEntities ( Entity& entity1, Entity& entity2 );
	};

	using CollisionHandlerPtr = std::shared_ptr<CollisionHandler>;
} // namespace GameEngine

#endif
