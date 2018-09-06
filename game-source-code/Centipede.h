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
		std::vector<CentipedeSegment> &GetCentipede();
		float GetLastSpriteXPosition();
		void SpawnCentipedeSegments(bool firstSegment = false);
		void DrawCentipedeSegments();
		void MoveCentipede(float dt);
		void DestroyCentipedeSegments();
		float GetSegmentCenterXPosition(unsigned int index);
		float GetSegmentCenterYPosition(unsigned int index);
	private:
		DataPtr _data;
		std::vector<CentipedeSegment> _centipedeSegments;
	};

	typedef std::shared_ptr<Centipede> CentPtr;
}


#endif