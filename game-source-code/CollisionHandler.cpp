#include "CollisionHandler.h"
#include "Region.h"
#include "Mushroom.h"
#include "DEFINITIONS.h"
#include "Direction.h"
#include "Trajectory.h"
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

	void CollisionHandler::CheckBulletSegmentCollisions()
	{
		for (unsigned int i = 0; i < _turret->GetBullets().size(); i++)
		{
			// collision checking between bullets and centipedes
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
				else if (CheckDistanceBetweenBulletsAndSegments(i,j) < (CENTIPEDE_SEGMENT_HIT_RADIUS + BULLET_HIT_RADIUS))
				{
					_turret->GetBullets().at(i).SetDead(true);
					_centipede->GetCentipede().at(j).SetDead(true);
					auto mushroom = Mushroom{_data,
						_centipede->GetCentipede().at(j).GetTopLeftXPosition(),
						_centipede->GetCentipede().at(j).GetTopLeftYPosition()};
					_field->GetMushrooms().push_back(mushroom);

					// --------------ADD FUNCTIONALITY SO THAT THIS DOES NOT AFFECT ALL SPLIT SEGMENTS
					if ((j+1) != (_centipede->GetCentipede().size()))
					{
						_centipede->GetCentipede().at(j+1).GetSegmentSprite().setTexture(_data->resources.GetTexture("Segment sprite"));
					}
					break;
				}
			}
		}
	}

	void CollisionHandler::CheckSegmentMushroomCollisions()
	{
		for (unsigned int i = 0; i < _centipede->GetCentipede().size(); i++)
		{
			for (unsigned int j = 0; j < _field->GetMushrooms().size(); j++)
			{
				if ((_centipede->GetCentipede().at(i).GetDirection() == Direction::LEFT) || 
					(_centipede->GetCentipede().at(i).GetDirection() == Direction::RIGHT))
				{
					if (CheckDistanceBetweenSegmentsAndMushrooms(j, i) < (CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS))
					{
						if (_centipede->GetCentipede().at(i).GetTrajectory() == Trajectory::DOWNWARD)
						{
							_centipede->GetCentipede().at(i).SetDirection(Direction::DOWN);
						} else _centipede->GetCentipede().at(i).SetDirection(Direction::UP);
					}
				}
			}
		}
	}

	void CollisionHandler::CheckTurretSegmentCollisions()
	{
		for (unsigned int i = 0; i < _centipede->GetCentipede().size(); i++)
		{
			if (_centipede->GetCentipede().at(i).GetRegion() == _turret->GetRegion())
			{
				if (CheckDistanceBetweenSegmentsAndTurret(i) < (CENTIPEDE_SEGMENT_HIT_RADIUS + TURRET_HIT_RADIUS))
				{
					_turret->SetDead(true);
				}
			}
		}
	}

	float CollisionHandler::CheckDistanceBetweenBulletsAndSegments(unsigned int BulletIndex, 
		unsigned int segmentIndex)
	{
		return sqrt(pow(_turret->GetBullets().at(BulletIndex).GetCenterXPosition()-_centipede->GetSegmentCenterXPosition(segmentIndex), 2)
		+ pow(_turret->GetBullets().at(BulletIndex).GetCenterYPosition()-_centipede->GetSegmentCenterYPosition(segmentIndex), 2));
	}

	float CollisionHandler::CheckDistanceBetweenSegmentsAndMushrooms(unsigned int mushroomIndex, 
		unsigned int segmentIndex)
	{
		return sqrt(pow(_field->GetMushrooms().at(mushroomIndex).GetMushroomCenterXPosition()-_centipede->GetSegmentCenterXPosition(segmentIndex), 2)
		+ pow(_field->GetMushrooms().at(mushroomIndex).GetMushroomCenterYPosition()-_centipede->GetSegmentCenterYPosition(segmentIndex), 2));
	}

	float CollisionHandler::CheckDistanceBetweenSegmentsAndTurret(unsigned int segmentIndex)
	{
		return sqrt(pow(_turret->GetCenterXPosition()-_centipede->GetSegmentCenterXPosition(segmentIndex), 2)
		+ pow(_turret->GetCenterYPosition()-_centipede->GetSegmentCenterYPosition(segmentIndex), 2));
	}
}