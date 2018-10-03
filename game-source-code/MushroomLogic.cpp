#include <cstdlib>
#include <ctime>
#include <experimental/random>
#include "DEFINITIONS.h"
#include "Mushroom.h"
#include "MushroomLogic.h"
#include "RegionHandler.h"

namespace GameEngine
{
MushroomLogic::MushroomLogic(FieldPtr field) : field_(field), death_chance_(0)
{
    std::srand(std::time(nullptr));
}

void MushroomLogic::Spawn()
{
    // only executes at the beginning of the game
    if(field_->GetMushrooms().empty())
	{
	    for(auto i = 0; i < MUSHROOMS_SPAWNED; i++)
		{
		    int randYLevel = std::rand() % maxYLevels;
		    int randXLevel = std::rand() % maxXLevels;
		    int maxScreenPosition = SCREEN_WIDTH - MUSHROOM_SPRITE_SIZE;

		    if(randYLevel < 3 || randYLevel > maxYLevels - 0.25 * maxYLevels ||
		       randXLevel * MUSHROOM_SPRITE_SIZE > maxScreenPosition || randXLevel == 0)
			{
			    i--;
			    continue;
			}

		    auto mushroom = Mushroom{static_cast<float>(randXLevel * MUSHROOM_SPRITE_SIZE),
		                             static_cast<float>(randYLevel * MUSHROOM_SPRITE_SIZE)};
		    field_->GetMushrooms().push_back(mushroom);
		}
	}

    if(!field_->GetNewMushrooms().empty())
	{
	    for(auto& i : field_->GetNewMushrooms())
		{
		    auto mushroom = Mushroom{std::get<0>(i), std::get<1>(i)};
		    field_->GetMushrooms().push_back(mushroom);
		}
	}
    field_->GetNewMushrooms().clear();
}

void MushroomLogic::CollisionHandle()
{
    death_chance_ = std::rand() % 100;
    // kill some poisoned mushrooms
    for(auto& i : field_->GetMushrooms())
	{
	    if(i.IsBitten())
		{
		    if(death_chance_ < SPIDER_BITE_DEATH_CHANCE)
			{
			    i.SetDead(true);
			}

		    else
			i.SetBitten(false);
		}
	}
    // delete all dead mushrooms
    auto deadBegin = std::remove(field_->GetMushrooms().begin(), field_->GetMushrooms().end(), true);
    field_->GetMushrooms().erase(deadBegin, field_->GetMushrooms().end());
}
}  // namespace GameEngine
