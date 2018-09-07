#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "CentipedeSegment.h"
#include "Game.h"

namespace GameEngine
{
	class Centipede
	{
	public:
		Centipede(DataPtr data);

		// Address Accessor Functions
		std::vector<CentipedeSegment> &GetCentipede();

		// Accessor Fucntions
		float GetLastSpriteXPosition();
		float GetSegmentCenterXPosition(unsigned int index);
		float GetSegmentCenterYPosition(unsigned int index);

		// ----------------------STILL TO REMOVE WITH LAYERING------------------
		void DestroyCentipedeSegments(); // logic layering required
	private:
		// pointer to GameData layer
		DataPtr _data;
		// data container to store CentipedeSegments
		std::vector<CentipedeSegment> _centipedeSegments;
	};

	typedef std::shared_ptr<Centipede> CentPtr;
}


#endif