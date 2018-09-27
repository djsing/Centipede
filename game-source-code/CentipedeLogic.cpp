#include "CentipedeLogic.h"
#include "CentipedeSegment.h"
#include "DEFINITIONS.h"
#include "Direction.h"
#include "GameWon.h"
#include "Trajectory.h"

namespace GameEngine
{
CentipedeLogic::CentipedeLogic(DataPtr data, CentPtr centipede)
    : data_(data), centipede_(centipede), speed_(CENTIPEDE_SPEED), move_distance_(0), number_of_centipede_segments_(0)
{
}

void CentipedeLogic::Spawn()
{
    if(centipede_->GetLastSpriteXPosition() >= CENTIPEDE_SPRITE_SIDE_SIZE &&
       number_of_centipede_segments_ < INITIAL_CENTIPEDE_NUMBER)
	{
	    if(centipede_->GetCentipede().empty())
		{
		    // creates 'head' spawn at first, then 'body' for the remainder
		    auto segment = CentipedeSegment(true);
		    centipede_->GetCentipede().push_back(segment);
		}

	    else
		{
		    auto segment = CentipedeSegment();
		    centipede_->GetCentipede().push_back(segment);
		}

	    number_of_centipede_segments_++;
	}
}

void CentipedeLogic::Move(float dt)
{
    move_distance_ = speed_ * dt;

    for(auto& i : centipede_->GetCentipede())
	{
	    // if segment is poisoned, move downwards
	    if(i.IsPoisoned())
		{
		    i.SetTopLeftYPosition(i.GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE);

		    // once in turret area, resume normal behaviour
		    if(i.GetTopLeftYPosition() >= TURRET_SCREEN_FRACTION * SCREEN_HEIGHT)
			{
			    i.SetPoisoned(false);

			    if(i.GetTrajectory() == Trajectory::UPWARD)
				{
				    i.SetTrajectory(Trajectory::DOWNWARD);
				    i.SetDirection(Direction::DOWN);
				}

			    continue;
			}

		    continue;
		}

	    // move sprite moveDistance away in the current direction
	    // Check whether centipede is moving to the bottom/top  of screen
	    switch(i.GetTrajectory())
		{
		    // check direction of centipede movement
		    case Trajectory::DOWNWARD:
			switch(i.GetDirection())
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
			switch(i.GetDirection())
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
    // find dead segments, and set the next segment in the centipede to be a head
    auto it = std::find(centipede_->GetCentipede().begin(), centipede_->GetCentipede().end() - 1, true);
    while(it != centipede_->GetCentipede().end() - 1)
	{
	    it++;
	    it->SetFirstSegment(true);
	    it = std::find(it, centipede_->GetCentipede().end() - 1, true);
	}

    // for poisoned segments, set the next segment to a head
    for(unsigned int i = 0; i < centipede_->GetCentipede().size(); i++)
	{
	    if(centipede_->GetCentipede().size() != i + 1 && centipede_->GetCentipede().at(i).IsPoisoned())
		{
		    centipede_->GetCentipede().at(i + 1).SetFirstSegment(true);
		}
	}

    // delete collided segments
    if(!centipede_->GetCentipede().empty())
	{
	    auto deadBegin = std::remove(centipede_->GetCentipede().begin(), centipede_->GetCentipede().end(), true);
	    centipede_->GetCentipede().erase(deadBegin, centipede_->GetCentipede().end());
	}

    // if after deleting segments, the centipede is empty, end (win) the game
    if(centipede_->GetCentipede().empty())
	{
	    data_->statehandler.AddState(StatePtr(new GameWon(data_)));
	}
}

void CentipedeLogic::MoveDown(CentipedeSegment& index)
{
    index.SetTopLeftYPosition(index.GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE);

    if(index.IsTurningLeft())
	{
	    index.SetDirection(Direction::LEFT);
	}

    else
	index.SetDirection(Direction::RIGHT);

    index.SetTurningLeft(!index.IsTurningLeft());
}

void CentipedeLogic::MoveUp(CentipedeSegment& index)
{
    index.SetTopLeftYPosition(index.GetTopLeftYPosition() - CENTIPEDE_SPRITE_SIDE_SIZE);

    if(index.IsTurningLeft())
	{
	    index.SetDirection(Direction::LEFT);
	}

    else
	index.SetDirection(Direction::RIGHT);

    index.SetTurningLeft(!index.IsTurningLeft());
}

void CentipedeLogic::MoveLeft(Trajectory trajectory, CentipedeSegment& index)
{
    switch(trajectory)
	{
	    case Trajectory::UPWARD:

		// x value of top left position
		if(index.GetTopLeftYPosition() <= SCREEN_TOP)
		    {
			index.SetTrajectory(Trajectory::DOWNWARD);
			index.SetTopLeftYPosition(SCREEN_TOP);
		    }

		else if(index.GetTopLeftXPosition() <= SCREEN_LHS)
		    {
			index.SetDirection(Direction::UP);
			index.SetTopLeftXPosition(SCREEN_LHS);
		    }

		else
		    {
			index.SetTopLeftXPosition(index.GetTopLeftXPosition() - move_distance_);
		    }

		break;

	    case Trajectory::DOWNWARD:
		if((index.GetTopLeftYPosition() + SCREEN_HEIGHT_BUFFER_FACTOR * CENTIPEDE_SPRITE_SIDE_SIZE) >=
		   (SCREEN_HEIGHT))
		    {
			index.SetTrajectory(Trajectory::UPWARD);
		    }

		else if(index.GetTopLeftXPosition() <= SCREEN_LHS)
		    {
			index.SetDirection(Direction::DOWN);
			index.SetTopLeftXPosition(SCREEN_LHS);
		    }

		else
		    {
			index.SetTopLeftXPosition(index.GetTopLeftXPosition() - move_distance_);
		    }

		break;
	}
}

void CentipedeLogic::MoveRight(Trajectory trajectory, CentipedeSegment& index)
{
    switch(trajectory)
	{
	    case Trajectory::UPWARD:
		if(index.GetTopLeftYPosition() <= SCREEN_TOP)
		    {
			index.SetTrajectory(Trajectory::DOWNWARD);
			index.SetTopLeftYPosition(SCREEN_TOP);
		    }

		else if((index.GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
		    {
			index.SetDirection(Direction::UP);
			index.SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);
		    }

		else
		    {
			index.SetTopLeftXPosition(index.GetTopLeftXPosition() + move_distance_);
		    }

		break;

	    case Trajectory::DOWNWARD:

		// check if square is at bottom of the screen
		if((index.GetTopLeftYPosition() + SCREEN_HEIGHT_BUFFER_FACTOR * CENTIPEDE_SPRITE_SIDE_SIZE) >=
		   (SCREEN_HEIGHT))
		    {
			index.SetTrajectory(Trajectory::UPWARD);
		    }  // now check if square is at right side of screen

		else if((index.GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
		    {
			index.SetDirection(Direction::DOWN);
			index.SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);
		    }

		else
		    {
			index.SetTopLeftXPosition(index.GetTopLeftXPosition() + move_distance_);
		    }

		break;
	}
}
}  // namespace GameEngine
