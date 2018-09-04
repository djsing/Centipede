#include "KeyboardControlsHandler.h"

namespace GameEngine
{
	KeyboardControlsHandler::KeyboardControlsHandler():
	_direction(Direction::HOVER),
	_isShooting(false)
	{}

	bool KeyboardControlsHandler::IsShooting()
	{
		return _isShooting;
	}

	void KeyboardControlsHandler::SetShooting(bool isShooting)
	{
		_isShooting = isShooting;
	}

	Direction KeyboardControlsHandler::GetDirection()
	{
		return _direction;
	}

	void KeyboardControlsHandler::SetDirection(Direction direction)
	{
		_direction = direction;
	}
}