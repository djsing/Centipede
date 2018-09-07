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
		void Spawn();
		// for centipede class, move() refers to centipede segments
		void Move(float dt);
		// for centipede class, MoveProjectiles() is empty
		void MoveProjectiles(float dt){}
		void CollisionCheck();
		// deletes centipede segments
		void CollisionHandle();

	private:
		DataPtr _data;
		CentPtr _centipede;
		float _speed;
		bool _isFirstSegment;
		void UpdateRegion(unsigned int i);
	};

	typedef std::unique_ptr<CentipedeLogic> CentLogicPtr;
}

#endif