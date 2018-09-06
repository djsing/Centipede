#ifndef TURRETLOGIC_H
#define TURRETLOGIC_H

#include <memory>
#include "EntityLogic.h"
#include "Game.h"
#include "Turret.h"

namespace GameEngine
{
	class TurretLogic: public EntityLogic
	{
	public:
		TurretLogic(DataPtr data, TurretPtr turret);
		// for turret class, spawn() refers to spawning bullets
		void Spawn();
		// for turret class, move() refers to turret
		void Move(float dt);
		// for turret class, MoveProjectiles() refers to moving bullets
		void MoveProjectiles(float dt);
		void CollisionCheck();
		// deletes bullets, ends game if turret collides with deadly entity
		void CollisionHandle();

	private:
		DataPtr _data;
		TurretPtr _turret;
		float _speed;
	};

	typedef std::unique_ptr<TurretLogic> TurretLogicPtr;
}

#endif