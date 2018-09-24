#include "DEFINITIONS.h"
#include "Spider.h"

namespace GameEngine
{
	Spider::Spider()
		: Entity ( SCREEN_WIDTH / 2 - SPIDER_SPRITE_SIZE / 2, TURRET_SCREEN_FRACTION * SCREEN_HEIGHT )
	{
		Entity::SetCenterXPosition ( Entity::GetTopLeftXPosition() + SPIDER_SPRITE_SIZE / 2 );
		Entity::SetCenterYPosition ( Entity::GetTopLeftYPosition() + SPIDER_SPRITE_SIZE / 2 );
	}

	void Spider::SetTopLeftXPosition ( float xpos )
	{
		if ( xpos < SCREEN_LHS - SPIDER_SPRITE_SIZE )
		{
			xpos = SCREEN_WIDTH + SPIDER_SPRITE_SIZE;
		}
		else if ( xpos > SCREEN_WIDTH + SPIDER_SPRITE_SIZE )
		{
			xpos = SCREEN_LHS - SPIDER_SPRITE_SIZE;
		}

		Entity::SetTopLeftXPosition ( xpos );
		Entity::SetCenterXPosition ( Entity::GetTopLeftXPosition() + SPIDER_SPRITE_SIZE / 2 );
	}

	void Spider::SetTopLeftYPosition ( float ypos )
	{
		Entity::SetTopLeftYPosition ( ypos );
		Entity::SetCenterYPosition ( Entity::GetTopLeftYPosition() + SPIDER_SPRITE_SIZE / 2 );
	}
} // namespace GameEngine
