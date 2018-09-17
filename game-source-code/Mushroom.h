#ifndef MUSHROOM_H
#define MUSHROOM_H

#include <SFML/Graphics.hpp>
#include "Region.h"
#include "Game.h"
#include "Entity.h"

namespace GameEngine
{
	class Mushroom: public Entity
	{
	public:
		Mushroom(DataPtr data, float xpos, float ypos);

		// Mutator functions
		void SetPoisoned(bool isPoisoned);
		void DecrementLives();

		// Accessor Functions
		bool IsPoisoned();
		int GetLivesRemaining();

	private:
		DataPtr _data;
		bool _isPoisoned;
		int _livesRemaining;
	};
}

#endif