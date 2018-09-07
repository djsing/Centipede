#ifndef BULLET_H
#define BULLET_H

#include "Game.h"
#include "Region.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class Bullet
	{
	public:
		Bullet(DataPtr data, float xpos, float ypos);

		// Address Accessor Functions
		sf::Sprite &GetBullet();

		// Mutator Functions
		void SetDead(bool isDead);
		void SetYPosition(float ypos);
		void SetRegion(Region region);
		void SetSubRegion(Region subregion);

		// Accessor Functions
		bool IsDead();
		Region GetRegion();
		Region GetSubRegion();
		float GetTopLeftXPosition();
		float GetTopLeftYPosition();
		float GetCenterXPosition();
		float GetCenterYPosition();

	private:
		// pointer to GameData layer
		DataPtr _data;
		sf::Sprite _bullet;
		// position information
		float _topLeftXPosition;
		float _topLeftYPosition;
		Region _region;
		Region _subregion;
		// bullet characteristics
		float _speed;
		bool _dead;
	};
}

#endif