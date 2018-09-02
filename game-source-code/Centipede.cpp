#include "Centipede.h"
#include "CentipedeSegment.h"
#include "Game.h"

namespace GameEngine
{
	Centipede::Centipede(DataPtr data):
	_data(data)
	{
		
	}

	void Centipede::SpawnCentipedeSegments()
	{
		auto segment = CentipedeSegment(_data);
	}
}