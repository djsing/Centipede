#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Trajectory.h"
#include "Game.h"

namespace GameEngine
{
	class CentipedeSegment
	{
	public:
		CentipedeSegment(DataPtr data);
		void MoveSprite(int x, int y);
		sf::Sprite GetSegmentSprite();
		void SetDirection(Direction direction);
		Direction GetDirection();
		void SetTrajectory(Trajectory trajectory);
		Trajectory GetTrajectory();
		int GetTopLeftPosition();
		void SetTurningLeft();
	private:
		DataPtr _data;
		sf::Sprite _segmentSprite;
		Direction _direction;
		Trajectory _trajecory;
		int _topLeftPosition;
		bool _turningLeft;
	};
}

#endif