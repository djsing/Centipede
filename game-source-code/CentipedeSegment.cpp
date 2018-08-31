#include "CentipedeSegment.h"

namespace GameEngine
{
	CentipedeSegment::CentipedeSegment(DataPtr data):
	_data(data)
	{}

	void CentipedeSegment::DrawSegments()
	{
		for (unsigned int i = 0; i < _centipedeSegmentSprites.size(); i++) 
		{
			_data->window.draw(_centipedeSegmentSprites.at(i));
		}
	}
}