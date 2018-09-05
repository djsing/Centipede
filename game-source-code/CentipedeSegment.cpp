#include "CentipedeSegment.h"
#include "Direction.h"
#include "Trajectory.h"
#include "DEFINITIONS.h"
#include "Region.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	CentipedeSegment::CentipedeSegment(DataPtr data, bool firstSegment):
	_data(data),
	_direction(Direction::RIGHT),
	_trajectory(Trajectory::DOWNWARD),
	_topLeftXPosition(0),
	_topLeftYPosition(0),
	_turningLeft(true),
	_firstSegment(firstSegment),
	_speed(500),
	_dead(false),
	_region(Region::TOP_LEFT),
	_subregion(Region::TOP_LEFT)
	{
		if (_firstSegment)
		{
		_segment.setTexture(_data->resources.GetTexture("Segment sprite"));
		_segment.setPosition(_topLeftXPosition, _topLeftYPosition);
		}
		else
		{
		_segment.setTexture(_data->resources.GetTexture("Body Segment sprite"));
		_segment.setPosition(_topLeftXPosition, _topLeftYPosition);
		}
	}

	float CentipedeSegment::GetSpeed()
	{
		return _speed;
	}

	bool CentipedeSegment::IsFirstSegment()
	{
		return _firstSegment;
	}

	bool CentipedeSegment::IsTurningLeft()
	{
		return _turningLeft;
	}

	bool CentipedeSegment::IsDead()
	{
		return _dead;
	}

	Trajectory CentipedeSegment::GetTrajectory()
	{
		return _trajectory;
	}

	Direction CentipedeSegment::GetDirection()
	{
		return _direction;
	}

	void CentipedeSegment::SetFirstSegment(bool firstSegment)
	{
		_firstSegment = firstSegment;
	}

	float CentipedeSegment::GetTopLeftXPosition()
	{
		return _topLeftXPosition;
	}

	float CentipedeSegment::GetTopLeftYPosition()
	{
		return _topLeftYPosition;
	}

	float CentipedeSegment::GetCenterXPosition()
	{
		return _topLeftXPosition + CENTIPEDE_SPRITE_SIDE_SIZE/2;
	}

	float CentipedeSegment::GetCenterYPosition()
	{
		return _topLeftYPosition + CENTIPEDE_SPRITE_SIDE_SIZE/2;
	}

	void CentipedeSegment::DrawSegments()
	{
		if (_firstSegment)
		{
		_segment.setTexture(_data->resources.GetTexture("Segment sprite"));
		}

		_data->window.draw(_segment);
	}

	void CentipedeSegment::MoveCentipedeSegments(float dt)
	{
		auto moveDistance = _speed*dt;
		// move sprite moveDistance away in the current direction
		// Check whether centipede is moving to the bottom/top  of screen
		switch (_trajectory)
		{
			// check direction of centipede movement
			case Trajectory::DOWNWARD:
				switch (_direction)
				{
					case Direction::RIGHT:
					// check if square is at bottom of the screen
					if ((_topLeftYPosition + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_HEIGHT))
					{
						_trajectory = Trajectory::UPWARD;
						_topLeftYPosition = SCREEN_HEIGHT - CENTIPEDE_SPRITE_SIDE_SIZE;
						_segment.setPosition(_topLeftXPosition, _topLeftYPosition);
					}	// now check if square is at right side of screen 
					else if ((_topLeftXPosition + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
					{
						_direction = Direction::DOWN;
						_topLeftXPosition = SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE;
						_segment.setPosition(_topLeftXPosition, _topLeftYPosition);
					} 
					else
					{
						_segment.move(moveDistance, 0);
						_topLeftXPosition += moveDistance;
					}
					break;

					case Direction::DOWN:
					_segment.move(0, CENTIPEDE_SPRITE_SIDE_SIZE);
					_topLeftYPosition += CENTIPEDE_SPRITE_SIDE_SIZE;
					if (_turningLeft)
					{
						_direction = Direction::LEFT;
					} else {_direction = Direction::RIGHT;}

						_turningLeft = !_turningLeft;
					break;

					case Direction::LEFT:
					if ((_topLeftYPosition + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_HEIGHT))
					{
						_trajectory = Trajectory::UPWARD;
					} else if (_topLeftXPosition <= 0)
					{
						_direction = Direction::DOWN;
						_topLeftXPosition = 0;
						_segment.setPosition(_topLeftXPosition, _topLeftYPosition);
					} 
					else 
					{
						_segment.move(-moveDistance, 0);
						_topLeftXPosition -= moveDistance;
					}
					break;

					default: break;
				}
				break;
///////////////////////////////////////////////////////////////////////////////////
			case Trajectory::UPWARD:
				switch (_direction)
				{
					case Direction::RIGHT:
						if (_topLeftYPosition <= 0)
					{
						_trajectory = Trajectory::DOWNWARD;
						_topLeftYPosition = 0;
						_segment.setPosition(_topLeftXPosition, _topLeftYPosition);
					}
					else if ((_topLeftXPosition + CENTIPEDE_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
					{
						_direction = Direction::UP;
						_topLeftXPosition = SCREEN_WIDTH - CENTIPEDE_SPRITE_SIDE_SIZE;
						_segment.setPosition(_topLeftXPosition, _topLeftYPosition);
					} 
					else
					{
						_segment.move(moveDistance, 0);
						_topLeftXPosition += moveDistance;
					}
					break;

					case Direction::UP:
					_segment.move(0, -CENTIPEDE_SPRITE_SIDE_SIZE);
					_topLeftYPosition -= CENTIPEDE_SPRITE_SIDE_SIZE;
					if (_turningLeft)
					{
						_direction = Direction::LEFT;
					} 
					else {_direction = Direction::RIGHT;}
						_turningLeft = !_turningLeft;
					break;

						case Direction::LEFT:
					// x value of top left position
					if (_topLeftXPosition <= 0)
					{
						_direction = Direction::UP;
						_topLeftXPosition = 0;
						_segment.setPosition(_topLeftXPosition, _topLeftYPosition);
					} 
					else 
					{
						_segment.move(-moveDistance, 0);
						_topLeftXPosition -= moveDistance;
					}
					break;

					default: break;
				}
				break;
		}
		// update regions after moving
		UpdateRegion();
	}

	void CentipedeSegment::UpdateRegion()
	{	// left side of screen
		if (_topLeftXPosition <= (SCREEN_WIDTH/2 - CENTIPEDE_SPRITE_SIDE_SIZE))
		{
			// top half of screen
			if (_topLeftYPosition <= (SCREEN_HEIGHT/2 - CENTIPEDE_SPRITE_SIDE_SIZE))
			{
				_region = Region::TOP_LEFT;
				// left side of top left quarter
				if (_topLeftXPosition <= (SCREEN_WIDTH/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
				{
					// top half of left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right side of top left quarter
				else
				{
					// top half of left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
			// bottom half of screen
			else
			{
				_region = Region::BOTTOM_LEFT;
				// left half of bottom left quarter
				if (_topLeftXPosition <= (SCREEN_WIDTH/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
				{
					// top half of bottom left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of bottom left quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right half of bottom left quarter
				else
				{
					// top half of left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
		}
		// right side of screen
		else
		{
			// top half of screen
			if (_topLeftYPosition <= (SCREEN_HEIGHT/2 - CENTIPEDE_SPRITE_SIDE_SIZE))
			{
				_region = Region::TOP_RIGHT;
				// left half of top right quarter
				if (_topLeftXPosition <= (SCREEN_WIDTH*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
				{
					// top half of left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right side of top right quarter
				else
				{
					// top half of top right quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of top right quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
			// bottom half of screen
			else
			{
				_region = Region::BOTTOM_RIGHT;
				// 
				if (_topLeftXPosition <= (SCREEN_WIDTH*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
				{
					// top half of right bottom quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of right bottom quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right side of bottom right quarter
				else
				{
					// top half of left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT*3/4 - CENTIPEDE_SPRITE_SIDE_SIZE))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
		}
	}
}