#include "Mushroom.h"
#include "Direction.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	Mushroom::Mushroom(DataPtr data, float xpos, float ypos):
	Entity(Direction::HOVER, xpos, ypos),
	_data(data),
	_isPoisoned(false)
	{
		_mushroom.setTexture(_data->resources.GetTexture("Mushroom Sprite"));
		_mushroom.setPosition(Entity::GetTopLeftXPosition(), Entity::GetTopLeftYPosition());
	}

	sf::Sprite &Mushroom::GetMushroomSprite()
	{
		return _mushroom;
	}

	float Mushroom::GetMushroomCenterXPosition()
	{
		return Entity::GetTopLeftXPosition() + MUSHROOM_SPRITE_SIZE/2;
	}

	float Mushroom::GetMushroomCenterYPosition()
	{
		return Entity::GetTopLeftYPosition() + MUSHROOM_SPRITE_SIZE/2;
	}
}