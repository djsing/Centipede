#include "MushroomLogic.h"
#include "DEFINITIONS.h"
#include "RegionHandler.h"
#include <cstdlib>
#include <ctime>
#include <experimental/random>

namespace GameEngine
{
	MushroomLogic::MushroomLogic(FieldPtr field, DataPtr data):
	_data(data),
	_field(field)
	{
		std::srand(std::time(nullptr));
	}

	void MushroomLogic::Spawn()
	{
		for (unsigned int i = 0; i < MUSHROOMS_SPAWNED ; i++)
		{
			int maxLevels = TURRET_SCREEN_FRACTION*SCREEN_HEIGHT/MUSHROOM_SPRITE_SIZE;
			int randLevel = std::experimental::randint(0, maxLevels);
			int maxScreenPosition = SCREEN_WIDTH-MUSHROOM_SPRITE_SIZE;
			int randXPos = std::experimental::randint(1, maxScreenPosition);
			auto mushRegion = RegionHandler{static_cast<float>(maxLevels), static_cast<float>(randLevel*MUSHROOM_SPRITE_SIZE)};
			auto mushroom = Mushroom{_data, static_cast<float>(randXPos), static_cast<float>(randLevel*MUSHROOM_SPRITE_SIZE)};
			_field->GetMushrooms().push_back(mushroom);
		}
	}

	void MushroomLogic::CollisionHandle()
	{
		for (unsigned int i = 0; i < _field->GetMushrooms().size(); i++)
		{
			
		}
	}
}