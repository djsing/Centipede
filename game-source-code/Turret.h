#ifndef TURRET_H
#define TURRET_H

#include "Game.h"
#include "Bullet.h"
#include "Direction.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

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
		float GetLastBulletYPosition();
		void DrawTurret();
		void MoveTurret(float dt);
		void SpawnBullets();
		void DrawBullets();
		void MoveBullets(float dt);
		void DestroyBullets();

	private:
		DataPtr _data;
		sf::Sprite _turret;
		Direction _direction;
		float _topLeftXPosition;
		float _topLeftYPosition;
		float _speed;
		std::vector<Bullet> _bullets;
	};

	typedef std::shared_ptr<Turret> TurretPtr;
}

#endif