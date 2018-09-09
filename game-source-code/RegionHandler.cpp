#include "RegionHandler.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	RegionHandler::RegionHandler(float xpos, float ypos):
	_xpos(xpos),
	_ypos(ypos)
	{
		// left side of screen
		if (_xpos <= (SCREEN_WIDTH/2))
		{
			// top half of screen
			if (_ypos <= (SCREEN_HEIGHT/2))
			{
				_region = Region::TOP_LEFT;
				// left side of top left quarter
				if (_xpos <= (SCREEN_WIDTH/4))
				{
					// top half of left quarter
					if (_ypos <= (SCREEN_HEIGHT/4))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right side of top left quarter
				else
				{
					// top half of left quarter
					if (_ypos <= (SCREEN_HEIGHT/4))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
			// bottom half of screen
			else
			{
				_region = Region::BOTTOM_LEFT;
				// left half of bottom left quarter
				if (_xpos <= (SCREEN_WIDTH/4))
				{
					// top half of bottom left quarter
					if (_ypos <= (SCREEN_HEIGHT*3/4))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of bottom left quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right half of bottom left quarter
				else
				{
					// top half of left quarter
					if (_ypos <= (SCREEN_HEIGHT*3/4))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
		}
		// right side of screen
		else
		{
			// top half of screen
			if (_ypos <= (SCREEN_HEIGHT/2))
			{
				_region = Region::TOP_RIGHT;
				// left half of top right quarter
				if (_xpos <= (SCREEN_WIDTH*3/4))
				{
					// top half of left quarter
					if (_ypos <= (SCREEN_HEIGHT/4))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right side of top right quarter
				else
				{
					// top half of top right quarter
					if (_ypos <= (SCREEN_HEIGHT/4))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of top right quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
			// bottom half of screen
			else
			{
				_region = Region::BOTTOM_RIGHT;
				// 
				if (_xpos <= (SCREEN_WIDTH*3/4))
				{
					// top half of right bottom quarter
					if (_ypos <= (SCREEN_HEIGHT*3/4))
					{
						_subregion = Region::TOP_LEFT;
					}
					// bottom half of right bottom quarter
					else
					{
						_subregion = Region::BOTTOM_LEFT;
					}
				}
				// right side of bottom right quarter
				else
				{
					// top half of left quarter
					if (_ypos <= (SCREEN_HEIGHT*3/4))
					{
						_subregion = Region::TOP_RIGHT;
					}
					// bottom half of left quarter
					else
					{
						_subregion = Region::BOTTOM_RIGHT;
					}
				}
			}
		}
	}

	Region RegionHandler::GetRegion()
	{
		return _region;
	}

	Region RegionHandler::GetSubRegion()
	{
		return _subregion;
	}
}