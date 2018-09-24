#include "Centipede.h"
#include "DEFINITIONS.h"
#include <vector>

namespace GameEngine
{
	Centipede::Centipede ()
	{
	}

	std::vector<CentipedeSegment>& Centipede::GetCentipede()
	{
		return centipede_segments_;
	}

	float Centipede::GetLastSpriteXPosition()
	{
		if ( centipede_segments_.empty() )
		{
			return CENTIPEDE_SPRITE_SIDE_SIZE;
		}
		else
			return centipede_segments_.back().GetTopLeftXPosition();
	}
} // namespace GameEngine
