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
		    for(auto& j : centipede_->GetCentipede())
			{
			    // if bullets and centipedes are in the same region, subregion, and
			    // if the are in hit range, register a collision
			    if(i.GetRegion() == j.GetRegion() && i.GetSubRegion() == j.GetSubRegion() &&
			       CheckDistanceBetweenEntities(j, i) < CENTIPEDE_SEGMENT_HIT_RADIUS + BULLET_HIT_RADIUS)
				{
				    i.SetDead(true);
				    j.SetDead(true);
				    auto mushroom = Mushroom{j.GetTopLeftXPosition(), j.GetTopLeftYPosition()};
				    field_->GetMushrooms().push_back(mushroom);
				    break;
				}
			}
		}
	}
}

void CollisionHandler::CheckSegmentMushroomCollisions()
{
    for(auto& i : centipede_->GetCentipede())
	{
	    for(auto& j : field_->GetMushrooms())
		{
		    // provide a seperate collision checking for poisoned mushrooms
		    if(j.IsPoisoned() &&
		       CheckDistanceBetweenEntities(i, j) < CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS)
			{
			    // set segments
			    i.SetPoisoned(true);
			    i.SetFirstSegment(true);
			    // set mushrooms
			    j.SetPoisoned(false);
			    continue;
			}

		    // only check collisions when the segment is moving across the screen
		    if(((i.GetDirection() == Direction::LEFT) || (i.GetDirection() == Direction::RIGHT)) &&
		       CheckDistanceBetweenEntities(i, j) < CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS)
			{
			    if(i.GetTrajectory() == Trajectory::DOWNWARD)
				{
				    i.SetDirection(Direction::DOWN);
				}

			    else
				i.SetDirection(Direction::UP);
			}
		}
	}
}

void CollisionHandler::CheckTurretSegmentCollisions()
{
    if(!turret_->IsDead())
	{
	    for(auto& i : centipede_->GetCentipede())
		{
		    // the turret is in the same region/subregion and are in hit radius of eachother, kill turret
		    if(i.GetRegion() == turret_->GetRegion() && i.GetSubRegion() == turret_->GetSubRegion() &&
		       CheckDistanceBetweenEntities(i, *turret_) < CENTIPEDE_SEGMENT_HIT_RADIUS + TURRET_HIT_RADIUS)
			{
			    data_->lives.LifeLost();
			    turret_->SetDead(true);
			    return;
			}
		}
	}
}

void CollisionHandler::CheckTurretSpiderCollisions()
{
    if(!turret_->IsDead() && !field_->GetSpiders().empty())
	{
	    for(auto& i : field_->GetSpiders())
		{
		    if(CheckDistanceBetweenEntities(i, *turret_) < TURRET_HIT_RADIUS + SPIDER_HIT_RADIUS)
			{
			    data_->lives.LifeLost();
			    turret_->SetDead(true);
			    return;
			}
		}
	}
}

void CollisionHandler::CheckMushroomScorpionCollisions()
{
    for(auto& i : field_->GetMushrooms())
	{
	    for(auto& j : field_->GetScorpions())
		{
		    if(CheckDistanceBetweenEntities(i, j) < MUSHROOM_HIT_RADIUS + SCORPION_HIT_RADIUS)
			{
			    i.SetPoisoned(true);
			}
		}
	}
}

void CollisionHandler::CheckMushroomSpiderCollisions()
{
    if(!field_->GetSpiders().empty())
	{
	    for(auto& i : field_->GetMushrooms())
		{
		    for(auto& j : field_->GetSpiders())
			{
			    if((i.GetRegion() == Region::BOTTOM_LEFT || i.GetRegion() == Region::BOTTOM_RIGHT) &&
			       CheckDistanceBetweenEntities(i, j) < MUSHROOM_HIT_RADIUS + SPIDER_HIT_RADIUS)
				{
				    i.SetBitten(true);
				}
			}
		}
	}
}

void CollisionHandler::CheckBulletSpiderCollisions()
{
    if(!turret_->GetBullets().empty() && !field_->GetSpiders().empty())
	{
	    for(auto& i : turret_->GetBullets())
		{
		    // collision checking between bullets and spiders
		    for(auto& j : field_->GetSpiders())
			{
			    // if bullets are in the same region/subregion and they are
			    // within hit radius, register a collision
			    if(i.GetRegion() == j.GetRegion() && i.GetSubRegion() == j.GetSubRegion() &&
			       CheckDistanceBetweenEntities(j, i) < SPIDER_HIT_RADIUS + BULLET_HIT_RADIUS)
				{
				    i.SetDead(true);
				    j.SetDead(true);
				}
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
		    // collision checking between bullets and mushrooms
		    for(auto& j : field_->GetMushrooms())
			{
			    if(CheckDistanceBetweenEntities(j, i) < MUSHROOM_HIT_RADIUS + BULLET_HIT_RADIUS)
				{
				    if(j.GetLivesRemaining() == 0)
					{
					    j.SetDead(true);
					}
				    else
					j.DecrementLives();

				    i.SetDead(true);
				}
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
