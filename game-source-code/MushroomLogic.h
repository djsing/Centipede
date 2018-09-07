#ifndef MUSHROOMLOGIC_H
#define MUSHROOMLOGIC_H

#include "EntityLogic.h"
#include "Mushroom.h"
#include "GameField.h"
#include <vector>

namespace GameEngine
{
	class MushroomLogic: public EntityLogic
	{
	public:
		MushroomLogic(FieldPtr field);
		void Spawn(){}
		void Move(float dt){}
		void MoveProjectiles(float dt){}
		void CollisionHandle();
		
	private:
		FieldPtr _field;
	};
}

#endif