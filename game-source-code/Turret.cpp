#include "DEFINITIONS.h"
#include "Turret.h"

namespace GameEngine
{
Turret::Turret(DataPtr data)
    : Entity(SCREEN_WIDTH / 2 - TURRET_SPRITE_SIDE_SIZE / 2, SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE)
    , _data(data)
    , _livesRemaining(3)
{
    Entity::SetDirection(Direction::HOVER);
    Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + TURRET_SPRITE_SIDE_SIZE / 2);
    Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + TURRET_SPRITE_SIDE_SIZE / 2);
}

std::vector<Bullet>& Turret::GetBullets()
{
    return _bullets;
}

void Turret::SetTopLeftXPosition(float xpos)
{
    Entity::SetTopLeftXPosition(xpos);
    Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + TURRET_SPRITE_SIDE_SIZE / 2);
}

void Turret::SetTopLeftYPosition(float ypos)
{
    Entity::SetTopLeftYPosition(ypos);
    Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + TURRET_SPRITE_SIDE_SIZE / 2);
}

void Turret::DecrementLives()
{
    Entity::SetTopLeftXPosition(SCREEN_WIDTH / 2 - TURRET_SPRITE_SIDE_SIZE / 2);
    Entity::SetTopLeftYPosition(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
    Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + TURRET_SPRITE_SIDE_SIZE / 2);
    Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + TURRET_SPRITE_SIDE_SIZE / 2);
    _livesRemaining--;
}

float Turret::GetLastBulletYPosition()
{
    if(_bullets.empty())
	{
	    return GetTopLeftYPosition() - BULLET_HEIGHT;
	}
    return _bullets.back().GetTopLeftYPosition();
}

int Turret::GetLivesRemaining()
{
    return _livesRemaining;
}
} // namespace GameEngine