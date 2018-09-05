#include "CollisionHandler.h"
#include <cmath>

namespace GameEngine
{
	CollisionHandler::CollisionHandler(TurretPtr turret, CentPtr centipede):
	_turret(turret),
	_centipede(centipede)
	{
		
	}

	void CollisionHandler::CheckBulletCollisions()
	{
		
	}

	void CollisionHandler::CheckCentipedeSegmentCollisions()
	{
		
	}

	float CollisionHandler::CheckDistanceBetweenBulletsAndSegments(unsigned int BulletIndex, 
		unsigned int CentipedeSegmentIndex)
	{
		return sqrt(pow(_turret->GetBulletCenterXPosition(BulletIndex)-_centipede->GetSegmentCenterXPosition(CentipedeSegmentIndex), 2)
		+ pow(_turret->GetBulletCenterYPosition(BulletIndex)-_centipede->GetSegmentCenterXPosition(CentipedeSegmentIndex), 2));
	}
}