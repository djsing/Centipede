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

		// Address Accessor functions
		sf::Sprite &GetTurretSprite();
		std::vector<Bullet> &GetBullets();

		// Mutator functions
		void SetSpritePosition(float xpos, float ypos);
		void SetTopLeftXPosition(float xpos);
		void SetTopLeftYPosition(float ypos);

		// Accessor functions
		Direction GetDirection();
		float GetTopLeftXPosition();
		float GetTopLeftYPosition();
		float GetCenterXPosition();
		float GetCenterYPosition();
		float GetLastBulletYPosition();

	private:
		// Data layer pointer
		DataPtr _data;
		// Turret sprite
		sf::Sprite _turret;
		// Turret Position/Movement Attributes
		Direction _direction;
		float _topLeftXPosition;
		float _topLeftYPosition;
		// Container to store all visible bullets
		std::vector<Bullet> _bullets;
	};

	// Shared pointer to a Turret Object
	typedef std::shared_ptr<Turret> TurretPtr;
}

#endif