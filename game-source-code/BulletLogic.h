#ifndef BULLETLOGIC_H
#define BULLETLOGIC_H

#include <memory>
#include "EntityLogic.h"
#include "Game.h"
#include "Bullet.h"

namespace GameEngine
{
	class BulletLogic: public EntityLogic
	{
	public:
		BulletLogic(Bullet &bullet);
		// for Bullet class, spawn() is empty
		void Spawn(){}
		// for Bullet class, move() refers to moving the bullet
		void Move(float dt);
		// for Bullet class, MoveProjectiles() is empty
		void MoveProjectiles(float dt){}
		void CollisionCheck();
		// deletes Bullets
		void CollisionHandle();

	private:
		Bullet &_bullet;
		float _speed;
		void UpdateRegion();
	};

	typedef std::unique_ptr<BulletLogic> BulletLogicPtr;
}

#endif