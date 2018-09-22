#include "Scorpion.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	Scorpion::Scorpion(DataPtr data):
	Entity(SCREEN_WIDTH/2 - SCORPION_SPRITE_SIZE/2, 0.25*SCREEN_HEIGHT),
	_data(data)
	{
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + SCORPION_SPRITE_SIZE/2);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + SCORPION_SPRITE_SIZE/2);
	}

	void Scorpion::SetTopLeftXPosition(float xpos)
	{
		if (xpos < SCREEN_LHS - SCORPION_SPRITE_SIZE)
		{
			xpos = SCREEN_WIDTH + SCORPION_SPRITE_SIZE;
		}
		else if (xpos > SCREEN_WIDTH + SCORPION_SPRITE_SIZE)
		{
			xpos = SCREEN_LHS - SCORPION_SPRITE_SIZE;
		}
		Entity::SetTopLeftXPosition(xpos);
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + SCORPION_SPRITE_SIZE/2);
	}

	void Scorpion::SetTopLeftYPosition(float ypos)
	{
		Entity::SetTopLeftYPosition(ypos);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + SCORPION_SPRITE_SIZE/2);
	}
}