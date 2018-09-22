#include "Entity.h"

namespace GameEngine
{
Entity::Entity(float topLeftXPosition, float topLeftYPosition)
    : _topLeftXPosition(topLeftXPosition)
    , _topLeftYPosition(topLeftYPosition)
    , _isDead(false)
{
}

sf::Sprite& Entity::GetObjectSprite()
{
    return _object;
}

void Entity::SetDirection(Direction direction)
{
    _direction = direction;
}

void Entity::SetTopLeftXPosition(float xpos)
{
    _topLeftXPosition = xpos;
}

void Entity::SetTopLeftYPosition(float ypos)
{
    _topLeftYPosition = ypos;
}

void Entity::SetRegion(Region region)
{
    _region = region;
}

void Entity::SetSubRegion(Region subregion)
{
    _subregion = subregion;
}

void Entity::SetDead(bool isDead)
{
    _isDead = isDead;
}

void Entity::SetCenterXPosition(float xpos)
{
    _centerXPosition = xpos;

    _regionHandler = RegionHandler{_centerXPosition, _centerYPosition};
    SetRegion(_regionHandler.GetRegion());
    SetSubRegion(_regionHandler.GetSubRegion());
}

void Entity::SetCenterYPosition(float ypos)
{
    _centerYPosition = ypos;

    _regionHandler = RegionHandler{_centerXPosition, _centerYPosition};
    SetRegion(_regionHandler.GetRegion());
    SetSubRegion(_regionHandler.GetSubRegion());
}

bool Entity::IsDead() const
{
    return _isDead;
}

Direction Entity::GetDirection() const
{
    return _direction;
}

Region Entity::GetRegion() const
{
    return _region;
}

Region Entity::GetSubRegion() const
{
    return _subregion;
}

float Entity::GetTopLeftXPosition() const
{
    return _topLeftXPosition;
}

float Entity::GetTopLeftYPosition() const
{
    return _topLeftYPosition;
}

float Entity::GetCenterXPosition() const
{
    return _centerXPosition;
}

float Entity::GetCenterYPosition() const
{
    return _centerYPosition;
}
} // namespace GameEngine