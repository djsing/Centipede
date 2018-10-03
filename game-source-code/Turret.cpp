#include "DEFINITIONS.h"
#include "Turret.h"

namespace GameEngine
{
Turret::Turret() : Entity(SCREEN_WIDTH / 2 - TURRET_SPRITE_SIDE_SIZE / 2, SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE)
{
    Entity::SetDirection(Direction::HOVER);
    Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + TURRET_SPRITE_SIDE_SIZE / 2);
    Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + TURRET_SPRITE_SIDE_SIZE / 2);
}

std::vector<Bullet>& Turret::GetBullets()
{
    return bullets_;
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

float Turret::GetLastBulletYPosition()
{
    if(bullets_.empty())
	{
	    return GetTopLeftYPosition() - BULLET_HEIGHT;
	}

    return bullets_.back().GetTopLeftYPosition();
}
}  // namespace GameEngine
