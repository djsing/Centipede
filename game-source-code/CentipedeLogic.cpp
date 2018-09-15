#include "CentipedeLogic.h"
#include "CentipedeSegment.h"
#include "DEFINITIONS.h"
#include "Trajectory.h"
#include "Direction.h"
#include "Region.h"
#include "RegionHandler.h"
#include "GameWon.h"

namespace GameEngine
{
	CentipedeLogic::CentipedeLogic(DataPtr data, CentPtr centipede):
	_data(data),
	_centipede(centipede),
	_speed(CENTIPEDE_SPEED),
	_isFirstSegment(true)
	{
		
	}

	void CentipedeLogic::Spawn()
	{
		// creates 'head' spawn at first, then 'body' for the remainder
		auto segment = CentipedeSegment(_data, _isFirstSegment);
		_centipede->GetCentipede().push_back(segment);
		_isFirstSegment = false;
	}

	void CentipedeLogic::Move(float dt)
	{
		auto moveDistance = _speed*dt;
		for (unsigned int i = 0; i < _centipede->GetCentipede().size(); i++)
		{
			// move sprite moveDistance away in the current direction
			// Check whether centipede is moving to the bottom/top  of screen
			switch (_centipede->GetCentipede().at(i).GetTrajectory())
			{
				// check direction of centipede movement
				case Trajectory::DOWNWARD:
					switch (_centipede->GetCentipede().at(i).GetDirection())
					{
						case Direction::RIGHT:
						// check if square is at bottom of the screen
						if ((_centipede->GetCentipede().at(i).GetTopLeftYPosition() + SCREEN_HEIGHT_BUFFER_FACTOR*CENTIPEDE_SPRITE_SIDE_SIZE)
							>= (SCREEN_HEIGHT))
						{
							_centipede->GetCentipede().at(i).SetTrajectory(Trajectory::UPWARD);
						}	// now check if square is at right side of screen 
						else if ((_centipede->GetCentipede().at(i).GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
						{

							_centipede->GetCentipede().at(i).SetDirection(Direction::DOWN);

							_centipede->GetCentipede().at(i).SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);

							_centipede->GetCentipede().at(i).GetObjectSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());

						} 
						else
						{

							_centipede->GetCentipede().at(i).GetObjectSprite().move(moveDistance, 0);

							_centipede->GetCentipede().at(i).SetTopLeftXPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition() + moveDistance);

						}
						break;

						case Direction::DOWN:
						_centipede->GetCentipede().at(i).GetObjectSprite().move(0, CENTIPEDE_SPRITE_SIDE_SIZE);
						_centipede->GetCentipede().at(i).SetTopLeftYPosition(
							_centipede->GetCentipede().at(i).GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE);

						if (_centipede->GetCentipede().at(i).IsTurningLeft())
						{
							_centipede->GetCentipede().at(i).SetDirection(Direction::LEFT);
						} 
						else _centipede->GetCentipede().at(i).SetDirection(Direction::RIGHT);

						_centipede->GetCentipede().at(i).SetTurningLeft(!_centipede->GetCentipede().at(i).IsTurningLeft());
						break;

						case Direction::LEFT:
						if ((_centipede->GetCentipede().at(i).GetTopLeftYPosition() + SCREEN_HEIGHT_BUFFER_FACTOR*CENTIPEDE_SPRITE_SIDE_SIZE)
							>= (SCREEN_HEIGHT))
						{
							_centipede->GetCentipede().at(i).SetTrajectory(Trajectory::UPWARD);
						} 
						else if (_centipede->GetCentipede().at(i).GetTopLeftXPosition() <= SCREEN_LHS)
						{
							_centipede->GetCentipede().at(i).SetDirection(Direction::DOWN);

							_centipede->GetCentipede().at(i).SetTopLeftXPosition(SCREEN_LHS);

							_centipede->GetCentipede().at(i).GetObjectSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());
						}
						else 
						{
							_centipede->GetCentipede().at(i).GetObjectSprite().move(-moveDistance, 0);
							_centipede->GetCentipede().at(i).SetTopLeftXPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition()
								- moveDistance);
						}
						break;

						default: break;
					}
					break;
///////////////////////////////////////////////////////////////////////////////////
				case Trajectory::UPWARD:
					switch (_centipede->GetCentipede().at(i).GetDirection())
					{
						case Direction::RIGHT:
							if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= 0)
						{
							_centipede->GetCentipede().at(i).SetTrajectory(Trajectory::DOWNWARD);

							_centipede->GetCentipede().at(i).SetTopLeftYPosition(0);

							_centipede->GetCentipede().at(i).GetObjectSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());
						}
						else if ((_centipede->GetCentipede().at(i).GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
						{
							_centipede->GetCentipede().at(i).SetDirection(Direction::UP);

							_centipede->GetCentipede().at(i).SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);

							_centipede->GetCentipede().at(i).GetObjectSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());
						}
						else
						{
							_centipede->GetCentipede().at(i).GetObjectSprite().move(moveDistance, 0);
							_centipede->GetCentipede().at(i).SetTopLeftXPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition() + moveDistance);
						}
						break;

						case Direction::UP:
						_centipede->GetCentipede().at(i).GetObjectSprite().move(0, -CENTIPEDE_SPRITE_SIDE_SIZE);

						_centipede->GetCentipede().at(i).SetTopLeftYPosition(
							_centipede->GetCentipede().at(i).GetTopLeftYPosition() - CENTIPEDE_SPRITE_SIDE_SIZE);

						if (_centipede->GetCentipede().at(i).IsTurningLeft())
						{
							_centipede->GetCentipede().at(i).SetDirection(Direction::LEFT);
						}
						else _centipede->GetCentipede().at(i).SetDirection(Direction::RIGHT);

							_centipede->GetCentipede().at(i).SetTurningLeft(!_centipede->GetCentipede().at(i).IsTurningLeft());

						break;

						case Direction::LEFT:
						// x value of top left position
						if (_centipede->GetCentipede().at(i).GetTopLeftXPosition() <= SCREEN_LHS)
						{
							_centipede->GetCentipede().at(i).SetDirection(Direction::UP);

							_centipede->GetCentipede().at(i).SetTopLeftXPosition(SCREEN_LHS);

							_centipede->GetCentipede().at(i).GetObjectSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());
						}
						else 
						{
							_centipede->GetCentipede().at(i).GetObjectSprite().move(-moveDistance, 0);
							_centipede->GetCentipede().at(i).SetTopLeftXPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition()
								- moveDistance);
						}
						break;

						default: break;
					}
					break;
			}

		// update regions after moving
		auto segmentRegion = RegionHandler{_centipede->GetCentipede().at(i).GetCenterXPosition(),
			_centipede->GetCentipede().at(i).GetCenterYPosition()};
		_centipede->GetCentipede().at(i).SetRegion(segmentRegion.GetRegion());
		_centipede->GetCentipede().at(i).SetSubRegion(segmentRegion.GetSubRegion());
		}
	}

	void CentipedeLogic::CollisionHandle()
	{
		// delete collided segments 
		if (!_centipede->GetCentipede().empty())
		{
			for (unsigned int i = 0; i < _centipede->GetCentipede().size(); i++)
			{
				if (_centipede->GetCentipede().at(i).IsDead())
				{
					_centipede->GetCentipede().erase(_centipede->GetCentipede().begin() + i);
					i--;
				}
			}
		} 
		else	// if after deleting segments, the centipede is empty, end (win) the game
		{
			_data->statehandler.AddState(StatePtr(new GameWon(_data)));
		}
	}
}