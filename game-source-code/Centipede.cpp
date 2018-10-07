#include <vector>
#include "Centipede.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
std::vector<CentipedeSegment>& Centipede::GetCentipede()
{
    return centipede_segments_;
}

float Centipede::GetLastSpriteXPosition()
{
    if(centipede_segments_.empty())
	{
	    return CENTIPEDE_SPRITE_SIDE_SIZE;
	}
    else
	return centipede_segments_.back().GetTopLeftXPosition();
}
}  // namespace GameEngine
