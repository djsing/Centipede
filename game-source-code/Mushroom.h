#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Entity.h"
#include "Game.h"
#include "Region.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class Mushroom : public Entity
	{
	public:
		Mushroom ( float xpos, float ypos );

		// Mutator functions
		void SetBitten ( bool isBitten );
		void SetPoisoned ( bool isPoisoned );
		void DecrementLives();

		// Accessor Functions
		bool IsBitten();
		bool IsPoisoned();
		int GetLivesRemaining();

	private:
		bool is_bitten_;
		bool is_poisoned_;
		int lives_remaining_;
	};
} // namespace GameEngine

#endif
