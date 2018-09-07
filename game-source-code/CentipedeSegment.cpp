#include "CentipedeSegment.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	CentipedeSegment::CentipedeSegment(DataPtr data, bool firstSegment):
	_data(data),
	_turningLeft(true),
	_direction(Direction::RIGHT),
	_trajectory(Trajectory::DOWNWARD),
	_topLeftXPosition(0),
	_topLeftYPosition(0),
	_region(Region::TOP_LEFT),
	_subregion(Region::TOP_LEFT),
	_firstSegment(firstSegment),
	_speed(500),
	_dead(false)
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

	sf::Sprite &CentipedeSegment::GetSegmentSprite()
	{
		return _segment;
	}


	void CentipedeSegment::SetDirection(Direction direction)
	{
		_direction = direction;
	}

	void CentipedeSegment::SetTrajectory(Trajectory trajectory)
	{
		_trajectory = trajectory;
	}

	void CentipedeSegment::SetTopLeftXPosition(float xpos)
	{
		_topLeftXPosition = xpos;
	}

	void CentipedeSegment::SetTopLeftYPosition(float ypos)
	{
		_topLeftYPosition = ypos;
	}

	void CentipedeSegment::SetTurningLeft(bool isTurningLeft)
	{
		_turningLeft = isTurningLeft;
	}

	void CentipedeSegment::SetRegion(Region region)
	{
		_region = region;
	}

	void CentipedeSegment::SetSubRegion(Region subregion)
	{
		_subregion = subregion;
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
}