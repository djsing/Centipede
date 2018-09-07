#include "BulletLogic.h"
#include "DEFINITIONS.h"

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
			_bullet.GetBullet().move(0, -moveDistance);
			_bullet.SetYPosition(_bullet.GetTopLeftYPosition() - moveDistance);
		}
		// Update the bullet's region after it has moved - prepare for collision checking
		UpdateRegion();
	}

	void BulletLogic::CollisionCheck()
	{
		
	}

	void BulletLogic::CollisionHandle()
	{
		
	}

	void BulletLogic::UpdateRegion()
	{
		// left side of screen
		if (_bullet.GetTopLeftXPosition() <= (SCREEN_WIDTH/2 - BULLET_WIDTH))
		{
			// top half of screen
			if (_bullet.GetTopLeftYPosition() <= (SCREEN_HEIGHT/2 - BULLET_HEIGHT))
			{
				_bullet.SetRegion(Region::TOP_LEFT);
				// left side of top left quarter
				if (_bullet.GetTopLeftXPosition() <= (SCREEN_WIDTH/4 - BULLET_WIDTH))
				{
					// top half of left quarter
					if (_bullet.GetTopLeftYPosition() <= (SCREEN_HEIGHT/4 - BULLET_HEIGHT))
					{
						_bullet.SetSubRegion(Region::TOP_LEFT);
					}
					// bottom half of left quarter
					else
					{
						_bullet.SetSubRegion(Region::BOTTOM_LEFT);
					}
				}
				// right side of top left quarter
				else
				{
					// top half of left quarter
					if (_bullet.GetTopLeftYPosition() <= (SCREEN_HEIGHT/4 - BULLET_HEIGHT))
					{
						_bullet.SetSubRegion(Region::TOP_RIGHT);
					}
					// bottom half of left quarter
					else
					{
						_bullet.SetSubRegion(Region::BOTTOM_RIGHT);
					}
				}
			}
			// bottom half of screen
			else
			{
				_bullet.SetRegion(Region::BOTTOM_LEFT);
				// left half of bottom left quarter
				if (_bullet.GetTopLeftXPosition() <= (SCREEN_WIDTH/4 - BULLET_WIDTH))
				{
					// top half of bottom left quarter
					if (_bullet.GetTopLeftYPosition() <= (SCREEN_HEIGHT*3/4 - BULLET_HEIGHT))
					{
						_bullet.SetSubRegion(Region::TOP_LEFT);
					}
					// bottom half of bottom left quarter
					else
					{
						_bullet.SetSubRegion(Region::BOTTOM_LEFT);
					}
				}
				// right half of bottom left quarter
				else
				{
					// top half of left quarter
					if (_bullet.GetTopLeftYPosition() <= (SCREEN_HEIGHT*3/4 - BULLET_HEIGHT))
					{
						_bullet.SetSubRegion(Region::TOP_RIGHT);
					}
					// bottom half of left quarter
					else
					{
						_bullet.SetSubRegion(Region::BOTTOM_RIGHT);
					}
				}
			}
		}
		// right side of screen
		else
		{
			// top half of screen
			if (_bullet.GetTopLeftYPosition() <= (SCREEN_HEIGHT/2 - BULLET_HEIGHT))
			{
				_bullet.SetRegion(Region::TOP_RIGHT);
				// left half of top right quarter
				if (_bullet.GetTopLeftXPosition() <= (SCREEN_WIDTH*3/4 - BULLET_WIDTH))
				{
					// top half of left quarter
					if (_bullet.GetTopLeftYPosition() <= (SCREEN_HEIGHT/4 - BULLET_HEIGHT))
					{
						_bullet.SetSubRegion(Region::TOP_LEFT);
					}
					// bottom half of left quarter
					else
					{
						_bullet.SetSubRegion(Region::BOTTOM_LEFT);
					}
				}
				// right side of top right quarter
				else
				{
					// top half of top right quarter
					if (_bullet.GetTopLeftYPosition() <= (SCREEN_HEIGHT/4 - BULLET_HEIGHT))
					{
						_bullet.SetSubRegion(Region::TOP_RIGHT);
					}
					// bottom half of top right quarter
					else
					{
						_bullet.SetSubRegion(Region::BOTTOM_RIGHT);
					}
				}
			}
			// bottom half of screen
			else
			{
				_bullet.SetRegion(Region::BOTTOM_RIGHT);
				// 
				if (_bullet.GetTopLeftXPosition() <= (SCREEN_WIDTH*3/4 - BULLET_WIDTH))
				{
					// top half of right bottom quarter
					if (_bullet.GetTopLeftYPosition() <= (SCREEN_HEIGHT*3/4 - BULLET_HEIGHT))
					{
						_bullet.SetSubRegion(Region::TOP_LEFT);
					}
					// bottom half of right bottom quarter
					else
					{
						_bullet.SetSubRegion(Region::BOTTOM_LEFT);
					}
				}
				// right side of bottom right quarter
				else
				{
					// top half of left quarter
					if (_bullet.GetTopLeftYPosition() <= (SCREEN_HEIGHT*3/4 - BULLET_HEIGHT))
					{
						_bullet.SetSubRegion(Region::TOP_RIGHT);
					}
					// bottom half of left quarter
					else
					{
						_bullet.SetSubRegion(Region::BOTTOM_RIGHT);
					}
				}
			}
		}
	}
}