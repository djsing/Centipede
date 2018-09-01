#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include "Game.h"
#include "Direction.h"
#include "Trajectory.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace GameEngine
{
	class Centipede
	{
	public:
		Centipede(DataPtr data);
		void DrawSegments();
		void SpawnCentipedeSegments();
		void MoveCentipedeSegments(float dt);
	private:
		DataPtr _data;
		std::vector<sf::Sprite> _centipedeSegmentSprites;
		Direction _direction;
		Trajectory _trajecory;
		int _topLeftPosition;
		bool _turningLeft;
		
	};
}

#endif