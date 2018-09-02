#include "CentipedeSegment.h"
#include "Direction.h"
#include "Trajectory.h"
#include "DEFINITIONS.h"
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
	_firstSegment(false),
	_speed(500)
	{
		setFirstSegment(firstSegment);

		if (_firstSegment)
		{
		_segment.setTexture(_data->resources.GetTexture("Segment sprite"));
		_segment.setPosition(0, 0);
		}
		else
		{
		_segment.setTexture(_data->resources.GetTexture("Body Segment sprite"));
		_segment.setPosition(0, 0);
		}
	}

	void CentipedeSegment::setFirstSegment(bool firstSegment)
	{
		_firstSegment = firstSegment;
	}

	float CentipedeSegment::GetTopLeftXPosition()
	{
		return _topLeftXPosition;
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

					case Direction::UP:
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

					case Direction::DOWN:
					default: break;
				}
				break;
		}
	}
}