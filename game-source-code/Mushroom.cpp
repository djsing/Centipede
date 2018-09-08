#include "Mushroom.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	Mushroom::Mushroom(DataPtr data, float xpos, float ypos):
	_data(data),
	_topLeftXPosition(xpos),
	_topLeftYPosition(ypos)
	{
		_mushroom.setTexture(_data->resources.GetTexture("Mushroom Sprite"));
		_mushroom.setPosition(_topLeftXPosition, _topLeftYPosition);
	}

	sf::Sprite &Mushroom::GetMushroomSprite()
	{
		return _mushroom;
	}

	float Mushroom::GetTopLeftXPosition()
	{
		return _topLeftXPosition;
	}

	float Mushroom::GetTopLeftYPosition()
	{
		return _topLeftYPosition;
	}

	float Mushroom::GetMushroomCenterXPosition()
	{
		return _topLeftXPosition + MUSHROOM_SPRITE_SIZE/2;
	}

	float Mushroom::GetMushroomCenterYPosition()
	{
		return _topLeftYPosition + MUSHROOM_SPRITE_SIZE/2;
	}
}