#ifndef REGIONHANDLER_H
#define REGIONHANDLER_H

#include "Region.h"

namespace GameEngine
{
	class RegionHandler
	{
	public:
		// default constructor
		RegionHandler(){}
		// takes in center point
		RegionHandler(float xpos, float ypos);
		Region GetRegion();
		Region GetSubRegion();
	private:
		float _xpos;
		float _ypos;
		Region _region;
		Region _subregion;
	};
}

#endif