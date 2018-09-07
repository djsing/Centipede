#include "Bullet.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	Bullet::Bullet(DataPtr data, float xpos, float ypos):
	_data(data),
	_topLeftXPosition(xpos),
	_topLeftYPosition(ypos),
	_speed(BULLET_SPEED),
	_dead(false)
	{
		_bullet.setTexture(_data->resources.GetTexture("Bullet sprite"));
		_bullet.setPosition(_topLeftXPosition,_topLeftYPosition);
	}

	void Bullet::SetDead(bool isDead)
	{
		_dead = isDead;
	}

	void Bullet::SetYPosition(float ypos)
	{
		_topLeftYPosition = ypos;
	}


	void Bullet::SetRegion(Region region)
	{
		_region = region;
	}

	void Bullet::SetSubRegion(Region subregion)
	{
		_subregion = subregion;
	}

	sf::Sprite &Bullet::GetBullet()
	{
		return _bullet;
	}

	bool Bullet::IsDead()
	{
		return _dead;
	}

	Region Bullet::GetRegion()
	{
		return _region;
	}

	Region Bullet::GetSubRegion()
	{
		return _subregion;
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
}