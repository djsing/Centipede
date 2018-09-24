#include "CentipedeSegment.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	CentipedeSegment::CentipedeSegment ( bool firstSegment )
		: Entity ( SCREEN_LHS, SCREEN_TOP )
		, turning_left_ ( true )
		, trajectory_ ( Trajectory::DOWNWARD )
		, first_segment_ ( firstSegment )
		, is_poisoned_ ( false )
	{
		Entity::SetDirection ( Direction::RIGHT );
		Entity::SetCenterXPosition ( Entity::GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE / 2 );
		Entity::SetCenterYPosition ( Entity::GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE / 2 );
	}

	void CentipedeSegment::SetTopLeftXPosition ( float xpos )
	{
		Entity::SetTopLeftXPosition ( xpos );
		Entity::SetCenterXPosition ( Entity::GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE / 2 );
	}

	void CentipedeSegment::SetTopLeftYPosition ( float ypos )
	{
		Entity::SetTopLeftYPosition ( ypos );
		Entity::SetCenterYPosition ( Entity::GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE / 2 );
	}

	void CentipedeSegment::SetFirstSegment ( bool isFirstSegment )
	{
		first_segment_ = isFirstSegment;
	}

	void CentipedeSegment::SetTrajectory ( Trajectory trajectory )
	{
		trajectory_ = trajectory;
	}

	void CentipedeSegment::SetTurningLeft ( bool isTurningLeft )
	{
		turning_left_ = isTurningLeft;
	}

	void CentipedeSegment::SetPoisoned ( bool isPoisoned )
	{
		is_poisoned_ = isPoisoned;
	}

	Trajectory CentipedeSegment::GetTrajectory()
	{
		return trajectory_;
	}

	bool CentipedeSegment::IsFirstSegment()
	{
		return first_segment_;
	}

	bool CentipedeSegment::IsTurningLeft()
	{
		return turning_left_;
	}

	bool CentipedeSegment::IsPoisoned()
	{
		return is_poisoned_;
	}
} // namespace GameEngine
