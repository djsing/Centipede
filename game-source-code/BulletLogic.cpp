#include "BulletLogic.h"
#include "DEFINITIONS.h"
#include "RegionHandler.h"

namespace GameEngine
{
	BulletLogic::BulletLogic(Bullet &bullet):
	_bullet(bullet),
	_speed(BULLET_SPEED)
	{
		
	}

	void BulletLogic::Move(float dt)
	{
		auto moveDistance = _speed*dt;
		// Check whether bullet is moving to the top  of screen
		if (_bullet.GetTopLeftYPosition() <= 0)
		{
			_bullet.SetDead(true);
		}
		else
		{
			_bullet.SetTopLeftYPosition(_bullet.GetTopLeftYPosition() - moveDistance);
		}
	}
}