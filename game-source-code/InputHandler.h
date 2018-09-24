#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Direction.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace GameEngine
{
	class InputHandler
	{
	public:
		InputHandler ( DataPtr data );
		void SetControls ( sf::Event event );

	private:
		DataPtr data_;
		bool is_shooting_;
		Direction direction_;
		bool is_left_;
		bool is_right_;
		bool is_up_;
		bool is_down_;
	};

	using InputHandlerPtr = std::shared_ptr<InputHandler>;
} // namespace GameEngine

#endif
