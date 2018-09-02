#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include "Game.h"
#include "Direction.h"
#include "Trajectory.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace GameEngine
{
	class CentipedeSegment
	{
	public:
		CentipedeSegment(DataPtr data);
		sf::Sprite &GetSprite();
		void DrawSegments();
		void SpawnCentipedeSegments();
		void MoveCentipedeSegments(float dt);
	private:
		DataPtr _data;
		sf::Sprite _segment;
		std::vector<sf::Sprite> _centipedeSegmentSprites;
		Direction _direction;
		Trajectory _trajectory;
		float _topLeftXPosition;
		float _topLeftYPosition;
		bool _turningLeft;
		
	};
}

#endif