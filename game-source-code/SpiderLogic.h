#ifndef SPIDERLOGIC_H
#define SPIDERLOGIC_H

#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
	class SpiderLogic : public EntityLogic
	{
	public:
		SpiderLogic ( FieldPtr field );
		void Spawn() override;
		void Move ( float dt ) override;
		void MoveProjectiles ( float dt )
		{
		}
		void CollisionHandle() override;

	private:
		FieldPtr _field;
		float _totalTimePerMovement;
		float _speed;
		int _angle;
	};
} // namespace GameEngine

#endif
