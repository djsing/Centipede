#include "Turret.h"
#include "Direction.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	Turret::Turret(DataPtr data):
	_data(data),
	_direction(Direction::HOVER),
	_topLeftXPosition(SCREEN_WIDTH/2 - TURRET_SPRITE_SIDE_SIZE/2),
	_topLeftYPosition(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE),
	_speed(200)
	{
		_turret.setTexture(_data->resources.GetTexture("Turret Sprite"));
		_turret.setPosition(_topLeftXPosition, _topLeftYPosition);
	}

	float Turret::GetSpeed()
	{
		return _speed;
	}

	Direction Turret::GetDirection()
	{
		return _direction;
	}

	float Turret::GetTopLeftXPosition()
	{
		return _topLeftXPosition;
	}

	float Turret::GetTopLeftYPosition()
	{
		return _topLeftYPosition;
	}

	float Turret::GetCenterXPosition()
	{
		return _topLeftXPosition + TURRET_SPRITE_SIDE_SIZE/2;
	}

	float Turret::GetCenterYPosition()
	{
		return _topLeftYPosition + TURRET_SPRITE_SIDE_SIZE/2;
	}

	void Turret::DrawTurret()
	{
		_data->window.draw(_turret);
	}

	void Turret::MoveTurret(float dt)
	{
		auto moveDistance = _speed*dt;
		// move sprite moveDistance away in the current direction
		// Check whether centipede is moving to the bottom/top  of screen
		// check direction of centipede movement
		switch (_data->keyboard.GetDirection())
		{
			case Direction::RIGHT:
			// now check if square is at right side of screen 
			if ((_topLeftXPosition + TURRET_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
				{
					_topLeftXPosition = SCREEN_WIDTH - TURRET_SPRITE_SIDE_SIZE;
					_turret.setPosition(_topLeftXPosition, _topLeftYPosition);
				} 
			else
				{
					_turret.move(moveDistance, 0);
					_topLeftXPosition += moveDistance;
				}
			break;

			case Direction::DOWN:
			// check if square is at bottom of the screen
			if ((_topLeftYPosition + TURRET_SPRITE_SIDE_SIZE) >= (SCREEN_HEIGHT))
			{
				_topLeftYPosition = SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE;
				_turret.setPosition(_topLeftXPosition, _topLeftYPosition);
			} 
			else
			{
				_turret.move(0, moveDistance);
				_topLeftYPosition += moveDistance;
			}

			break;

			case Direction::LEFT:
			if (_topLeftXPosition <= 0)
			{
				_topLeftXPosition = 0;
				_turret.setPosition(_topLeftXPosition, _topLeftYPosition);
			} 
			else 
			{
				_turret.move(-moveDistance, 0);
				_topLeftXPosition -= moveDistance;
			}
			break;

			case Direction::UP:
			// check if square is at top of the screen
			if (_topLeftYPosition <= 0.75*SCREEN_HEIGHT)
			{
				_topLeftYPosition = 0.75*SCREEN_HEIGHT;
				_turret.setPosition(_topLeftXPosition, _topLeftYPosition);
			}
			else
			{
				_turret.move(0, -moveDistance);
				_topLeftYPosition -= moveDistance;
			}

			case Direction::HOVER:
			default: break;
		}
	}
}