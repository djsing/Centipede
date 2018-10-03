#include <cmath>
#include <ctime>
#include "CollisionHandler.h"
#include "DEFINITIONS.h"
#include "Direction.h"
#include "Mushroom.h"
#include "Region.h"
#include "Trajectory.h"

namespace GameEngine
{
CollisionHandler::CollisionHandler(DataPtr data, TurretPtr turret, CentPtr centipede, FieldPtr field)
    : data_(data), turret_(turret), centipede_(centipede), field_(field)
{
}

void CollisionHandler::CheckCollisions()
{
    // check for game losing collisions first
    CheckTurretSpiderCollisions();
    CheckTurretSegmentCollisions();

    // if the game is not lost, check the remaining collisions
    if(!turret_->IsDead())
	{
	    // check for game winning collisions
	    CheckBulletSegmentCollisions();
	    // check for point scoring collisions
	    CheckBulletSpiderCollisions();
	    CheckBulletMushroomCollisions();

	    // if the game hasnt been won, check for
	    // non-point scoring collisions
	    if(!centipede_->GetCentipede().empty())
		{
		    // check field altering collisions
		    CheckMushroomScorpionCollisions();
		    CheckMushroomSpiderCollisions();
		    // check segment collisions after the field is altered
		    CheckSegmentMushroomCollisions();
		}
	}
}

void CollisionHandler::CheckBulletSegmentCollisions()
{
    if(!turret_->GetBullets().empty())
	{
	    for(auto& i : turret_->GetBullets())
		{
		    auto it = std::find(centipede_->GetCentipede().begin(), centipede_->GetCentipede().end(),
		                        std::make_pair(i.GetRegion(), i.GetSubRegion()));
		    while(it != centipede_->GetCentipede().end())
			{
			    if(CheckDistanceBetweenEntities(*it, i) < CENTIPEDE_SEGMENT_HIT_RADIUS + BULLET_HIT_RADIUS)
				{
				    i.SetDead(true);
				    it->SetDead(true);
				    // saved the position of bullet/segment collisions to the GameField container.
				    field_->GetNewMushrooms().push_back(
				        std::make_tuple(it->GetTopLeftXPosition(), it->GetTopLeftYPosition()));
				}
			    it++;
			    it = std::find(it, centipede_->GetCentipede().end(),
			                   std::make_pair(i.GetRegion(), i.GetSubRegion()));
			}
		}
	}
}

void CollisionHandler::CheckSegmentMushroomCollisions()
{
    for(auto& i : centipede_->GetCentipede())
	{
	    auto it = std::find(field_->GetMushrooms().begin(), field_->GetMushrooms().end(),
	                        std::make_pair(i.GetRegion(), i.GetSubRegion()));
	    while(it != field_->GetMushrooms().end())
		{
		    if(it->IsPoisoned() &&
		       CheckDistanceBetweenEntities(i, *it) < CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS)
			{
			    // set segments
			    i.SetPoisoned(true);
			    // set mushrooms normal after collisions with the last segment of a centipede segment
			    if(i.IsLastSegment())
				{
				    it->SetPoisoned(false);
				}
			    it++;
			    it = std::find(it, field_->GetMushrooms().end(),
			                   std::make_pair(i.GetRegion(), i.GetSubRegion()));
			    continue;
			}
		    // only check collisions when the segment is moving across the screen
		    if(((i.GetDirection() == Direction::LEFT) || (i.GetDirection() == Direction::RIGHT)) &&
		       CheckDistanceBetweenEntities(i, *it) < CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS)
			{
			    if(i.GetDirection() == Direction::LEFT)
				{
				    i.SetTopLeftXPosition(it->GetTopLeftXPosition() + MUSHROOM_SPRITE_SIZE);
				}
			    else
				i.SetTopLeftXPosition(it->GetTopLeftXPosition() - CENTIPEDE_SPRITE_SIDE_SIZE);

			    if(i.GetTrajectory() == Trajectory::DOWNWARD)
				{
				    i.SetDirection(Direction::DOWN);
				}

			    else
				i.SetDirection(Direction::UP);
			}
		    it++;
		    it = std::find(it, field_->GetMushrooms().end(), std::make_pair(i.GetRegion(), i.GetSubRegion()));
		}
	}
}

void CollisionHandler::CheckTurretSegmentCollisions()
{
    if(!turret_->IsDead())
	{
	    auto it = std::find(centipede_->GetCentipede().begin(), centipede_->GetCentipede().end(),
	                        std::make_pair(turret_->GetRegion(), turret_->GetSubRegion()));
	    while(it != centipede_->GetCentipede().end())
		{
		    if(CheckDistanceBetweenEntities(*it, *turret_) < CENTIPEDE_SEGMENT_HIT_RADIUS + TURRET_HIT_RADIUS)
			{
			    data_->lives.LifeLost();
			    turret_->SetDead(true);
			    return;
			}
		    it++;
		    it = std::find(it, centipede_->GetCentipede().end(),
		                   std::make_pair(turret_->GetRegion(), turret_->GetSubRegion()));
		}
	}
}

void CollisionHandler::CheckTurretSpiderCollisions()
{
    if(!turret_->IsDead() && !field_->GetSpiders().empty())
	{
	    auto it = std::find(field_->GetSpiders().begin(), field_->GetSpiders().end(),
	                        std::make_pair(turret_->GetRegion(), turret_->GetSubRegion()));
	    while(it != field_->GetSpiders().end())
		{
		    if(CheckDistanceBetweenEntities(*it, *turret_) < TURRET_HIT_RADIUS + SPIDER_HIT_RADIUS)
			{
			    data_->lives.LifeLost();
			    turret_->SetDead(true);
			    return;
			}
		    it++;
		    it = std::find(it, field_->GetSpiders().end(),
		                   std::make_pair(turret_->GetRegion(), turret_->GetSubRegion()));
		}
	}
}

void CollisionHandler::CheckMushroomScorpionCollisions()
{
    for(auto& i : field_->GetScorpions())
	{
	    auto it = std::find(field_->GetMushrooms().begin(), field_->GetMushrooms().end(),
	                        std::make_pair(i.GetRegion(), i.GetSubRegion()));
	    while(it != field_->GetMushrooms().end())
		{
		    if(CheckDistanceBetweenEntities(*it, i) < MUSHROOM_HIT_RADIUS + SCORPION_HIT_RADIUS)
			{
			    it->SetPoisoned(true);
			}
		    it++;
		    it = std::find(it, field_->GetMushrooms().end(), std::make_pair(i.GetRegion(), i.GetSubRegion()));
		}
	}
}

void CollisionHandler::CheckMushroomSpiderCollisions()
{
    if(!field_->GetSpiders().empty())
	{
	    for(auto& j : field_->GetSpiders())
		{
		    auto it = std::find(field_->GetMushrooms().begin(), field_->GetMushrooms().end(),
		                        std::make_pair(j.GetRegion(), j.GetSubRegion()));
		    while(it != field_->GetMushrooms().end())
			{
			    if(CheckDistanceBetweenEntities(*it, j) < MUSHROOM_HIT_RADIUS + SPIDER_HIT_RADIUS)
				{
				    it->SetBitten(true);
				}
			    it++;
			    it = std::find(it, field_->GetMushrooms().end(),
			                   std::make_pair(j.GetRegion(), j.GetSubRegion()));
			}
		}
	}
}

void CollisionHandler::CheckBulletSpiderCollisions()
{
    if(!turret_->GetBullets().empty() && !field_->GetSpiders().empty())
	{
	    for(auto& j : field_->GetSpiders())
		{
		    auto it = std::find(turret_->GetBullets().begin(), turret_->GetBullets().end(),
		                        std::make_pair(j.GetRegion(), j.GetSubRegion()));
		    while(it != turret_->GetBullets().end())
			{
			    if(CheckDistanceBetweenEntities(j, *it) < SPIDER_HIT_RADIUS + BULLET_HIT_RADIUS)
				{
				    it->SetDead(true);
				    j.SetDead(true);
				}
			    it++;
			    it = std::find(it, turret_->GetBullets().end(),
			                   std::make_pair(j.GetRegion(), j.GetSubRegion()));
			}
		}
	}
}

void CollisionHandler::CheckBulletMushroomCollisions()
{
    if(!turret_->GetBullets().empty())
	{
	    for(auto& i : turret_->GetBullets())
		{
		    auto it = std::find(field_->GetMushrooms().begin(), field_->GetMushrooms().end(),
		                        std::make_pair(i.GetRegion(), i.GetSubRegion()));
		    // collision checking between bullets and mushrooms
		    while(it != field_->GetMushrooms().end())
			{
			    if(CheckDistanceBetweenEntities(*it, i) < MUSHROOM_HIT_RADIUS + BULLET_HIT_RADIUS)
				{
				    i.SetDead(true);
				    it->DecrementLives();
				    if(it->GetLivesRemaining() == 0)
					{
					    it->SetDead(true);
					}
				}
			    it++;
			    it = std::find(it, field_->GetMushrooms().end(),
			                   std::make_pair(i.GetRegion(), i.GetSubRegion()));
			}
		}
	}
}

float CollisionHandler::CheckDistanceBetweenEntities(Entity& entity1, Entity& entity2)
{
    return sqrt(pow(entity1.GetCenterXPosition() - entity2.GetCenterXPosition(), 2) +
                pow(entity1.GetCenterYPosition() - entity2.GetCenterYPosition(), 2));
}
}  // namespace GameEngine
