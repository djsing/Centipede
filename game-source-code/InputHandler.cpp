#include "InputHandler.h"
#include "Direction.h"

namespace GameEngine
{
	InputHandler::InputHandler(DataPtr data):
	_data(data),
	_isShooting(false),
	_direction(Direction::HOVER),
	_isLeft(false),
	_isRight(false),
	_isUp(false),
	_isDown(false)
	{
		_data->keyboard.SetDirection(_direction);
		_data->keyboard.SetShooting(_isShooting);
	}

	void InputHandler::SetControls(sf::Event event)
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
			switch (event.key.code)
			{
				case sf::Keyboard::Left:
				_isLeft = true;
				break;

				case sf::Keyboard::Right:
				_isRight = true;
				break;

				case sf::Keyboard::Up:
				_isUp = true;
				break;

				case sf::Keyboard::Down:
				_isDown = true;
				break;

				case sf::Keyboard::Space:
				_data->window.setKeyRepeatEnabled(false);
				if (_isShooting)
				{
					_isShooting = false;
				} else _isShooting = true;

				default: break;
			}
			break;

			case sf::Event::KeyReleased:
			switch (event.key.code)
			{
				case sf::Keyboard::Left:
				_isLeft = false;
				break;

				case sf::Keyboard::Right:
				_isRight = false;
				break;

				case sf::Keyboard::Up:
				_isUp = false;
				break;

				case sf::Keyboard::Down:
				_isDown = false;
				break;

				case sf::Keyboard::Space:
				_isShooting = false;

				default: break;
			}
			default: break;
		}

		_data->keyboard.SetShooting(_isShooting);

		_direction = Direction::HOVER;
		if (_isLeft)
		{
			_direction = Direction::LEFT;
		}
		if (_isRight)
		{
			_direction = Direction::RIGHT;
		}
		if (_isUp)
		{
			_direction = Direction::UP;
		}
		if (_isDown)
		{
			_direction = Direction::DOWN;
		}

		_data->keyboard.SetDirection(_direction);
	}
}