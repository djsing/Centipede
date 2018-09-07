#include "Mushroom.h"

namespace GameEngine
{
	Mushroom::Mushroom(DataPtr data, float xpos, float ypos, Region region, Region subregion):
	_data(data),
	_topLeftXPosition(xpos),
	_topLeftYPosition(ypos),
	_region(region),
	_subregion(subregion)
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

	Region Mushroom::GetRegion()
	{
		return _region;
	}

	Region Mushroom::GetSubRegion()
	{
		return _subregion;
	}
}