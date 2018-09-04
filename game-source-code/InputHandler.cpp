#include "InputHandler.h"
#include "Direction.h"

namespace GameEngine
{
	InputHandler::InputHandler(DataPtr data):
	_data(data),
	_isShooting(false),
	_direction(Direction::HOVER)
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
				_data->keyboard.SetDirection(Direction::LEFT);
				break;

				case sf::Keyboard::Right:
				_data->keyboard.SetDirection(Direction::RIGHT);
				break;

				case sf::Keyboard::Up:
				_data->keyboard.SetDirection(Direction::UP);
				break;

				case sf::Keyboard::Down:
				_data->keyboard.SetDirection(Direction::DOWN);
				break;

				case sf::Keyboard::Space:
				_isShooting = true;
				_data->keyboard.SetShooting(_isShooting);

				default: break;
			}
			break;

			case sf::Event::KeyReleased:
			if (event.key.code != sf::Keyboard::Space)
			{
				_data->keyboard.SetDirection(Direction::HOVER);
				break;
			}
			else if (event.key.code == sf::Keyboard::Space)
			{
				_isShooting = false;
				_data->keyboard.SetShooting(_isShooting);
			}

			default: break;
		}
	}

	bool InputHandler::IsShooting()
	{
		return _isShooting;
	}
}