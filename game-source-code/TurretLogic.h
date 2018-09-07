#ifndef TURRETLOGIC_H
#define TURRETLOGIC_H

#include <memory>
#include "EntityLogic.h"
#include "Game.h"
#include "Turret.h"
#include "BulletLogic.h"

namespace GameEngine
{
	class TurretLogic: public EntityLogic
	{
	public:
		TurretLogic(DataPtr data, TurretPtr turret);
		// for turret class, spawn() refers to spawning bullets
		void Spawn();
		// for turret class, move() refers to turret movement
		void Move(float dt);
		// for turret class, MoveProjectiles() refers to moving bullets
		void MoveProjectiles(float dt);
		// deletes dead bullets, ends game if turret collides with deadly entity
		void CollisionHandle();	// incomplete

	private:
		DataPtr _data;
		TurretPtr _turret;
		BulletLogicPtr _bulletLogic;
		float _speed;
	};

	typedef std::unique_ptr<TurretLogic> TurretLogicPtr;
}

#endif