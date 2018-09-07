#include "TurretLogic.h"
#include "Bullet.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	TurretLogic::TurretLogic(DataPtr data, TurretPtr turret):
	_data(data),
	_turret(turret),
	_speed(TURRET_SPEED)
	{
		
	}

	void TurretLogic::Spawn()
	{
		auto bullet = Bullet(_data,
			(_turret->GetCenterXPosition() - BULLET_WIDTH/2),
			_turret->GetTopLeftYPosition());

		_turret->GetBullets().push_back(bullet);
	}

	void TurretLogic::Move(float dt)
	{
		auto moveDistance = _speed*dt;

		switch (_data->keyboard.GetDirection())
		{
			case Direction::RIGHT:
			// now check if square is at right side of screen 
			if ((_turret->GetTopLeftXPosition() + TURRET_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
				{
					_turret->SetTopLeftXPosition(SCREEN_WIDTH - TURRET_SPRITE_SIDE_SIZE);
					_turret->GetTurretSprite().setPosition(_turret->GetTopLeftXPosition(), _turret->GetTopLeftYPosition());
				} 
			else
				{
					_turret->GetTurretSprite().move(moveDistance, 0);
					_turret->SetTopLeftXPosition(_turret->GetTopLeftXPosition() + moveDistance);
				}
			break;

			case Direction::DOWN:
			// check if square is at bottom of the screen
			if ((_turret->GetTopLeftYPosition() + TURRET_SPRITE_SIDE_SIZE) >= (SCREEN_HEIGHT))
			{
				_turret->SetTopLeftYPosition(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
				_turret->GetTurretSprite().setPosition(_turret->GetTopLeftXPosition(), _turret->GetTopLeftYPosition());
			}
			else
			{
				_turret->GetTurretSprite().move(0, moveDistance);
				_turret->SetTopLeftYPosition(_turret->GetTopLeftYPosition() + moveDistance);
			}

			break;

			case Direction::LEFT:
			if (_turret->GetTopLeftXPosition() <= 0)
			{
				_turret->SetTopLeftXPosition(0);
				_turret->GetTurretSprite().setPosition(_turret->GetTopLeftXPosition(), _turret->GetTopLeftYPosition());
			}
			else
			{
				_turret->GetTurretSprite().move(-moveDistance, 0);
				_turret->SetTopLeftXPosition(_turret->GetTopLeftXPosition() - moveDistance);
			}
			break;

			case Direction::UP:
			// check if square is at top of player box
			if (_turret->GetTopLeftYPosition() <= 0.6*SCREEN_HEIGHT)
			{
				_turret->SetTopLeftYPosition(0.6*SCREEN_HEIGHT);
				_turret->GetTurretSprite().setPosition(_turret->GetTopLeftXPosition(), _turret->GetTopLeftYPosition());
			}
			else
			{
				_turret->GetTurretSprite().move(0, -moveDistance);
				_turret->SetTopLeftYPosition(_turret->GetTopLeftYPosition() - moveDistance);
			}

			case Direction::HOVER:
			default: break;
		}
	}

	void TurretLogic::MoveProjectiles(float dt)
	{
		for (unsigned int i = 0; i < _turret->GetBullets().size(); i++)
		{
			_bulletLogic = std::make_unique<BulletLogic>(_turret->GetBullets().at(i));
			_bulletLogic->Move(dt);
		}
	}

	void TurretLogic::CollisionCheck()
	{
		
	}

	void TurretLogic::CollisionHandle()
	{
		//------------------------------- implement GAMEOVER if turret is hit ----------------------------------

		// delete collided bullets 
		for (unsigned int i = 0; i < _turret->GetBullets().size(); i++)
		{
			if (_turret->GetBullets().at(i).IsDead())
			{
				_turret->GetBullets().erase(_turret->GetBullets().begin() + i);
				i--;
			}
		}
	}
}