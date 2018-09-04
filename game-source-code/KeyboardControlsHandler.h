#ifndef KEYBOARDCONTROLSHANDLER_H
#define KEYBOARDCONTROLSHANDLER_H

#include "Direction.h"

namespace GameEngine
{
	class KeyboardControlsHandler
	{
	public:
		KeyboardControlsHandler();
		bool IsShooting();
		void SetShooting(bool isShooting);
		Direction GetDirection();
		void SetDirection(Direction direction);
	private:
		Direction _direction;
		bool _isShooting;
	};
}

#endif