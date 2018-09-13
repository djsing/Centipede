#ifndef SCORPIONLOGIC_H
#define SCORPIONLOGIC_H

#include "EntityLogic.h"
#include "GameField.h"

namespace GameEngine
{
	class ScorpionLogic: public EntityLogic
	{
	public:
		ScorpionLogic(FieldPtr field);
		void Spawn() override;
		void Move(float dt) override;
		void MoveProjectiles(float dt){}
		void CollisionHandle() override;
	private:
		FieldPtr _field;
	};
}

#endif