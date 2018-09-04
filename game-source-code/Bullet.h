#ifndef BULLET_H
#define BULLET_H

#include "Game.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class Bullet
	{
	public:
		Bullet(DataPtr data, float xpos, float ypos);
		bool IsDead();
		float GetSpeed();
		float GetTopLeftXPosition();
		float GetTopLeftYPosition();
		float GetCenterXPosition();
		float GetCenterYPosition();
		void DrawBullet();
		void MoveBullet(float dt);
	private:
		DataPtr _data;
		sf::Sprite _bullet;
		float _topLeftXPosition;
		float _topLeftYPosition;
		float _speed;
		bool _dead;
	};
}

#endif