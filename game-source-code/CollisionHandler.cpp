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
				else if (CheckDistanceBetweenEntities(_centipede->GetCentipede().at(j), _turret->GetBullets().at(i)) 
					< (CENTIPEDE_SEGMENT_HIT_RADIUS + BULLET_HIT_RADIUS))
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
						_centipede->GetCentipede().at(j+1).SetFirstSegment(true);
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
					if (CheckDistanceBetweenEntities(_centipede->GetCentipede().at(i), _field->GetMushrooms().at(j)) 
						< (CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS))
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
				if (CheckDistanceBetweenEntities(_centipede->GetCentipede().at(i), *_turret) < (CENTIPEDE_SEGMENT_HIT_RADIUS + TURRET_HIT_RADIUS))
				{
					_turret->SetDead(true);
				}
			}
		}
	}

	float CollisionHandler::CheckDistanceBetweenEntities(Entity &entity1, Entity &entity2)
	{
		return sqrt(pow(entity1.GetCenterXPosition() - entity2.GetCenterXPosition(),2)
			+ pow(entity1.GetCenterYPosition() - entity2.GetCenterYPosition(),2));
	}
}