#include "CentipedeSegment.h"
#include "Trajectory.h"
#include "Direction.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
namespace GameEngine
{
	CentipedeSegment::CentipedeSegment(DataPtr data):
	_data(data),
	_direction(Direction::RIGHT),
	_trajecory(Trajectory::DOWNWARD),
	_topLeftPosition(0),
	_turningLeft(true)
	{
		
	}

	void CentipedeSegment::MoveSprite(int x, int y)
	{
		_segmentSprite.move(x,y);
	}

	void CentipedeSegment::SetDirection(Direction direction)
	{
		_direction = direction;
	}

	Direction CentipedeSegment::GetDirection()
	{
		return _direction;
	}

	void CentipedeSegment::SetTrajectory(Trajectory trajectory)
	{
		_trajecory = trajectory;
	}

	Trajectory CentipedeSegment::GetTrajectory()
	{
		return _trajecory;
	}

	int CentipedeSegment::GetTopLeftPosition()
	{
		return _topLeftPosition;
	}

	void CentipedeSegment::SetTurningLeft()
	{
		_turningLeft = !_turningLeft;
	}
}