#ifndef MUSHROOMLOGIC_H
#define MUSHROOMLOGIC_H

#include "Game.h"
#include "EntityLogic.h"
#include "Mushroom.h"
#include "GameField.h"
#include <vector>

namespace GameEngine
{
	class MushroomLogic: public EntityLogic
	{
	public:
		MushroomLogic(FieldPtr field, DataPtr data);
		void Spawn();
		void Move(float dt){}
		void MoveProjectiles(float dt){}
		void CollisionHandle(); // yet to implement
		
	private:
		DataPtr _data;
		FieldPtr _field;
	};

	typedef std::unique_ptr<MushroomLogic> MushLogicPtr;
}

#endif