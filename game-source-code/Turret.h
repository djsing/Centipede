#ifndef TURRET_H
#define TURRET_H

#include "Game.h"
#include "Direction.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class Turret
	{
	public:
		Turret(DataPtr data);
		float GetSpeed();
		Direction GetDirection();
		float GetTopLeftXPosition();
		float GetTopLeftYPosition();
		float GetCenterXPosition();
		float GetCenterYPosition();
		void DrawTurret();
		void MoveTurret(float dt);
	private:
		DataPtr _data;
		sf::Sprite _turret;
		Direction _direction;
		float _topLeftXPosition;
		float _topLeftYPosition;
		float _speed;
	};
}

#endif