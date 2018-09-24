#ifndef BULLETLOGIC_H
#define BULLETLOGIC_H

#include "Bullet.h"
#include "EntityLogic.h"
#include "Game.h"
#include <memory>

namespace GameEngine
{
	class BulletLogic : public EntityLogic
	{
	public:
		BulletLogic ( std::vector<Bullet>& bullets );
		void Spawn() override;
		// for Bullet class, move() refers to moving the bullet
		void Move ( float dt ) override;
		void MoveProjectiles ( float dt ) override;
		void CollisionHandle() override;

	private:
		std::vector<Bullet>& bullets_;
		float speed_;
	};

	using BulletLogicPtr = std::unique_ptr<BulletLogic>;
} // namespace GameEngine

#endif
