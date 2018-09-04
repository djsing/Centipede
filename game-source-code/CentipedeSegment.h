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
		CentipedeSegment(bool firstSegment);
		CentipedeSegment(DataPtr data, bool firstSegment);
		float GetSpeed();
		bool IsFirstSegment();
		bool IsTurningLeft();
		Trajectory GetTrajectory();
		Direction GetDirection();
		float GetTopLeftXPosition();
		float GetTopLeftYPosition();
		float GetCenterXPosition();
		float GetCenterYPosition();
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
		void SetFirstSegment(bool firstSegment);
		bool _firstSegment;
		float _speed;
	};
}

#endif