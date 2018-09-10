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
		void Spawn(){}
		// for Bullet class, move() refers to moving the bullet
		void Move(float dt) override;
		void MoveProjectiles(float dt){}
		void CollisionHandle(){}

	private:
		Bullet &_bullet;
		float _speed;
	};

	typedef std::unique_ptr<BulletLogic> BulletLogicPtr;
}

#endif