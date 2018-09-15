#include "Spider.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	Spider::Spider(DataPtr data):
	Entity(SCREEN_WIDTH/2 - SPIDER_SPRITE_SIZE/2, 0.8*SCREEN_HEIGHT),
	_data(data)
	{
		Entity::GetObjectSprite().setTexture(_data->resources.GetTexture("Spider sprite"));
		Entity::GetObjectSprite().setPosition(Entity::GetTopLeftXPosition(), Entity::GetTopLeftYPosition());
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + SPIDER_SPRITE_SIZE/2);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + SPIDER_SPRITE_SIZE/2);
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