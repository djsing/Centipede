#include "Bullet.h"
#include "DEFINITIONS.h"
#include "GameOver.h"
#include "GamePlay.h"
#include "TurretLogic.h"

namespace GameEngine
{
TurretLogic::TurretLogic(DataPtr data, TurretPtr turret) : data_(data), turret_(turret), speed_(TURRET_SPEED)
{
}

void TurretLogic::Spawn()
{
    if(data_->keyboard.IsShooting() &&
       turret_->GetTopLeftYPosition() >= turret_->GetLastBulletYPosition() + BULLET_HEIGHT)
	{
	    auto bullet = Bullet(turret_->GetCenterXPosition() - BULLET_WIDTH / 2, turret_->GetTopLeftYPosition());
	    turret_->GetBullets().push_back(bullet);
	    data_->keyboard.SetShooting(false);
	}
}

void TurretLogic::Move(float dt)
{
    // move turret
    auto moveDistance = speed_ * dt;

    switch(data_->keyboard.GetDirection())
	{
	case Direction::RIGHT:
	    // if turret moves past the right side of the screen, set it at the right edge of the screen
	    if((turret_->GetTopLeftXPosition() + TURRET_SPRITE_SIDE_SIZE) >= (SCREEN_WIDTH))
		{
		    turret_->SetTopLeftXPosition(SCREEN_WIDTH - TURRET_SPRITE_SIDE_SIZE);
		}
	    else
		{
		    turret_->SetTopLeftXPosition(turret_->GetTopLeftXPosition() + moveDistance);
		}
	    break;

	case Direction::DOWN:
	    // check if square is at bottom of the screen
	    if((turret_->GetTopLeftYPosition() + TURRET_SPRITE_SIDE_SIZE) >= (SCREEN_HEIGHT))
		{
		    turret_->SetTopLeftYPosition(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
		}
	    else
		{
		    turret_->SetTopLeftYPosition(turret_->GetTopLeftYPosition() + moveDistance);
		}
	    break;

	case Direction::LEFT:
	    if(turret_->GetTopLeftXPosition() <= SCREEN_LHS)
		{
		    turret_->SetTopLeftXPosition(SCREEN_LHS);
		}
	    else
		{
		    turret_->SetTopLeftXPosition(turret_->GetTopLeftXPosition() - moveDistance);
		}
	    break;

	case Direction::UP:

	    // check if square is at top of player box
	    if(turret_->GetTopLeftYPosition() <= TURRET_SCREEN_FRACTION * SCREEN_HEIGHT)
		{
		    turret_->SetTopLeftYPosition(TURRET_SCREEN_FRACTION * SCREEN_HEIGHT);
		}
	    else
		{
		    turret_->SetTopLeftYPosition(turret_->GetTopLeftYPosition() - moveDistance);
		}

	default:
	    break;
	}
}

void TurretLogic::CollisionHandle()
{
    if(data_->lives.LivesRemaining() == 0)
	{
	    data_->statehandler.AddState(StatePtr(new GameOver(data_)));
	}
    else if(turret_->IsDead())
	{
	    data_->score_manager.DecrementScore(PLAYER_DEATH_SCORE_LOSS);
	    data_->statehandler.AddState(StatePtr(new GamePlay(data_)));
	}
}
}  // namespace GameEngine
