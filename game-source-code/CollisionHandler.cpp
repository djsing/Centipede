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
	    CheckBulletBombCollisions();
	    CheckExplosionCollisions();
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
		    if(i.IsDead())
			{
			    continue;
			}

		    auto it = std::find(centipede_->GetCentipede().begin(), centipede_->GetCentipede().end(),
		                        std::make_pair(i.GetRegion(), i.GetSubRegion()));
		    while(it != centipede_->GetCentipede().end())
			{
			    if(CheckDistanceBetweenEntities(*it, i) < CENTIPEDE_SEGMENT_HIT_RADIUS + BULLET_HIT_RADIUS)
				{
				    i.SetDead();
				    it->SetDead();
				    data_->score_manager.IncrementScore(SEGMENT_SCORE);
				    // saved the position of bullet/segment collisions to the GameField container.
				    field_->GetNewMushrooms().push_back(
				        std::make_pair(it->GetTopLeftXPosition(), it->GetTopLeftYPosition()));
				    break;
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
    for(unsigned int i = 0; i < centipede_->GetCentipede().size(); i++)
	{
	    // if segment is poisoned, or moving up/down, don't check for collisions, since the behaviour for poisoned
	    // segments is predefined in the Move() function
	    if(centipede_->GetCentipede().at(i).IsPoisoned() ||
	       centipede_->GetCentipede().at(i).GetDirection() == Direction::UP ||
	       centipede_->GetCentipede().at(i).GetDirection() == Direction::DOWN ||
	       centipede_->GetCentipede().at(i).IsDead())
		{
		    continue;
		}

	    auto it = std::find(field_->GetMushrooms().begin(), field_->GetMushrooms().end(),
	                        std::make_pair(centipede_->GetCentipede().at(i).GetRegion(),
	                                       centipede_->GetCentipede().at(i).GetSubRegion()));
	    while(it != field_->GetMushrooms().end())
		{
		    if(it->IsPoisoned() && CheckDistanceBetweenEntities(centipede_->GetCentipede().at(i), *it) <
		                               CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS)
			{
			    // set segments
			    centipede_->GetCentipede().at(i).SetPoisoned(true);
			    // set mushrooms normal after collisions with the last segment of a centipede segment
			    if(centipede_->GetCentipede().at(i).IsLastSegment())
				{
				    it->SetPoisoned(false);
				}
			    it++;
			    it = std::find(it, field_->GetMushrooms().end(),
			                   std::make_pair(centipede_->GetCentipede().at(i).GetRegion(),
			                                  centipede_->GetCentipede().at(i).GetSubRegion()));
			    continue;
			}

		    if(CheckDistanceBetweenEntities(centipede_->GetCentipede().at(i), *it) <
		       CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS)
			{
			    if(centipede_->GetCentipede().at(i).GetDirection() == Direction::LEFT)
				{
				    centipede_->GetCentipede().at(i).SetTopLeftXPosition(it->GetTopLeftXPosition() +
				                                                         MUSHROOM_SPRITE_SIZE);
				}
			    else
				centipede_->GetCentipede().at(i).SetTopLeftXPosition(it->GetTopLeftXPosition() -
				                                                     CENTIPEDE_SPRITE_SIDE_SIZE);

			    if(centipede_->GetCentipede().at(i).GetTrajectory() == Trajectory::DOWNWARD)
				{
				    centipede_->GetCentipede().at(i).SetDirection(Direction::DOWN);
				}

			    else
				centipede_->GetCentipede().at(i).SetDirection(Direction::UP);
			}
		    it++;
		    it = std::find(it, field_->GetMushrooms().end(),
		                   std::make_pair(centipede_->GetCentipede().at(i).GetRegion(),
		                                  centipede_->GetCentipede().at(i).GetSubRegion()));
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
			    turret_->SetDead();
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
			    turret_->SetDead();
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
				    it->SetDead();
				    j.SetDead();
				    data_->score_manager.IncrementScore(SPIDER_SCORE);
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
		    if(i.IsDead())
			{
			    continue;
			}
		    auto it = std::find(field_->GetMushrooms().begin(), field_->GetMushrooms().end(),
		                        std::make_pair(i.GetRegion(), i.GetSubRegion()));
		    // collision checking between bullets and mushrooms
		    while(it != field_->GetMushrooms().end())
			{
			    if(CheckDistanceBetweenEntities(*it, i) < MUSHROOM_HIT_RADIUS + BULLET_HIT_RADIUS)
				{
				    i.SetDead();
				    it->DecrementLives();
				    if(it->GetLivesRemaining() == 0)
					{
					    it->SetDead();
					    data_->score_manager.IncrementScore(MUSHROOM_SCORE);
					}
				}
			    it++;
			    it = std::find(it, field_->GetMushrooms().end(),
			                   std::make_pair(i.GetRegion(), i.GetSubRegion()));
			}
		}
	}
}

void CollisionHandler::CheckBulletBombCollisions()
{
    if(!turret_->GetBullets().empty())
	{
	    for(auto& i : field_->GetBombs())
		{
		    if(i.IsDead())
			{
			    continue;
			}
		    auto it = std::find(turret_->GetBullets().begin(), turret_->GetBullets().end(),
		                        std::make_pair(i.GetRegion(), i.GetSubRegion()));
		    while(it != turret_->GetBullets().end())
			{
			    if(CheckDistanceBetweenEntities(i, *it) < BULLET_HIT_RADIUS + BOMB_HIT_RADIUS)
				{
				    it->SetDead();
				    i.SetDead();
				    break;
				}
			    it++;
			    it = std::find(it, turret_->GetBullets().end(),
			                   std::make_pair(i.GetRegion(), i.GetSubRegion()));
			}
		}
	}
}

void CollisionHandler::CheckExplosionCollisions()
{
    for(auto& i : field_->GetBombs())
	{
	    if(i.IsDead())
		{
		    // Check scorpion deaths
		    for(auto& j : field_->GetScorpions())
			{
			    if(j.IsDead())
				{
				    continue;
				}
			    if(CheckDistanceBetweenEntities(i, j) < SCORPION_HIT_RADIUS + EXPLOSION_HIT_RADIUS)
				{
				    i.SetDead();
				    j.SetDead();
				    data_->score_manager.IncrementScore(SCORPION_SCORE);
				}
			}
		    // Check spider deaths
		    for(auto& j : field_->GetSpiders())
			{
			    if(j.IsDead())
				{
				    continue;
				}
			    if(CheckDistanceBetweenEntities(i, j) < SPIDER_HIT_RADIUS + EXPLOSION_HIT_RADIUS)
				{
				    i.SetDead();
				    j.SetDead();
				    data_->score_manager.IncrementScore(SPIDER_SCORE);
				}
			}
		    // Check mushroom deaths
		    for(auto& j : field_->GetMushrooms())
			{
			    if(j.IsDead())
				{
				    continue;
				}
			    if(CheckDistanceBetweenEntities(i, j) < CENTIPEDE_SEGMENT_HIT_RADIUS + EXPLOSION_HIT_RADIUS)
				{
				    i.SetDead();
				    j.SetDead();
				    data_->score_manager.IncrementScore(MUSHROOM_SCORE);
				}
			}
		    // Check segment deaths
		    for(auto& j : centipede_->GetCentipede())
			{
			    if(j.IsDead())
				{
				    continue;
				}
			    if(CheckDistanceBetweenEntities(i, j) < CENTIPEDE_SEGMENT_HIT_RADIUS + EXPLOSION_HIT_RADIUS)
				{
				    i.SetDead();
				    j.SetDead();
				    data_->score_manager.IncrementScore(SEGMENT_SCORE);
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
