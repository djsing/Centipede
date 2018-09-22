#include "DEFINITIONS.h"
#include "Direction.h"
#include "Mushroom.h"

namespace GameEngine
{
Mushroom::Mushroom(DataPtr data, float xpos, float ypos)
    : Entity(xpos, ypos)
    , _data(data)
    , _isPoisoned(false)
    , _livesRemaining(4)
{
    Entity::SetDirection(Direction::HOVER);
    Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + MUSHROOM_SPRITE_SIZE / 2);
    Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + MUSHROOM_SPRITE_SIZE / 2);
}

void Mushroom::SetPoisoned(bool isPoisoned)
{
    _isPoisoned = isPoisoned;
}

bool Mushroom::IsPoisoned()
{
    return _isPoisoned;
}

void Mushroom::DecrementLives()
{
    _livesRemaining--;
}

int Mushroom::GetLivesRemaining()
{
    return _livesRemaining;
}
} // namespace GameEngine