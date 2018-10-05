#include <cstdlib>
#include <ctime>
#include <tuple>
#include "BombLogic.h"

namespace GameEngine
{
BombLogic::BombLogic(FieldPtr field) : field_(field)
{
    srand(time(nullptr));
    timer_.restart();
}

void BombLogic::Spawn()
{
    if(field_->GetBombs().size() < BOMBS_SPAWNED)
	{
	    auto randPos = GetRandomPositions();
	    auto bomb = Bomb{std::get<0>(randPos), std::get<1>(randPos)};
	    field_->GetBombs().push_back(bomb);
	}
}

void BombLogic::Move(float dt)
{
    if(time_elapsed_ > 4)
	{
	    for(auto& i : field_->GetBombs())
		{
		    auto randPos = GetRandomPositions();
		    i.SetTopLeftXPosition(std::get<0>(randPos));
		    i.SetTopLeftYPosition(std::get<1>(randPos));
		}
	    time_elapsed_ = 0;
	    return;
	}
    time_elapsed_ += dt;
}

void BombLogic::CollisionHandle()
{
    if(timer_.getElapsedTime() > 1)
	{
	    // find and delete dead bombs
	    auto deadBegin = std::remove(field_->GetBombs().begin(), field_->GetBombs().end(), true);
	    field_->GetBombs().erase(deadBegin, field_->GetBombs().end());
	    timer_.restart();
	}
}

std::pair<float, float> BombLogic::GetRandomPositions()
{
    bool isValid = false;
    int randYLevel = 0;
    int randXLevel = 0;
    // look for a set of valid positions while the set of positions are not valid
    while(!isValid)
	{
	    randXLevel = std::rand() % max_x_levels_;
	    randYLevel = std::rand() % max_y_levels_;
	    if(randYLevel * BOMB_SPRITE_SIZE <= WINDOW_TOP)
		{
		    continue;
		}
	    else if((randXLevel * BOMB_SPRITE_SIZE < SCREEN_WIDTH / 4) &&
	            (randXLevel * BOMB_SPRITE_SIZE + BOMB_SPRITE_SIZE > SCREEN_WIDTH / 4))
		{
		    continue;
		}
	    else if((randXLevel * BOMB_SPRITE_SIZE < SCREEN_WIDTH / 2) &&
	            (randXLevel * BOMB_SPRITE_SIZE + BOMB_SPRITE_SIZE > SCREEN_WIDTH / 2))
		{
		    continue;
		}
	    else if((randXLevel * BOMB_SPRITE_SIZE < SCREEN_WIDTH * 3 / 4) &&
	            (randXLevel * BOMB_SPRITE_SIZE + BOMB_SPRITE_SIZE > SCREEN_WIDTH * 3 / 4))
		{
		    continue;
		}
	    isValid = true;
	}
    return std::make_pair(randXLevel * BOMB_SPRITE_SIZE, randYLevel * BOMB_SPRITE_SIZE);
}

}  // namespace GameEngine