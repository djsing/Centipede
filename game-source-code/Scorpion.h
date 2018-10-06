#ifndef SCORPION_H
#define SCORPION_H

#include "Entity.h"
#include "Game.h"

namespace GameEngine
{
	class Scorpion : public Entity
	{
	public:
		Scorpion();
		void SetTopLeftXPosition ( float xpos );
		void SetTopLeftYPosition ( float ypos );
	};
} // namespace GameEngine

#endif
