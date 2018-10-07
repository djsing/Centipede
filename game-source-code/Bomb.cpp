#include "Bomb.h"
#include "DEFINITIONS.h"
#include "Direction.h"

namespace GameEngine
{
Bomb::Bomb(float xpos, float ypos) : Entity(xpos, ypos)
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
}  // namespace GameEngine