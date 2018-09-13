#include "Spider.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	Spider::Spider():
	Entity(Direction::HOVER, SCREEN_WIDTH/2 - SPIDER_SPRITE_SIZE/2, TURRET_SCREEN_FRACTION*SCREEN_HEIGHT)
	{
		// LOAD SPIDER SPRITE HERE
		// Initialised with Direction::HOVER since it is the default direction, movement will not depend on type Direction
	}

	void Spider::SetDirection(Direction direction)
	{
		Entity::SetDirection(direction);
	}

	void Spider::SetTopLeftXPosition(float xpos)
	{
		Entity::SetTopLeftXPosition(xpos);
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + SPIDER_SPRITE_SIZE/2);
	}

	void Spider::SetTopLeftYPosition(float ypos)
	{
		Entity::SetTopLeftYPosition(ypos);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + SPIDER_SPRITE_SIZE/2);
	}

	void Spider::SetRegion(Region region)
	{
		Entity::SetRegion(region);
	}

	void Spider::SetSubRegion(Region subregion)
	{
		Entity::SetSubRegion(subregion);
	}

	void Spider::SetDead(bool isDead)
	{
		Entity::SetDead(isDead);
	}
}