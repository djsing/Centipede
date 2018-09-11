#ifndef BULLET_H
#define BULLET_H

#include "Game.h"
#include "Region.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class Bullet: public Entity
	{
	public:
		Bullet(DataPtr data, float xpos, float ypos);

		// Address Accessor Functions
		sf::Sprite &GetBullet();

		// Mutator Functions
		void SetDead(bool isDead);
		void SetTopLeftYPosition(float ypos);

		// Accessor Functions
		float GetCenterXPosition();
		float GetCenterYPosition();

	private:
		// pointer to GameData layer
		DataPtr _data;
		sf::Sprite _bullet;
		// bullet characteristics
		float _speed;
	};
}

#endif