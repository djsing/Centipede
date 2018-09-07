#include "Bullet.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	Bullet::Bullet(DataPtr data, float xpos, float ypos):
	_data(data),
	_topLeftXPosition(xpos),
	_topLeftYPosition(ypos),
	_speed(BULLET_SPEED),
	_dead(false)
	{
		_bullet.setTexture(_data->resources.GetTexture("Bullet sprite"));
		_bullet.setPosition(_topLeftXPosition,_topLeftYPosition);
	}

	void Bullet::SetDead(bool isDead)
	{
		_dead = isDead;
	}

	void Bullet::SetYPosition(float ypos)
	{
		_topLeftYPosition = ypos;
	}


	void Bullet::SetRegion(Region region)
	{
		_region = region;
	}

	void Bullet::SetSubRegion(Region subregion)
	{
		_subregion = subregion;
	}

	sf::Sprite &Bullet::GetBullet()
	{
		return _bullet;
	}

	bool Bullet::IsDead()
	{
		return _dead;
	}


	float Bullet::GetTopLeftXPosition()
	{
		return _topLeftXPosition;
	}

	float Bullet::GetTopLeftYPosition()
	{
		return _topLeftYPosition;
	}

	float Bullet::GetCenterXPosition()
	{
		return _topLeftXPosition + CENTIPEDE_SPRITE_SIDE_SIZE/2;
	}

	float Bullet::GetCenterYPosition()
	{
		return _topLeftYPosition + CENTIPEDE_SPRITE_SIDE_SIZE/2;
	}

	void Bullet::UpdateRegion()
	{	// left side of screen
		if (_topLeftXPosition <= (SCREEN_WIDTH/2 - BULLET_WIDTH))
		{
			// top half of screen
			if (_topLeftYPosition <= (SCREEN_HEIGHT/2 - BULLET_HEIGHT))
			{
				_region = Region::TOP_LEFT;
				// left side of top left quarter
				if (_topLeftXPosition <= (SCREEN_WIDTH/4 - BULLET_WIDTH))
				{
					// top half of left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT/4 - BULLET_HEIGHT))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right side of top left quarter
				else
				{
					// top half of left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT/4 - BULLET_HEIGHT))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
			// bottom half of screen
			else
			{
				_region = Region::BOTTOM_LEFT;
				// left half of bottom left quarter
				if (_topLeftXPosition <= (SCREEN_WIDTH/4 - BULLET_WIDTH))
				{
					// top half of bottom left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT*3/4 - BULLET_HEIGHT))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of bottom left quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right half of bottom left quarter
				else
				{
					// top half of left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT*3/4 - BULLET_HEIGHT))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
		}
		// right side of screen
		else
		{
			// top half of screen
			if (_topLeftYPosition <= (SCREEN_HEIGHT/2 - BULLET_HEIGHT))
			{
				_region = Region::TOP_RIGHT;
				// left half of top right quarter
				if (_topLeftXPosition <= (SCREEN_WIDTH*3/4 - BULLET_WIDTH))
				{
					// top half of left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT/4 - BULLET_HEIGHT))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right side of top right quarter
				else
				{
					// top half of top right quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT/4 - BULLET_HEIGHT))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of top right quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
			// bottom half of screen
			else
			{
				_region = Region::BOTTOM_RIGHT;
				// 
				if (_topLeftXPosition <= (SCREEN_WIDTH*3/4 - BULLET_WIDTH))
				{
					// top half of right bottom quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT*3/4 - BULLET_HEIGHT))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of right bottom quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right side of bottom right quarter
				else
				{
					// top half of left quarter
					if (_topLeftYPosition <= (SCREEN_HEIGHT*3/4 - BULLET_HEIGHT))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
		}
	}
}