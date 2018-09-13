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
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + BULLET_WIDTH/2);
	}

	void Bullet::SetDead(bool isDead)
	{
		Entity::SetDead(isDead);
	}

	void Bullet::SetTopLeftYPosition(float ypos)
	{
		Entity::SetTopLeftYPosition(ypos);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + BULLET_HEIGHT/2);
	}

	sf::Sprite &Bullet::GetBullet()
	{
		return _bullet;
	}
}