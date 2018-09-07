#include "Centipede.h"
#include "DEFINITIONS.h"
#include <vector>

namespace GameEngine
{
	Centipede::Centipede(DataPtr data):
	_data(data)
	{
		
	}

	std::vector<CentipedeSegment> &Centipede::GetCentipede()
	{
		return _centipedeSegments;
	}

	float Centipede::GetLastSpriteXPosition()
	{
		if (_centipedeSegments.empty())
		{
			return CENTIPEDE_SPRITE_SIDE_SIZE;
		} else return _centipedeSegments.back().GetTopLeftXPosition();
	}

	float Centipede::GetSegmentCenterXPosition(unsigned int index)
	{
		return _centipedeSegments.at(index).GetCenterXPosition();
	}

	float Centipede::GetSegmentCenterYPosition(unsigned int index)
	{
		return _centipedeSegments.at(index).GetCenterYPosition();
	}

	void Centipede::DestroyCentipedeSegments()
	{
		for (unsigned int i = 0; i < _centipedeSegments.size(); i++)
		{
			if (_centipedeSegments.at(i).IsDead())
			{
				_centipedeSegments.erase(_centipedeSegments.begin() + i);
				i--;
			}
		}
	}
}