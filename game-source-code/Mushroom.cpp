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
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + MUSHROOM_SPRITE_SIZE/2);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + MUSHROOM_SPRITE_SIZE/2);
	}

	sf::Sprite &Mushroom::GetMushroomSprite()
	{
		return _mushroom;
	}
}