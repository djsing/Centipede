#ifndef ENTITYLOGIC_H
#define ENTITYLOGIC_H

namespace GameEngine
{
	class EntityLogic
	{
	public:
		virtual void Spawn() = 0;
		virtual void Move(float dt) = 0;
		virtual void MoveProjectiles(float dt) = 0;
		virtual void CollisionCheck() = 0;
		virtual void CollisionHandle() = 0;
	};
}

#endif