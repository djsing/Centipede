#include "Scorpion.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	Scorpion::Scorpion():
	Entity(Direction::HOVER, SCREEN_WIDTH/2 - SCORPION_SPIRTE_SIZE/2, 0.25*SCREEN_HEIGHT)
	{
		//LOAD SCORPION SPRITE HERE
	}

	void Scorpion::SetDirection(Direction direction)
	{
		Entity::SetDirection(direction);
	}

	void Scorpion::SetTopLeftXPosition(float xpos)
	{
		Entity::SetTopLeftXPosition(xpos);
	}

	void Scorpion::SetTopLeftYPosition(float ypos)
	{
		Entity::SetTopLeftYPosition(ypos);
	}

	void Scorpion::SetRegion(Region region)
	{
		Entity::SetRegion(region);
	}

	void Scorpion::SetSubRegion(Region subregion)
	{
		Entity::SetSubRegion(subregion);
	}

	void Scorpion::SetDead(bool isDead)
	{
		Entity::SetDead(isDead);
	}
}