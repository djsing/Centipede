#include "CollisionHandler.h"
#include "Region.h"
#include "Mushroom.h"
#include "DEFINITIONS.h"
#include <cmath>

namespace GameEngine
{
	CollisionHandler::CollisionHandler(DataPtr data, TurretPtr turret, CentPtr centipede, FieldPtr field):
	_data(data),
	_turret(turret),
	_centipede(centipede),
	_field(field)
	{
		
	}

	void CollisionHandler::CheckBulletCollisions()
	{
		for (unsigned int i = 0; i < _turret->GetBullets().size(); i++)
		{
			for (unsigned int j = 0; j < _centipede->GetCentipede().size(); j++)
			{
				if (_turret->GetBullets().at(i).GetRegion() != _centipede->GetCentipede().at(j).GetRegion())
				{
					continue;
				}
				else if (_turret->GetBullets().at(i).GetSubRegion() != _centipede->GetCentipede().at(j).GetSubRegion()) 
				{
					continue;
				}
				else if (CheckDistanceBetweenBulletsAndSegments(i,j) <= (CENTIPEDE_SEGMENT_HIT_RADIUS + BULLET_HIT_RADIUS))
				{
					_turret->GetBullets().at(i).SetDead(true);
					_centipede->GetCentipede().at(j).SetDead(true);
					auto mushroom = Mushroom{_data,
						_centipede->GetCentipede().at(j).GetTopLeftXPosition(),
						_centipede->GetCentipede().at(j).GetTopLeftYPosition(),
						_centipede->GetCentipede().at(j).GetRegion(),
						_centipede->GetCentipede().at(j).GetSubRegion()};
					_field->GetMushrooms().push_back(mushroom);

					// --------------ADD FUNCTIONALITY SO THAT THIS DOES NOT AFFECT ALL SPLIT SEGMENTS
					if ((j+1) != (_centipede->GetCentipede().size()))
					{
						_centipede->GetCentipede().at(j+1).GetSegmentSprite().setTexture(_data->resources.GetTexture("Segment sprite"));
					}
					
					// not breaking the loop accounts for bullets hitting segments at the same time
				}
			}
		}
	}

	void CollisionHandler::CheckCentipedeSegmentCollisions()
	{
		
	}

	float CollisionHandler::CheckDistanceBetweenBulletsAndSegments(unsigned int BulletIndex, 
		unsigned int CentipedeSegmentIndex)
	{
		return sqrt(pow(_turret->GetBulletCenterXPosition(BulletIndex)-_centipede->GetSegmentCenterXPosition(CentipedeSegmentIndex), 2)
		+ pow(_turret->GetBulletCenterYPosition(BulletIndex)-_centipede->GetSegmentCenterYPosition(CentipedeSegmentIndex), 2));
	}
}