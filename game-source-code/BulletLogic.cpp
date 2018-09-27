#include "BulletLogic.h"
#include "DEFINITIONS.h"
#include "RegionHandler.h"

namespace GameEngine
{
BulletLogic::BulletLogic(std::vector<Bullet>& bullets) : bullets_(bullets), speed_(BULLET_SPEED)
{
}

void BulletLogic::Spawn()
{
}

void BulletLogic::Move(float dt)
{
    auto moveDistance = speed_ * dt;

    for(auto& i : bullets_)
	{
	    // Check whether bullet is moving to the top  of screen
	    if(i.GetTopLeftYPosition() <= SCREEN_TOP)
		{
		    i.SetDead(true);
		}

	    else
		{
		    i.SetTopLeftYPosition(i.GetTopLeftYPosition() - moveDistance);
		}
	}
}

void BulletLogic::CollisionHandle()
{
    // delete dead bullets
    if(!bullets_.empty())
	{
	    auto deadBegin = std::remove(bullets_.begin(), bullets_.end(), true);
	    bullets_.erase(deadBegin, bullets_.end());
	}
}
}  // namespace GameEngine
