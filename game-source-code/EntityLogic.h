#ifndef ENTITYLOGIC_H
#define ENTITYLOGIC_H

#include <memory>

namespace GameEngine
{
	class EntityLogic
	{
	public:
		virtual void Spawn() = 0;
		virtual void Move ( float dt ) = 0;
		virtual void CollisionHandle() = 0;
	};
	using LogicPtr = std::unique_ptr<EntityLogic>;
} // namespace GameEngine

#endif
