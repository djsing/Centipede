#include "Bullet.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	Bullet::Bullet(DataPtr data, float xpos, float ypos):
	Entity(Direction::UP, xpos, ypos),
	_data(data),
	_speed(BULLET_SPEED)
	{
		_bullet.setTexture(_data->resources.GetTexture("Bullet sprite"));
		_bullet.setPosition(Entity::GetTopLeftXPosition(), Entity::GetTopLeftYPosition());
	}

	void Bullet::SetDead(bool isDead)
	{
		Entity::SetDead(isDead);
	}

	void Bullet::SetTopLeftYPosition(float ypos)
	{
		Entity::SetTopLeftYPosition(ypos);
	}

	sf::Sprite &Bullet::GetBullet()
	{
		return _bullet;
	}

	float Bullet::GetCenterXPosition()
	{
		return Entity::GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE/2;
	}

	float Bullet::GetCenterYPosition()
	{
		return Entity::GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE/2;
	}
}