#include "KeyboardControlsHandler.h"

namespace GameEngine
{
	KeyboardControlsHandler::KeyboardControlsHandler()
		: direction_ ( Direction::HOVER )
		, is_shooting_ ( false )
	{
	}

	bool KeyboardControlsHandler::IsShooting()
	{
		return is_shooting_;
	}

	void KeyboardControlsHandler::SetShooting ( bool isShooting )
	{
		is_shooting_ = isShooting;
	}

	Direction KeyboardControlsHandler::GetDirection()
	{
		return direction_;
	}

	void KeyboardControlsHandler::SetDirection ( Direction direction )
	{
		direction_ = direction;
	}
} // namespace GameEngine
