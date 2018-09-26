#include "CentipedeLogic.h"
#include "CentipedeSegment.h"
#include "DEFINITIONS.h"
#include "Direction.h"
#include "GameWon.h"
#include "Trajectory.h"

namespace GameEngine
{
	CentipedeLogic::CentipedeLogic ( DataPtr data, CentPtr centipede )
		: data_ ( data )
		, centipede_ ( centipede )
		, speed_ ( CENTIPEDE_SPEED )
		, move_distance_ ( 0 )
		, number_of_centipede_segments_ ( 0 )
	{

	}

	void CentipedeLogic::Spawn()
	{
		if ( ( centipede_->GetLastSpriteXPosition() >= CENTIPEDE_SPRITE_SIDE_SIZE ) &&
		        ( number_of_centipede_segments_ < INITIAL_CENTIPEDE_NUMBER ) )
			{
				if ( centipede_->GetCentipede().empty() )
					{
						// creates 'head' spawn at first, then 'body' for the remainder
						auto segment = CentipedeSegment ( true );
						centipede_->GetCentipede().push_back ( segment );
					}

				else
					{
						auto segment = CentipedeSegment ();
						centipede_->GetCentipede().push_back ( segment );
					}

				number_of_centipede_segments_++;
			}
	}

	void CentipedeLogic::Move ( float dt )
	{
		move_distance_ = speed_ * dt;

		for ( unsigned int i = 0; i < centipede_->GetCentipede().size(); i++ )
			{
				// if segment is poisoned, move downwards
				if ( centipede_->GetCentipede().at ( i ).IsPoisoned() )
					{
						centipede_->GetCentipede().at ( i ).SetTopLeftYPosition (
						    centipede_->GetCentipede().at ( i ).GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE );

						// once in turret area, resume normal behaviour
						if ( centipede_->GetCentipede().at ( i ).GetTopLeftYPosition() >= TURRET_SCREEN_FRACTION * SCREEN_HEIGHT )
							{
								centipede_->GetCentipede().at ( i ).SetPoisoned ( false );

								if ( centipede_->GetCentipede().at ( i ).GetTrajectory() == Trajectory::UPWARD )
									{
										centipede_->GetCentipede().at ( i ).SetTrajectory ( Trajectory::DOWNWARD );
										centipede_->GetCentipede().at ( i ).SetDirection ( Direction::DOWN );
									}

								continue;
							}

						continue;
					}

				// move sprite moveDistance away in the current direction
				// Check whether centipede is moving to the bottom/top  of screen
				switch ( centipede_->GetCentipede().at ( i ).GetTrajectory() )
					{
					// check direction of centipede movement
					case Trajectory::DOWNWARD:
						switch ( centipede_->GetCentipede().at ( i ).GetDirection() )
							{
							case Direction::RIGHT:
								MoveRight ( Trajectory::DOWNWARD, i );
								break;

							case Direction::DOWN:
								MoveDown ( i );
								break;

							case Direction::LEFT:
								MoveLeft ( Trajectory::DOWNWARD, i );
								break;

							default:
								break;
							}

						break;

					case Trajectory::UPWARD:
						switch ( centipede_->GetCentipede().at ( i ).GetDirection() )
							{
							case Direction::RIGHT:
								MoveRight ( Trajectory::UPWARD, i );
								break;

							case Direction::UP:
								MoveUp ( i );
								break;

							case Direction::LEFT:
								MoveLeft ( Trajectory::UPWARD, i );
								break;

							default:
								break;
							}

						break;
					}
			}
	}

	void CentipedeLogic::CollisionHandle()
	{
		// delete collided segments
		if ( !centipede_->GetCentipede().empty() )
			{
				auto dead = std::find ( centipede_->GetCentipede().begin(), centipede_->GetCentipede().end(), true );

				while ( dead != centipede_->GetCentipede().end() )
					{
						centipede_->GetCentipede().erase ( dead );
						dead = std::find ( dead, centipede_->GetCentipede().end(), true );
					}
			}

		// if after deleting segments, the centipede is empty, end (win) the game
		if ( centipede_->GetCentipede().empty() )
			{
				data_->statehandler.AddState ( StatePtr ( new GameWon ( data_ ) ) );
			}
	}

	void CentipedeLogic::MoveDown ( int index )
	{
		centipede_->GetCentipede().at ( index ).SetTopLeftYPosition (
		    centipede_->GetCentipede().at ( index ).GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE );

		if ( centipede_->GetCentipede().at ( index ).IsTurningLeft() )
			{
				centipede_->GetCentipede().at ( index ).SetDirection ( Direction::LEFT );
			}

		else
			centipede_->GetCentipede().at ( index ).SetDirection ( Direction::RIGHT );

		centipede_->GetCentipede().at ( index ).SetTurningLeft ( !centipede_->GetCentipede().at ( index ).IsTurningLeft() );
	}

