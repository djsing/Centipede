#include "BulletLogic.h"
#include "DEFINITIONS.h"
#include "RegionHandler.h"

namespace GameEngine
{
BulletLogic::BulletLogic(std::vector<Bullet>& bullets)
    : _bullets(bullets)
    , _speed(BULLET_SPEED)
{
}

void BulletLogic::Spawn()
{
}

void BulletLogic::Move(float dt)
{
    auto moveDistance = _speed * dt;
    for(unsigned int i = 0; i < _bullets.size(); i++)
	{
	    // Check whether bullet is moving to the top  of screen
	    if(_bullets.at(i).GetTopLeftYPosition() <= 0)
		{
		    _bullets.at(i).SetDead(true);
		}
	    else
		{
		    _bullets.at(i).SetTopLeftYPosition(_bullets.at(i).GetTopLeftYPosition() - moveDistance);
		}
	}
}

void BulletLogic::MoveProjectiles(float dt)
{
}

void BulletLogic::CollisionHandle()
{
    // delete collided bullets
    for(unsigned int i = 0; i < _bullets.size(); i++)
	{
	    if(_bullets.at(i).IsDead())
		{
		    _bullets.erase(_bullets.begin() + i);
		    i--;
		}
	}
}
} // namespace GameEngine