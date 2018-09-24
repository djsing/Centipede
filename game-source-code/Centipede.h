#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include "CentipedeSegment.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace GameEngine
{
	class Centipede
	{
	public:
		Centipede ();

		// Address Accessor Functions
		std::vector<CentipedeSegment>& GetCentipede();

		// Accessor Fucntions
		float GetLastSpriteXPosition();

	private:
		// data container to store CentipedeSegments
		std::vector<CentipedeSegment> centipede_segments_;
	};

	using CentPtr = std::shared_ptr<Centipede>;
} // namespace GameEngine

#endif
