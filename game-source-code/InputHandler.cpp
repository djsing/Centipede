#include "InputHandler.h"

namespace GameEngine
{
	InputHandler::InputHandler ( DataPtr data )
		: data_ ( data )
		, is_shooting_ ( false )
		, direction_ ( Direction::HOVER )
		, is_left_ ( false )
		, is_right_ ( false )
		, is_up_ ( false )
		, is_down_ ( false )
	{
		data_->keyboard.SetDirection ( direction_ );
		data_->keyboard.SetShooting ( is_shooting_ );
	}

	void InputHandler::SetControls ( sf::Event event )
	{
		switch ( event.type )
		{
		case sf::Event::KeyPressed:
			switch ( event.key.code )
			{
			case sf::Keyboard::Left:
				is_left_ = true;
				break;

			case sf::Keyboard::Right:
				is_right_ = true;
				break;

			case sf::Keyboard::Up:
				is_up_ = true;
				break;

			case sf::Keyboard::Down:
				is_down_ = true;
				break;

			case sf::Keyboard::Space:
				data_->window.setKeyRepeatEnabled ( false );

				if ( is_shooting_ )
				{
					is_shooting_ = false;
				}

				else
					is_shooting_ = true;

			default:
				break;
			}

			break;

		case sf::Event::KeyReleased:
			switch ( event.key.code )
			{
			case sf::Keyboard::Left:
				is_left_ = false;
				break;

			case sf::Keyboard::Right:
				is_right_ = false;
				break;

			case sf::Keyboard::Up:
				is_up_ = false;
				break;

			case sf::Keyboard::Down:
				is_down_ = false;
				break;

			case sf::Keyboard::Space:
				is_shooting_ = false;

			default:
				break;
			}

		default:
			break;
		}

		data_->keyboard.SetShooting ( is_shooting_ );

		direction_ = Direction::HOVER;

		if ( is_left_ )
		{
			direction_ = Direction::LEFT;
		}

		if ( is_right_ )
		{
			direction_ = Direction::RIGHT;
		}

		if ( is_up_ )
		{
			direction_ = Direction::UP;
		}

		if ( is_down_ )
		{
			direction_ = Direction::DOWN;
		}

		data_->keyboard.SetDirection ( direction_ );
	}
} // namespace GameEngine
