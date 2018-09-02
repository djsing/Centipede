#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <SFML/Graphics.hpp>
#include "CentipedeSegment.h"
#include "Game.h"

namespace GameEngine
{
	class Centipede
	{
	public:
		Centipede(DataPtr data);
		void SpawnCentipedeSegments();
	private:
		DataPtr _data;
		std::vector<CentipedeSegment> _centipedeSegments;
	};
}


#endif