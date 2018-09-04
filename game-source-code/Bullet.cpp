#include "Bullet.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	Bullet::Bullet(DataPtr data, float xpos, float ypos):
	_data(data),
	_topLeftXPosition(xpos),
	_topLeftYPosition(ypos),
	_speed(500),
	_dead(false)
	{
		_bullet.setTexture(_data->resources.GetTexture("Bullet sprite"));
		_bullet.setPosition(_topLeftXPosition,_topLeftYPosition);
	}

	Bullet::~Bullet()
	{
		
	}

	bool Bullet::IsDead()
	{
		return _dead;
	}

	float Bullet::GetSpeed()
	{
		return _speed;
	}

	float Bullet::GetTopLeftXPosition()
	{
		return _topLeftXPosition;
	}

	float Bullet::GetTopLeftYPosition()
	{
		return _topLeftYPosition;
	}

	float Bullet::GetCenterXPosition()
	{
		return _topLeftXPosition + CENTIPEDE_SPRITE_SIDE_SIZE/2;
	}

	float Bullet::GetCenterYPosition()
	{
		return _topLeftYPosition + CENTIPEDE_SPRITE_SIDE_SIZE/2;
	}

	void Bullet::DrawBullet()
	{
		_data->window.draw(_bullet);
	}

	void Bullet::MoveBullet(float dt)
	{
		auto moveDistance = _speed*dt;
		// Check whether bullet is moving to the top  of screen
		if (_topLeftYPosition <= 0)
		{
			_topLeftYPosition = 0;
			_bullet.setPosition(_topLeftXPosition, _topLeftYPosition);
			_dead = true;
		}
		else
		{
			_bullet.move(0, -moveDistance);
			_topLeftYPosition -= moveDistance;
		}
	}
}