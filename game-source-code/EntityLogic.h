#ifndef ENTITYLOGIC_H
#define ENTITYLOGIC_H

#include <vector>

namespace GameEngine
{
	class EntityLogic
	{
	public:
		// All game states should have its own declaration of the following functions
		virtual void Spawn() = 0;
		virtual void Move(float dt) = 0;
		virtual void MoveProjectiles(float dt) = 0;
		virtual void CollisionCheck() = 0;
		virtual void CollisionHandle() = 0;
	};
}

#endif