	void CentipedeLogic::MoveUp ( int index )
	{
		centipede_->GetCentipede().at ( index ).SetTopLeftYPosition (
		    centipede_->GetCentipede().at ( index ).GetTopLeftYPosition() - CENTIPEDE_SPRITE_SIDE_SIZE );

		if ( centipede_->GetCentipede().at ( index ).IsTurningLeft() )
			{
				centipede_->GetCentipede().at ( index ).SetDirection ( Direction::LEFT );
			}

		else
			centipede_->GetCentipede().at ( index ).SetDirection ( Direction::RIGHT );

		centipede_->GetCentipede().at ( index ).SetTurningLeft ( !centipede_->GetCentipede().at ( index ).IsTurningLeft() );
	}

	void CentipedeLogic::MoveLeft ( Trajectory trajectory, int index )
	{
		switch ( trajectory )
			{
			case Trajectory::UPWARD:

				// x value of top left position
				if ( centipede_->GetCentipede().at ( index ).GetTopLeftYPosition() <= SCREEN_TOP )
					{
						centipede_->GetCentipede().at ( index ).SetTrajectory ( Trajectory::DOWNWARD );
						centipede_->GetCentipede().at ( index ).SetTopLeftYPosition ( SCREEN_TOP );
					}

				else if ( centipede_->GetCentipede().at ( index ).GetTopLeftXPosition() <= SCREEN_LHS )
					{
						centipede_->GetCentipede().at ( index ).SetDirection ( Direction::UP );
						centipede_->GetCentipede().at ( index ).SetTopLeftXPosition ( SCREEN_LHS );
					}

				else
					{
						centipede_->GetCentipede().at ( index ).SetTopLeftXPosition (
						    centipede_->GetCentipede().at ( index ).GetTopLeftXPosition() - move_distance_ );
					}

				break;

			case Trajectory::DOWNWARD:
				if ( ( centipede_->GetCentipede().at ( index ).GetTopLeftYPosition() +
				        SCREEN_HEIGHT_BUFFER_FACTOR * CENTIPEDE_SPRITE_SIDE_SIZE ) >= ( SCREEN_HEIGHT ) )
					{
						centipede_->GetCentipede().at ( index ).SetTrajectory ( Trajectory::UPWARD );
					}

				else if ( centipede_->GetCentipede().at ( index ).GetTopLeftXPosition() <= SCREEN_LHS )
					{
						centipede_->GetCentipede().at ( index ).SetDirection ( Direction::DOWN );
						centipede_->GetCentipede().at ( index ).SetTopLeftXPosition ( SCREEN_LHS );
					}

				else
					{
						centipede_->GetCentipede().at ( index ).SetTopLeftXPosition (
						    centipede_->GetCentipede().at ( index ).GetTopLeftXPosition() - move_distance_ );
					}

				break;
			}
	}

	void CentipedeLogic::MoveRight ( Trajectory trajectory, int index )
	{
		switch ( trajectory )
			{
			case Trajectory::UPWARD:
				if ( centipede_->GetCentipede().at ( index ).GetTopLeftYPosition() <= SCREEN_TOP )
					{
						centipede_->GetCentipede().at ( index ).SetTrajectory ( Trajectory::DOWNWARD );
						centipede_->GetCentipede().at ( index ).SetTopLeftYPosition ( SCREEN_TOP );
					}

				else if ( ( centipede_->GetCentipede().at ( index ).GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE ) >=
				          ( SCREEN_WIDTH ) )
					{
						centipede_->GetCentipede().at ( index ).SetDirection ( Direction::UP );
						centipede_->GetCentipede().at ( index ).SetTopLeftXPosition ( SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE );
					}

				else
					{
						centipede_->GetCentipede().at ( index ).SetTopLeftXPosition (
						    centipede_->GetCentipede().at ( index ).GetTopLeftXPosition() + move_distance_ );
					}

				break;

			case Trajectory::DOWNWARD:

				// check if square is at bottom of the screen
				if ( ( centipede_->GetCentipede().at ( index ).GetTopLeftYPosition() +
				        SCREEN_HEIGHT_BUFFER_FACTOR * CENTIPEDE_SPRITE_SIDE_SIZE ) >= ( SCREEN_HEIGHT ) )
					{
						centipede_->GetCentipede().at ( index ).SetTrajectory ( Trajectory::UPWARD );
					} // now check if square is at right side of screen

				else if ( ( centipede_->GetCentipede().at ( index ).GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE ) >=
				          ( SCREEN_WIDTH ) )
					{
						centipede_->GetCentipede().at ( index ).SetDirection ( Direction::DOWN );
						centipede_->GetCentipede().at ( index ).SetTopLeftXPosition ( SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE );
					}

				else
					{
						centipede_->GetCentipede().at ( index ).SetTopLeftXPosition (
						    centipede_->GetCentipede().at ( index ).GetTopLeftXPosition() + move_distance_ );
					}

				break;
			}
	}
} // namespace GameEngine
