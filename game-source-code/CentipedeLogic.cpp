#include "CentipedeLogic.h"
#include "CentipedeSegment.h"
#include "DEFINITIONS.h"
#include "Direction.h"
#include "GameWon.h"
#include "Trajectory.h"

namespace GameEngine
{
CentipedeLogic::CentipedeLogic(DataPtr data, CentPtr centipede)
    : _data(data)
    , _centipede(centipede)
    , _speed(CENTIPEDE_SPEED)
    , _isFirstSegment(true)
    , _moveDistance(0)
    , _numberOfCentipedeSegments(0)
{
}

void CentipedeLogic::Spawn()
{
    if((_centipede->GetLastSpriteXPosition() >= CENTIPEDE_SPRITE_SIDE_SIZE) &&
       (_numberOfCentipedeSegments < INITIAL_CENTIPEDE_NUMBER))
	{
	    // creates 'head' spawn at first, then 'body' for the remainder
	    auto segment = CentipedeSegment(_data, _isFirstSegment);
	    _centipede->GetCentipede().push_back(segment);
	    _numberOfCentipedeSegments++;
	}
    _isFirstSegment = false;
}

void CentipedeLogic::Move(float dt)
{
    _moveDistance = _speed * dt;
    for(unsigned int i = 0; i < _centipede->GetCentipede().size(); i++)
	{
	    // if segment is poisoned, move downwards
	    if(_centipede->GetCentipede().at(i).IsPoisoned())
		{
		    _centipede->GetCentipede().at(i).SetTopLeftYPosition(
		        _centipede->GetCentipede().at(i).GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE);
		    // once in turret area, resume normal behaviour
		    if(_centipede->GetCentipede().at(i).GetTopLeftYPosition() >= TURRET_SCREEN_FRACTION * SCREEN_HEIGHT)
			{
			    _centipede->GetCentipede().at(i).SetPoisoned(false);
			    continue;
			}
		    continue;
		}

	    // move sprite moveDistance away in the current direction
	    // Check whether centipede is moving to the bottom/top  of screen
	    switch(_centipede->GetCentipede().at(i).GetTrajectory())
		{
		// check direction of centipede movement
		case Trajectory::DOWNWARD:
		    switch(_centipede->GetCentipede().at(i).GetDirection())
			{
			case Direction::RIGHT:
			    MoveRight(Trajectory::DOWNWARD, i);
			    break;

			case Direction::DOWN:
			    MoveDown(i);
			    break;

			case Direction::LEFT:
			    MoveLeft(Trajectory::DOWNWARD, i);
			    break;

			default:
			    break;
			}
		    break;

		case Trajectory::UPWARD:
		    switch(_centipede->GetCentipede().at(i).GetDirection())
			{
			case Direction::RIGHT:
			    MoveRight(Trajectory::UPWARD, i);
			    break;

			case Direction::UP:
			    MoveUp(i);
			    break;

			case Direction::LEFT:
			    MoveLeft(Trajectory::UPWARD, i);
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
    if(!_centipede->GetCentipede().empty())
	{
	    for(unsigned int i = 0; i < _centipede->GetCentipede().size(); i++)
		{
		    if(_centipede->GetCentipede().at(i).IsDead())
			{
			    _centipede->GetCentipede().erase(_centipede->GetCentipede().begin() + i);
			    i--;
			}
		}
	}
    else // if after deleting segments, the centipede is empty, end (win) the game
	{
	    _data->statehandler.AddState(StatePtr(new GameWon(_data)));
	}
}

void CentipedeLogic::MoveDown(int index)
{
    _centipede->GetCentipede().at(index).SetTopLeftYPosition(
        _centipede->GetCentipede().at(index).GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE);

    if(_centipede->GetCentipede().at(index).IsTurningLeft())
	{
	    _centipede->GetCentipede().at(index).SetDirection(Direction::LEFT);
	}
    else
	_centipede->GetCentipede().at(index).SetDirection(Direction::RIGHT);

    _centipede->GetCentipede().at(index).SetTurningLeft(!_centipede->GetCentipede().at(index).IsTurningLeft());
}

void CentipedeLogic::MoveUp(int index)
{
    _centipede->GetCentipede().at(index).SetTopLeftYPosition(
        _centipede->GetCentipede().at(index).GetTopLeftYPosition() - CENTIPEDE_SPRITE_SIDE_SIZE);

    if(_centipede->GetCentipede().at(index).IsTurningLeft())
	{
	    _centipede->GetCentipede().at(index).SetDirection(Direction::LEFT);
	}
    else
	_centipede->GetCentipede().at(index).SetDirection(Direction::RIGHT);

    _centipede->GetCentipede().at(index).SetTurningLeft(!_centipede->GetCentipede().at(index).IsTurningLeft());
}

void CentipedeLogic::MoveLeft(Trajectory trajectory, int index)
{
    switch(trajectory)
	{
	case Trajectory::UPWARD:
	    // x value of top left position
	    if(_centipede->GetCentipede().at(index).GetTopLeftYPosition() <= SCREEN_TOP)
		{
		    _centipede->GetCentipede().at(index).SetTrajectory(Trajectory::DOWNWARD);
		    _centipede->GetCentipede().at(index).SetTopLeftYPosition(SCREEN_TOP);
		}
	    else if(_centipede->GetCentipede().at(index).GetTopLeftXPosition() <= SCREEN_LHS)
		{
		    _centipede->GetCentipede().at(index).SetDirection(Direction::UP);
		    _centipede->GetCentipede().at(index).SetTopLeftXPosition(SCREEN_LHS);
		}
	    else
		{
		    _centipede->GetCentipede().at(index).SetTopLeftXPosition(
		        _centipede->GetCentipede().at(index).GetTopLeftXPosition() - _moveDistance);
		}
	    break;

	case Trajectory::DOWNWARD:
	    if((_centipede->GetCentipede().at(index).GetTopLeftYPosition() +
	        SCREEN_HEIGHT_BUFFER_FACTOR * CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_HEIGHT))
		{
		    _centipede->GetCentipede().at(index).SetTrajectory(Trajectory::UPWARD);
		}
	    else if(_centipede->GetCentipede().at(index).GetTopLeftXPosition() <= SCREEN_LHS)
		{
		    _centipede->GetCentipede().at(index).SetDirection(Direction::DOWN);
		    _centipede->GetCentipede().at(index).SetTopLeftXPosition(SCREEN_LHS);
		}
	    else
		{
		    _centipede->GetCentipede().at(index).SetTopLeftXPosition(
		        _centipede->GetCentipede().at(index).GetTopLeftXPosition() - _moveDistance);
		}
	    break;
	}
}

void CentipedeLogic::MoveRight(Trajectory trajectory, int index)
{
    switch(trajectory)
	{
	case Trajectory::UPWARD:
	    if(_centipede->GetCentipede().at(index).GetTopLeftYPosition() <= SCREEN_TOP)
		{
		    _centipede->GetCentipede().at(index).SetTrajectory(Trajectory::DOWNWARD);
		    _centipede->GetCentipede().at(index).SetTopLeftYPosition(SCREEN_TOP);
		}
	    else if((_centipede->GetCentipede().at(index).GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE) >=
	            (SCREEN_WIDTH))
		{
		    _centipede->GetCentipede().at(index).SetDirection(Direction::UP);
		    _centipede->GetCentipede().at(index).SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);
		}
	    else
		{
		    _centipede->GetCentipede().at(index).SetTopLeftXPosition(
		        _centipede->GetCentipede().at(index).GetTopLeftXPosition() + _moveDistance);
		}
	    break;

	case Trajectory::DOWNWARD:
	    // check if square is at bottom of the screen
	    if((_centipede->GetCentipede().at(index).GetTopLeftYPosition() +
	        SCREEN_HEIGHT_BUFFER_FACTOR * CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_HEIGHT))
		{
		    _centipede->GetCentipede().at(index).SetTrajectory(Trajectory::UPWARD);
		} // now check if square is at right side of screen
	    else if((_centipede->GetCentipede().at(index).GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE) >=
	            (SCREEN_WIDTH))
		{
		    _centipede->GetCentipede().at(index).SetDirection(Direction::DOWN);
		    _centipede->GetCentipede().at(index).SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);
		}
	    else
		{
		    _centipede->GetCentipede().at(index).SetTopLeftXPosition(
		        _centipede->GetCentipede().at(index).GetTopLeftXPosition() + _moveDistance);
		}
	    break;
	}
}
} // namespace GameEngine