#include "BulletLogic.h"
#include "DEFINITIONS.h"
#include "RegionHandler.h"

namespace GameEngine
{
	BulletLogic::BulletLogic ( std::vector<Bullet>& bullets )
		: bullets_ ( bullets )
		, speed_ ( BULLET_SPEED )
	{
	}

	void BulletLogic::Spawn()
	{
	}

	void BulletLogic::Move ( float dt )
	{
		auto moveDistance = speed_ * dt;

		for ( unsigned int i = 0; i < bullets_.size(); i++ )
			{
				// Check whether bullet is moving to the top  of screen
				if ( bullets_.at ( i ).GetTopLeftYPosition() <= SCREEN_TOP )
					{
						bullets_.at ( i ).SetDead ( true );
					}

				else
					{
						bullets_.at ( i ).SetTopLeftYPosition ( bullets_.at ( i ).GetTopLeftYPosition() - moveDistance );
					}
			}
	}

	void BulletLogic::MoveProjectiles ( float dt )
	{
	}

	void BulletLogic::CollisionHandle()
	{
		// delete collided bullets
		auto dead = std::find ( bullets_.begin(), bullets_.end(), true );

		while ( dead != bullets_.end() )
			{
				bullets_.erase ( dead );
				dead = std::find ( dead, bullets_.end(), true );
			}
	}
} // namespace GameEngine
