#include "Centipede.h"
#include "DEFINITIONS.h"
#include <vector>

namespace GameEngine
{
Centipede::Centipede(DataPtr data)
    : _data(data)
{
}

std::vector<CentipedeSegment>& Centipede::GetCentipede()
{
    return _centipedeSegments;
}

float Centipede::GetLastSpriteXPosition()
{
    if(_centipedeSegments.empty())
	{
	    return CENTIPEDE_SPRITE_SIDE_SIZE;
	}
    else
	return _centipedeSegments.back().GetTopLeftXPosition();
}
} // namespace GameEngine