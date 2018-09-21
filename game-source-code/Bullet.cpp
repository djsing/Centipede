#include "Bullet.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	Bullet::Bullet(DataPtr data, float xpos, float ypos):
	Entity(xpos, ypos),
	_data(data)
	{
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + BULLET_WIDTH/2);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + BULLET_HEIGHT/2);
		Entity::SetDirection(Direction::UP);
	}

	void Bullet::SetDead(bool isDead)
	{
		Entity::SetDead(isDead);
	}

	void Bullet::SetTopLeftXPosition(float ypos)
	{
		Entity::SetTopLeftXPosition(ypos);
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + BULLET_WIDTH/2);
	}

	void Bullet::SetTopLeftYPosition(float ypos)
	{
		Entity::SetTopLeftYPosition(ypos);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + BULLET_HEIGHT/2);
	}
}