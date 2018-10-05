#include "Bomb.h"
#include "DEFINITIONS.h"
#include "Direction.h"

namespace GameEngine
{
Bomb::Bomb(float xpos, float ypos) : Entity(xpos, ypos), is_exploding_(false)
{
    Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + BOMB_SPRITE_SIZE / 2);
    Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + BOMB_SPRITE_SIZE / 2);
    Entity::SetDirection(Direction::HOVER);
}

void Bomb::SetTopLeftXPosition(float xpos)
{
    Entity::SetTopLeftXPosition(xpos);
    Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + BOMB_SPRITE_SIZE / 2);
}

void Bomb::SetTopLeftYPosition(float ypos)
{
    Entity::SetTopLeftYPosition(ypos);
    Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + BOMB_SPRITE_SIZE / 2);
}

void Bomb::Explode()
{
    Entity::SetDead(true);
    is_exploding_ = true;
}

bool Bomb::IsTriggered()
{
    return is_exploding_;
}
}  // namespace GameEngine