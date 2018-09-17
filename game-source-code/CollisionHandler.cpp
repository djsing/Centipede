#include "CollisionHandler.h"
#include "Region.h"
#include "Mushroom.h"
#include "DEFINITIONS.h"
#include "Direction.h"
#include "Trajectory.h"
#include <cmath>
#include <ctime>
#include <cstdlib>

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
		if (!_turret->GetBullets().empty())
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
	}

	void CollisionHandler::CheckSegmentMushroomCollisions()
	{
		for (unsigned int i = 0; i < _centipede->GetCentipede().size(); i++)
		{
			for (unsigned int j = 0; j < _field->GetMushrooms().size(); j++)
			{
				if (_field->GetMushrooms().at(j).IsPoisoned())
				{
					if (CheckDistanceBetweenEntities(_centipede->GetCentipede().at(i), _field->GetMushrooms().at(j)) 
						< (CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS))
					{
						_centipede->GetCentipede().at(i).SetPoisoned(true);
						if (_centipede->GetCentipede().size() != i+1)
						{
							_centipede->GetCentipede().at(i+1).SetFirstSegment(true);
						}
						_field->GetMushrooms().at(j).SetPoisoned(false);
						continue;
					}
				}

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
				if (CheckDistanceBetweenEntities(_centipede->GetCentipede().at(i), *_turret)
					< (CENTIPEDE_SEGMENT_HIT_RADIUS + TURRET_HIT_RADIUS))
				{
					_turret->DecrementLives();
					if (_turret->GetLivesRemaining() == 0)
					{
						_turret->SetDead(true);
					}
				}
			}
		}
	}

	void CollisionHandler::CheckTurretSpiderCollisions()
	{
		if (!_field->GetSpiders().empty())
		{
			for (unsigned int i = 0; i < _field->GetSpiders().size(); i++)
			{
				if (CheckDistanceBetweenEntities(_field->GetSpiders().at(i), *_turret) < (TURRET_HIT_RADIUS + SPIDER_HIT_RADIUS))
				{
					_turret->DecrementLives();
					if (_turret->GetLivesRemaining() == 0)
					{
						_turret->SetDead(true);
					}
				}
			}
		}
	}

	void CollisionHandler::CheckMushroomScorpionCollisions()
	{
		for (unsigned int i = 0; i < _field->GetMushrooms().size(); i++)
		{
			if (!_field->GetScorpions().empty())
			{
				for (unsigned int j = 0; j < _field->GetScorpions().size(); j++)
				{
					if (CheckDistanceBetweenEntities(_field->GetMushrooms().at(i), _field->GetScorpions().at(j)) 
						< (MUSHROOM_HIT_RADIUS + SCORPION_HIT_RADIUS))
					{
						_field->GetMushrooms().at(i).SetPoisoned(true);
					}
				}
			} else break;
		}
	}

	void CollisionHandler::CheckMushroomSpiderCollisions()
	{
		for (unsigned int i = 0; i < _field->GetMushrooms().size(); i++)
		{
			if (!_field->GetSpiders().empty())
			{
				for (unsigned int j = 0; j < _field->GetSpiders().size(); j++)
				{
					if ((_field->GetMushrooms().at(i).GetRegion() == (Region::BOTTOM_LEFT))||
						(_field->GetMushrooms().at(i).GetRegion() == Region::BOTTOM_RIGHT))
					{
						if (CheckDistanceBetweenEntities(_field->GetMushrooms().at(i), _field->GetSpiders().at(j)) 
							< (MUSHROOM_HIT_RADIUS + SPIDER_HIT_RADIUS))
						{
							_field->GetMushrooms().at(i).SetDead(true);
						}
					}
				}
			} else break;
		}
	}

	void CollisionHandler::CheckBulletSpiderCollisions()
	{
		if (!_turret->GetBullets().empty())
		{
			for (unsigned int i = 0; i < _turret->GetBullets().size(); i++)
			{
				if (!_field->GetSpiders().empty())
				{
					// collision checking between bullets and spiders
					for (unsigned int j = 0; j < _field->GetSpiders().size(); j++)
					{
						if (_turret->GetBullets().at(i).GetRegion() != _field->GetSpiders().at(j).GetRegion())
						{
							continue;
						}
						else if (_turret->GetBullets().at(i).GetSubRegion() != _field->GetSpiders().at(j).GetSubRegion()) 
						{
							continue;
						}
						else if (CheckDistanceBetweenEntities(_field->GetSpiders().at(j), _turret->GetBullets().at(i)) 
							< (SPIDER_HIT_RADIUS + BULLET_HIT_RADIUS))
						{
							_turret->GetBullets().at(i).SetDead(true);
							_field->GetSpiders().at(j).SetDead(true);
						}
					}
				} else break;
			}
		}
	}

	void CollisionHandler::CheckBulletMushroomCollisions()
	{
		if (!_turret->GetBullets().empty())
		{
			for (unsigned int i = 0; i < _turret->GetBullets().size(); i++)
			{
				if (!_field->GetMushrooms().empty())
				{
					// collision checking between bullets and mushrooms
					for (unsigned int j = 0; j < _field->GetMushrooms().size(); j++)
					{
						if (CheckDistanceBetweenEntities(_field->GetMushrooms().at(j), _turret->GetBullets().at(i)) 
							< (MUSHROOM_HIT_RADIUS + BULLET_HIT_RADIUS))
						{
							_turret->GetBullets().at(i).SetDead(true);
							_field->GetMushrooms().at(j).DecrementLives();
							if (_field->GetMushrooms().at(j).GetLivesRemaining() == 0)
							{
								_field->GetMushrooms().at(j).SetDead(true);
							}
						}
					}
				} else break;
			}
		}
	}

	float CollisionHandler::CheckDistanceBetweenEntities(Entity &entity1, Entity &entity2)
	{
		return sqrt(pow(entity1.GetCenterXPosition() - entity2.GetCenterXPosition(),2)
			+ pow(entity1.GetCenterYPosition() - entity2.GetCenterYPosition(),2));
	}
}