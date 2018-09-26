#include "DEFINITIONS.h"
#include "MushroomLogic.h"
#include "RegionHandler.h"
#include <cstdlib>
#include <ctime>
#include <experimental/random>

namespace GameEngine
{
	MushroomLogic::MushroomLogic ( FieldPtr field )
		: _field ( field )
		, _deathChance ( 0 )
	{
		std::srand ( std::time ( nullptr ) );
	}

	void MushroomLogic::Spawn()
	{
		if ( _field->GetMushrooms().empty() )
			{
				for ( unsigned int i = 0; i < MUSHROOMS_SPAWNED; i++ )
					{
						int maxLevels = SCREEN_HEIGHT / MUSHROOM_SPRITE_SIZE;
						int randLevel = std::rand() % maxLevels;
						int maxScreenPosition = SCREEN_WIDTH - MUSHROOM_SPRITE_SIZE;
						int randXPos = std::rand() % maxScreenPosition;

						if ( randLevel < 3 || randLevel > maxLevels - 0.25 * maxLevels )
							{
								i--;
								continue;
							}

						auto mushroom = Mushroom{ static_cast<float> ( randXPos ),
						                          static_cast<float> ( randLevel * MUSHROOM_SPRITE_SIZE ) };
						_field->GetMushrooms().push_back ( mushroom );
					}
			}
	}

	void MushroomLogic::CollisionHandle()
	{
		_deathChance = std::rand() % 100;

		for ( unsigned int i = 0; i < _field->GetMushrooms().size(); i++ )
			{
				if ( _field->GetMushrooms().at ( i ).IsBitten() )
					{
						if ( _deathChance < SPIDER_BITE_DEATH_CHANCE )
							{
								_field->GetMushrooms().at ( i ).SetDead ( true );
							}

						else
							_field->GetMushrooms().at ( i ).SetBitten ( false );
					}
			}

		auto dead = std::find ( _field->GetMushrooms().begin(), _field->GetMushrooms().end(), true );

		while ( dead != _field->GetMushrooms().end() )
			{
				_field->GetMushrooms().erase ( dead );
				dead = std::find ( dead, _field->GetMushrooms().end(), true );
			}
	}
} // namespace GameEngine
