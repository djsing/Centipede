#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include "Game.h"
#include "Direction.h"
#include "Trajectory.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class CentipedeSegment
	{
	public:
		CentipedeSegment(DataPtr data);
		void DrawSegments();
		void MoveCentipedeSegments(float dt);
	private:
		DataPtr _data;
		sf::Sprite _segment;
		Direction _direction;
		Trajectory _trajectory;
		float _topLeftXPosition;
		float _topLeftYPosition;
		bool _turningLeft;
		
	};
}

#endif