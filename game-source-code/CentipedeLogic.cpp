#include "CentipedeLogic.h"
#include "CentipedeSegment.h"
#include "DEFINITIONS.h"
#include "Trajectory.h"
#include "Direction.h"
#include "Region.h"

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
						if ((_centipede->GetCentipede().at(i).GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_HEIGHT))
						{

							_centipede->GetCentipede().at(i).SetTrajectory(Trajectory::UPWARD);

							_centipede->GetCentipede().at(i).SetTopLeftYPosition(SCREEN_HEIGHT - CENTIPEDE_SPRITE_SIDE_SIZE);

							_centipede->GetCentipede().at(i).GetSegmentSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(), 
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());

						}	// now check if square is at right side of screen 
						else if ((_centipede->GetCentipede().at(i).GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
						{

							_centipede->GetCentipede().at(i).SetDirection(Direction::DOWN);

							_centipede->GetCentipede().at(i).SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);

							_centipede->GetCentipede().at(i).GetSegmentSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());

						} 
						else
						{

							_centipede->GetCentipede().at(i).GetSegmentSprite().move(moveDistance, 0);

							_centipede->GetCentipede().at(i).SetTopLeftXPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition() + moveDistance);

						}
						break;

						case Direction::DOWN:
						_centipede->GetCentipede().at(i).GetSegmentSprite().move(0, CENTIPEDE_SPRITE_SIDE_SIZE);
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
						if ((_centipede->GetCentipede().at(i).GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_HEIGHT))
						{
							_centipede->GetCentipede().at(i).SetTrajectory(Trajectory::UPWARD);
						} 
						else if (_centipede->GetCentipede().at(i).GetTopLeftXPosition() <= 0)
						{
							_centipede->GetCentipede().at(i).SetDirection(Direction::DOWN);

							_centipede->GetCentipede().at(i).SetTopLeftXPosition(0);

							_centipede->GetCentipede().at(i).GetSegmentSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());
						}
						else 
						{
							_centipede->GetCentipede().at(i).GetSegmentSprite().move(-moveDistance, 0);
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

							_centipede->GetCentipede().at(i).GetSegmentSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());
						}
						else if ((_centipede->GetCentipede().at(i).GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
						{
							_centipede->GetCentipede().at(i).SetDirection(Direction::UP);

							_centipede->GetCentipede().at(i).SetTopLeftXPosition(SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE);

							_centipede->GetCentipede().at(i).GetSegmentSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());
						}
						else
						{
							_centipede->GetCentipede().at(i).GetSegmentSprite().move(moveDistance, 0);
							_centipede->GetCentipede().at(i).SetTopLeftXPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition() + moveDistance);
						}
						break;

						case Direction::UP:
						_centipede->GetCentipede().at(i).GetSegmentSprite().move(0, -CENTIPEDE_SPRITE_SIDE_SIZE);

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
						if (_centipede->GetCentipede().at(i).GetTopLeftXPosition() <= 0)
						{
							_centipede->GetCentipede().at(i).SetDirection(Direction::UP);

							_centipede->GetCentipede().at(i).SetTopLeftXPosition(0);

							_centipede->GetCentipede().at(i).GetSegmentSprite().setPosition(
								_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
								_centipede->GetCentipede().at(i).GetTopLeftYPosition());
						}
						else 
						{
							_centipede->GetCentipede().at(i).GetSegmentSprite().move(-moveDistance, 0);
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
		UpdateRegion(i);
		}
	}

	void CentipedeLogic::CollisionHandle()
	{
		// delete collided segments 
		for (unsigned int i = 0; i < _centipede->GetCentipede().size(); i++)
		{
			if (_centipede->GetCentipede().at(i).IsDead())
			{
				_centipede->GetCentipede().erase(_centipede->GetCentipede().begin() + i);
				i--;
			}
		}
	}

	void CentipedeLogic::UpdateRegion(unsigned int i)
	{
		if (_centipede->GetCentipede().at(i).GetTopLeftXPosition() <= (SCREEN_WIDTH/2 - CENTIPEDE_SPRITE_SIDE_SIZE))
		{
			// top half of screen
			if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= (SCREEN_HEIGHT/2 - CENTIPEDE_SPRITE_SIDE_SIZE))
			{
				_centipede->GetCentipede().at(i).SetRegion(Region::TOP_LEFT);
				// left side of top left quarter
				if (_centipede->GetCentipede().at(i).GetTopLeftXPosition() <= (SCREEN_WIDTH/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
				{
					// top half of left quarter
					if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= (SCREEN_HEIGHT/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::TOP_LEFT);
					}
					// bottom half of left quarter
					else
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::BOTTOM_LEFT);
					}
				}
				// right side of top left quarter
				else
				{
					// top half of left quarter
					if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= (SCREEN_HEIGHT/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::TOP_RIGHT);
					}
					// bottom half of left quarter
					else
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::BOTTOM_RIGHT);
					}
				}
			}
			// bottom half of screen
			else
			{
				_centipede->GetCentipede().at(i).SetRegion(Region::BOTTOM_LEFT);
				// left half of bottom left quarter
				if (_centipede->GetCentipede().at(i).GetTopLeftXPosition() <= (SCREEN_WIDTH/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
				{
					// top half of bottom left quarter
					if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= (SCREEN_HEIGHT*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::TOP_LEFT);
					}
					// bottom half of bottom left quarter
					else
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::BOTTOM_LEFT);
					}
				}
				// right half of bottom left quarter
				else
				{
					// top half of left quarter
					if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= (SCREEN_HEIGHT*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::TOP_RIGHT);
					}
					// bottom half of left quarter
					else
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::BOTTOM_RIGHT);
					}
				}
			}
		}
		// right side of screen
		else
		{
			// top half of screen
			if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= (SCREEN_HEIGHT/2 - CENTIPEDE_SPRITE_SIDE_SIZE))
			{
				_centipede->GetCentipede().at(i).SetRegion(Region::TOP_RIGHT);
				// left half of top right quarter
				if (_centipede->GetCentipede().at(i).GetTopLeftXPosition() <= (SCREEN_WIDTH*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
				{
					// top half of left quarter
					if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= (SCREEN_HEIGHT/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::TOP_LEFT);
					}
					// bottom half of left quarter
					else
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::BOTTOM_LEFT);
					}
				}
				// right side of top right quarter
				else
				{
					// top half of top right quarter
					if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= (SCREEN_HEIGHT/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::TOP_RIGHT);
					}
					// bottom half of top right quarter
					else
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::BOTTOM_RIGHT);
					}
				}
			}
			// bottom half of screen
			else
			{
				_centipede->GetCentipede().at(i).SetRegion(Region::BOTTOM_RIGHT);
				// 
				if (_centipede->GetCentipede().at(i).GetTopLeftXPosition() <= (SCREEN_WIDTH*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
				{
					// top half of right bottom quarter
					if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= (SCREEN_HEIGHT*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::TOP_LEFT);
					}
					// bottom half of right bottom quarter
					else
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::BOTTOM_LEFT);
					}
				}
				// right side of bottom right quarter
				else
				{
					// top half of left quarter
					if (_centipede->GetCentipede().at(i).GetTopLeftYPosition() <= (SCREEN_HEIGHT*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::TOP_RIGHT);
					}
					// bottom half of left quarter
					else
					{
						_centipede->GetCentipede().at(i).SetSubRegion(Region::BOTTOM_RIGHT);
					}
				}
			}
		}
	}
}