#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace GameEngine
{
	class CentipedeSegment 
	{
	public:
		CentipedeSegment(DataPtr data);
		void DrawSegments();
	private:
		DataPtr _data;
		std::vector<sf::Sprite> _centipedeSegmentSprites;
	};
}

#endif