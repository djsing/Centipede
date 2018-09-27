#include <cstdlib>
#include <ctime>
#include <experimental/random>
#include "DEFINITIONS.h"
#include "MushroomLogic.h"
#include "RegionHandler.h"

namespace GameEngine
{
MushroomLogic::MushroomLogic(FieldPtr field) : _field(field), _deathChance(0)
{
    std::srand(std::time(nullptr));
}

void MushroomLogic::Spawn()
{
    // only executes at the beginning of the game
    if(_field->GetMushrooms().empty())
	{
	    for(auto i = 0; i < MUSHROOMS_SPAWNED; i++)
		{
		    int randYLevel = std::rand() % maxYLevels;
		    int randXLevel = std::rand() % maxXLevels;
		    int maxScreenPosition = SCREEN_WIDTH - MUSHROOM_SPRITE_SIZE;

		    if(randYLevel < 3 || randYLevel > maxYLevels - 0.25 * maxYLevels ||
		       randXLevel * MUSHROOM_SPRITE_SIZE > maxScreenPosition)
			{
			    i--;
			    continue;
			}

		    auto mushroom = Mushroom{static_cast<float>(randXLevel * MUSHROOM_SPRITE_SIZE),
		                             static_cast<float>(randYLevel * MUSHROOM_SPRITE_SIZE)};
		    _field->GetMushrooms().push_back(mushroom);
		}
	}
}

void MushroomLogic::CollisionHandle()
{
    _deathChance = std::rand() % 100;
    // kill some poisoned mushrooms
    for(auto& i : _field->GetMushrooms())
	{
	    if(i.IsBitten())
		{
		    if(_deathChance < SPIDER_BITE_DEATH_CHANCE)
			{
			    i.SetDead(true);
			}

		    else
			i.SetBitten(false);
		}
	}
    // delete all dead mushrooms
    auto deadBegin = std::remove(_field->GetMushrooms().begin(), _field->GetMushrooms().end(), true);
    _field->GetMushrooms().erase(deadBegin, _field->GetMushrooms().end());
}
}  // namespace GameEngine
