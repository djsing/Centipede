#ifndef CENTIPEDELOGIC_H
#define CENTIPEDELOGIC_H

#include <memory>
#include "EntityLogic.h"
#include "Game.h"
#include "Centipede.h"

namespace GameEngine
{
	class CentipedeLogic: public EntityLogic
	{
	public:
		CentipedeLogic(DataPtr data, CentPtr centipede);
		// for centipede class, spawn() refers to spawning centipede segments
		void Spawn() override;
		// for centipede class, move() refers to centipede segments
		void Move(float dt) override;
		void MoveProjectiles(float dt){}
		// deletes centipede segments
		void CollisionHandle();

	private:
		DataPtr _data;
		CentPtr _centipede;
		float _speed;
		bool _isFirstSegment;
		// track initially spawned centipede segments
		unsigned int _numberOfCentipedeSegments;
	};
}

#endif