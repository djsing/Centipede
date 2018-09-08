#include "Turret.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	Turret::Turret(DataPtr data):
	_data(data),
	_direction(Direction::HOVER),
	_topLeftXPosition(SCREEN_WIDTH/2 - TURRET_SPRITE_SIDE_SIZE/2),
	_topLeftYPosition(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE)
	{
		_turret.setTexture(_data->resources.GetTexture("Turret Sprite"));
		_turret.setPosition(_topLeftXPosition, _topLeftYPosition);
	}

	sf::Sprite &Turret::GetTurretSprite()
	{
		return _turret;
	}

	std::vector<Bullet> &Turret::GetBullets()
	{
		return _bullets;
	}

	void Turret::SetSpritePosition(float xpos, float ypos)
	{
		_turret.setPosition(xpos, ypos);
	}

	void Turret::SetTopLeftXPosition(float xpos)
	{
		_topLeftXPosition = xpos;
	}

	void Turret::SetTopLeftYPosition(float ypos)
	{
		_topLeftYPosition = ypos;
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

	float Turret::GetLastBulletYPosition()
	{
		if (_bullets.empty())
		{
			return GetTopLeftYPosition() - BULLET_HEIGHT;
		}
		return _bullets.back().GetTopLeftYPosition();
	}
}