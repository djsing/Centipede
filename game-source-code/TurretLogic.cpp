#include "Bullet.h"
#include "DEFINITIONS.h"
#include "GameOver.h"
#include "GamePlay.h"
#include "TurretLogic.h"

namespace GameEngine
{
TurretLogic::TurretLogic(DataPtr data, TurretPtr turret)
    : _data(data)
    , _turret(turret)
    , _speed(TURRET_SPEED)
{
    _bulletLogic = std::make_unique<BulletLogic>(_turret->GetBullets());
}

void TurretLogic::Spawn()
{
    if(_data->keyboard.IsShooting() &&
       (_turret->GetTopLeftYPosition() >= (_turret->GetLastBulletYPosition() + BULLET_HEIGHT)))
	{
	    auto bullet =
	        Bullet(_data, _turret->GetCenterXPosition() - BULLET_WIDTH / 2, _turret->GetTopLeftYPosition());
	    _turret->GetBullets().push_back(bullet);
	    _data->keyboard.SetShooting(false);
	}
}

void TurretLogic::Move(float dt)
{
    auto moveDistance = _speed * dt;

    switch(_data->keyboard.GetDirection())
	{
	case Direction::RIGHT:
	    // now check if square is at right side of screen
	    if((_turret->GetTopLeftXPosition() + TURRET_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
		{
		    _turret->SetTopLeftXPosition(SCREEN_WIDTH - TURRET_SPRITE_SIDE_SIZE);
		}
	    else
		{
		    _turret->SetTopLeftXPosition(_turret->GetTopLeftXPosition() + moveDistance);
		}
	    break;

	case Direction::DOWN:
	    // check if square is at bottom of the screen
	    if((_turret->GetTopLeftYPosition() + TURRET_SPRITE_SIDE_SIZE) >= (SCREEN_HEIGHT))
		{
		    _turret->SetTopLeftYPosition(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
		}
	    else
		{
		    _turret->SetTopLeftYPosition(_turret->GetTopLeftYPosition() + moveDistance);
		}

	    break;

	case Direction::LEFT:
	    if(_turret->GetTopLeftXPosition() <= SCREEN_LHS)
		{
		    _turret->SetTopLeftXPosition(SCREEN_LHS);
		}
	    else
		{
		    _turret->SetTopLeftXPosition(_turret->GetTopLeftXPosition() - moveDistance);
		}
	    break;

	case Direction::UP:
	    // check if square is at top of player box
	    if(_turret->GetTopLeftYPosition() <= TURRET_SCREEN_FRACTION * SCREEN_HEIGHT)
		{
		    _turret->SetTopLeftYPosition(TURRET_SCREEN_FRACTION * SCREEN_HEIGHT);
		}
	    else
		{
		    _turret->SetTopLeftYPosition(_turret->GetTopLeftYPosition() - moveDistance);
		}

	case Direction::HOVER:
	default:
	    break;
	}
}

void TurretLogic::MoveProjectiles(float dt)
{
    _bulletLogic->Move(dt);
}

void TurretLogic::CollisionHandle()
{
    if(_data->lives.LivesRemaining() == 0)
	{
	    _data->statehandler.AddState(StatePtr(new GameOver(_data)));
	}
    else if(_turret->IsDead())
	{
	    _data->statehandler.AddState(StatePtr(new GamePlay(_data)));
	}

    _bulletLogic->CollisionHandle();
}
} // namespace GameEngine