#include <cmath>
#include <cstdlib>
#include <ctime>
#include "CollisionHandler.h"
#include "DEFINITIONS.h"
#include "Direction.h"
#include "Mushroom.h"
#include "Region.h"
#include "Trajectory.h"

namespace GameEngine
{
CollisionHandler::CollisionHandler ( DataPtr data, TurretPtr turret, CentPtr centipede, FieldPtr field )
    : data_ ( data ), turret_ ( turret ), centipede_ ( centipede ), field_ ( field )
{
}

void CollisionHandler::CheckCollisions ()
{
    // check for game losing collisions first
    CheckTurretSpiderCollisions ();
    CheckTurretSegmentCollisions ();

    // if the game is not lost, check the remaining collisions
    if ( !turret_->IsDead () )
	{
	    // check for game winning collisions
	    CheckBulletSegmentCollisions ();
	    // check for point scoring collisions
	    CheckBulletSpiderCollisions ();
	    CheckBulletMushroomCollisions ();
	    // check field altering collisions
	    CheckMushroomScorpionCollisions ();
	    CheckMushroomSpiderCollisions ();
	    // check segment collisions after the field is altered
	    CheckSegmentMushroomCollisions ();
	}
}

void CollisionHandler::CheckBulletSegmentCollisions ()
{
    if ( !turret_->GetBullets ().empty () )
	{
	    for ( unsigned int i = 0; i < turret_->GetBullets ().size (); i++ )
		{
		    // collision checking between bullets and centipedes
		    for ( unsigned int j = 0; j < centipede_->GetCentipede ().size (); j++ )
			{
			    if ( turret_->GetBullets ().at ( i ).GetRegion () !=
			         centipede_->GetCentipede ().at ( j ).GetRegion () )
				{
				    continue;
				}

			    else if ( turret_->GetBullets ().at ( i ).GetSubRegion () !=
			              centipede_->GetCentipede ().at ( j ).GetSubRegion () )
				{
				    continue;
				}

			    else if ( CheckDistanceBetweenEntities ( centipede_->GetCentipede ().at ( j ),
			                                             turret_->GetBullets ().at ( i ) ) <
			              ( CENTIPEDE_SEGMENT_HIT_RADIUS + BULLET_HIT_RADIUS ) )
				{
				    turret_->GetBullets ().at ( i ).SetDead ( true );
				    centipede_->GetCentipede ().at ( j ).SetDead ( true );
				    auto mushroom =
				        Mushroom{centipede_->GetCentipede ().at ( j ).GetTopLeftXPosition (),
				                 centipede_->GetCentipede ().at ( j ).GetTopLeftYPosition ()};
				    field_->GetMushrooms ().push_back ( mushroom );

				    // --------------ADD FUNCTIONALITY SO THAT THIS DOES NOT AFFECT ALL SPLIT SEGMENTS
				    if ( ( j + 1 ) != ( centipede_->GetCentipede ().size () ) )
					{
					    centipede_->GetCentipede ().at ( j + 1 ).SetFirstSegment ( true );
					}

				    break;
				}
			}
		}
	}
}

void CollisionHandler::CheckSegmentMushroomCollisions ()
{
    for ( unsigned int i = 0; i < centipede_->GetCentipede ().size (); i++ )
	{
	    for ( unsigned int j = 0; j < field_->GetMushrooms ().size (); j++ )
		{
		    if ( field_->GetMushrooms ().at ( j ).IsPoisoned () )
			{
			    if ( CheckDistanceBetweenEntities ( centipede_->GetCentipede ().at ( i ),
			                                        field_->GetMushrooms ().at ( j ) ) <
			         ( CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS ) )
				{
				    centipede_->GetCentipede ().at ( i ).SetPoisoned ( true );
				    centipede_->GetCentipede ().at ( i ).SetFirstSegment ( true );

				    if ( centipede_->GetCentipede ().size () != i + 1 )
					{
					    centipede_->GetCentipede ().at ( i + 1 ).SetFirstSegment ( true );
					}

				    field_->GetMushrooms ().at ( j ).SetPoisoned ( false );
				    continue;
				}
			}

		    if ( ( centipede_->GetCentipede ().at ( i ).GetDirection () == Direction::LEFT ) ||
		         ( centipede_->GetCentipede ().at ( i ).GetDirection () == Direction::RIGHT ) )
			{
			    if ( CheckDistanceBetweenEntities ( centipede_->GetCentipede ().at ( i ),
			                                        field_->GetMushrooms ().at ( j ) ) <
			         ( CENTIPEDE_SEGMENT_HIT_RADIUS + MUSHROOM_HIT_RADIUS ) )
				{
				    if ( centipede_->GetCentipede ().at ( i ).GetTrajectory () == Trajectory::DOWNWARD )
					{
					    centipede_->GetCentipede ().at ( i ).SetDirection ( Direction::DOWN );
					}

				    else
					centipede_->GetCentipede ().at ( i ).SetDirection ( Direction::UP );
				}
			}
		}
	}
}

void CollisionHandler::CheckTurretSegmentCollisions ()
{
    if ( !turret_->IsDead () )
	{
	    for ( unsigned int i = 0; i < centipede_->GetCentipede ().size (); i++ )
		{
		    if ( centipede_->GetCentipede ().at ( i ).GetRegion () == turret_->GetRegion () &&
		         centipede_->GetCentipede ().at ( i ).GetSubRegion () == turret_->GetSubRegion () )
			{
			    if ( CheckDistanceBetweenEntities ( centipede_->GetCentipede ().at ( i ), *turret_ ) <
			         ( CENTIPEDE_SEGMENT_HIT_RADIUS + TURRET_HIT_RADIUS ) )
				{
				    data_->lives.LifeLost ();
				    turret_->SetDead ( true );
				    return;
				}
			}
		}
	}
}

void CollisionHandler::CheckTurretSpiderCollisions ()
{
    if ( !turret_->IsDead () )
	{
	    if ( !field_->GetSpiders ().empty () )
		{
		    for ( unsigned int i = 0; i < field_->GetSpiders ().size (); i++ )
			{
			    if ( CheckDistanceBetweenEntities ( field_->GetSpiders ().at ( i ), *turret_ ) <
			         ( TURRET_HIT_RADIUS + SPIDER_HIT_RADIUS ) )
				{
				    data_->lives.LifeLost ();
				    turret_->SetDead ( true );
				    return;
				}
			}
		}
	}
}

void CollisionHandler::CheckMushroomScorpionCollisions ()
{
    for ( unsigned int i = 0; i < field_->GetMushrooms ().size (); i++ )
	{
	    if ( !field_->GetScorpions ().empty () )
		{
		    for ( unsigned int j = 0; j < field_->GetScorpions ().size (); j++ )
			{
			    if ( CheckDistanceBetweenEntities ( field_->GetMushrooms ().at ( i ),
			                                        field_->GetScorpions ().at ( j ) ) <
			         ( MUSHROOM_HIT_RADIUS + SCORPION_HIT_RADIUS ) )
				{
				    field_->GetMushrooms ().at ( i ).SetPoisoned ( true );
				}
			}
		}

	    else
		break;
	}
}

void CollisionHandler::CheckMushroomSpiderCollisions ()
{
    for ( unsigned int i = 0; i < field_->GetMushrooms ().size (); i++ )
	{
	    if ( !field_->GetSpiders ().empty () )
		{
		    for ( unsigned int j = 0; j < field_->GetSpiders ().size (); j++ )
			{
			    if ( ( field_->GetMushrooms ().at ( i ).GetRegion () == ( Region::BOTTOM_LEFT ) ) ||
			         ( field_->GetMushrooms ().at ( i ).GetRegion () == Region::BOTTOM_RIGHT ) )
				{
				    if ( CheckDistanceBetweenEntities ( field_->GetMushrooms ().at ( i ),
				                                        field_->GetSpiders ().at ( j ) ) <
				         ( MUSHROOM_HIT_RADIUS + SPIDER_HIT_RADIUS ) )
					{
					    field_->GetMushrooms ().at ( i ).SetBitten ( true );
					}
				}
			}
		}

	    else
		break;
	}
}

void CollisionHandler::CheckBulletSpiderCollisions ()
{
    if ( !turret_->GetBullets ().empty () )
	{
	    for ( unsigned int i = 0; i < turret_->GetBullets ().size (); i++ )
		{
		    if ( !field_->GetSpiders ().empty () )
			{
			    // collision checking between bullets and spiders
			    for ( unsigned int j = 0; j < field_->GetSpiders ().size (); j++ )
				{
				    if ( turret_->GetBullets ().at ( i ).GetRegion () !=
				         field_->GetSpiders ().at ( j ).GetRegion () )
					{
					    continue;
					}

				    else if ( turret_->GetBullets ().at ( i ).GetSubRegion () !=
				              field_->GetSpiders ().at ( j ).GetSubRegion () )
					{
					    continue;
					}

				    else if ( CheckDistanceBetweenEntities ( field_->GetSpiders ().at ( j ),
				                                             turret_->GetBullets ().at ( i ) ) <
				              ( SPIDER_HIT_RADIUS + BULLET_HIT_RADIUS ) )
					{
					    turret_->GetBullets ().at ( i ).SetDead ( true );
					    field_->GetSpiders ().at ( j ).SetDead ( true );
					}
				}
			}

		    else
			break;
		}
	}
}

void CollisionHandler::CheckBulletMushroomCollisions ()
{
    if ( !turret_->GetBullets ().empty () )
	{
	    for ( unsigned int i = 0; i < turret_->GetBullets ().size (); i++ )
		{
		    if ( !field_->GetMushrooms ().empty () )
			{
			    // collision checking between bullets and mushrooms
			    for ( unsigned int j = 0; j < field_->GetMushrooms ().size (); j++ )
				{
				    if ( CheckDistanceBetweenEntities ( field_->GetMushrooms ().at ( j ),
				                                        turret_->GetBullets ().at ( i ) ) <
				         ( MUSHROOM_HIT_RADIUS + BULLET_HIT_RADIUS ) )
					{
					    turret_->GetBullets ().at ( i ).SetDead ( true );
					    field_->GetMushrooms ().at ( j ).DecrementLives ();

					    if ( field_->GetMushrooms ().at ( j ).GetLivesRemaining () == 0 )
						{
						    field_->GetMushrooms ().at ( j ).SetDead ( true );
						}
					}
				}
			}

		    else
			break;
		}
	}
}

float CollisionHandler::CheckDistanceBetweenEntities ( Entity& entity1, Entity& entity2 )
{
    return sqrt ( pow ( entity1.GetCenterXPosition () - entity2.GetCenterXPosition (), 2 ) +
                  pow ( entity1.GetCenterYPosition () - entity2.GetCenterYPosition (), 2 ) );
}
}  // namespace GameEngine
