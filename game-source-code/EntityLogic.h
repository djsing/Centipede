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
		virtual void CollisionHandle() = 0;
	};
	typedef std::unique_ptr<EntityLogic> LogicPtr;
}

#endif