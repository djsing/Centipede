#include "CentipedeSegment.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	CentipedeSegment::CentipedeSegment(DataPtr data, bool firstSegment):
	Entity(SCREEN_LHS, SCREEN_TOP),
	_data(data),
	_turningLeft(true),
	_trajectory(Trajectory::DOWNWARD),
	_firstSegment(firstSegment)
	{
		Entity::SetDirection(Direction::RIGHT);
		if (_firstSegment)
		{
		Entity::GetObjectSprite().setTexture(_data->resources.GetTexture("Segment sprite"));
		}
		else
		{
		Entity::GetObjectSprite().setTexture(_data->resources.GetTexture("Body Segment sprite"));
		}

		Entity::GetObjectSprite().setPosition(Entity::GetTopLeftXPosition(), Entity::GetTopLeftYPosition());
	}

	void CentipedeSegment::SetDead(bool isDead)
	{
		Entity::SetDead(isDead);
	}

	void CentipedeSegment::SetTrajectory(Trajectory trajectory)
	{
		_trajectory = trajectory;
	}

	void CentipedeSegment::SetTopLeftXPosition(float xpos)
	{
		Entity::SetTopLeftXPosition(xpos);
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE/2);
	}

	void CentipedeSegment::SetTopLeftYPosition(float ypos)
	{
		Entity::SetTopLeftYPosition(ypos);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE/2);
	}

	void CentipedeSegment::SetFirstSegment(bool isFirstSegment)
	{
		_firstSegment = isFirstSegment;
	}


	void CentipedeSegment::SetTurningLeft(bool isTurningLeft)
	{
		_turningLeft = isTurningLeft;
	}

	void CentipedeSegment::SetRegion(Region region)
	{
		Entity::SetRegion(region);
	}

	void CentipedeSegment::SetSubRegion(Region subregion)
	{
		Entity::SetSubRegion(subregion);
	}

	bool CentipedeSegment::IsFirstSegment()
	{
		return _firstSegment;
	}

	bool CentipedeSegment::IsTurningLeft()
	{
		return _turningLeft;
	}

	Trajectory CentipedeSegment::GetTrajectory()
	{
		return _trajectory;
	}
}