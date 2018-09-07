#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include "Game.h"
#include "Direction.h"
#include "Trajectory.h"
#include "Region.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class CentipedeSegment
	{
	public:
		CentipedeSegment(DataPtr data, bool firstSegment);

		// Address Accessor Functions
		sf::Sprite &GetSegmentSprite();

		// Mutator Functions
		void SetDirection(Direction direction);
		void SetTrajectory(Trajectory trajectory);
		void SetTopLeftXPosition(float xpos);
		void SetTopLeftYPosition(float ypos);
		void SetTurningLeft(bool isTurningLeft);
		void SetRegion(Region region);
		void SetSubRegion(Region subregion);

		// Accessor Functions
		bool IsFirstSegment();
		bool IsTurningLeft();
		bool IsDead();
		Trajectory GetTrajectory();
		Direction GetDirection();
		float GetTopLeftXPosition();
		float GetTopLeftYPosition();
		float GetCenterXPosition();
		float GetCenterYPosition();

	private:
		// pointer to GameData layer
		DataPtr _data;
		sf::Sprite _segment;
		// movement information
		bool _turningLeft;
		Direction _direction;
		Trajectory _trajectory;
		// position information
		float _topLeftXPosition;
		float _topLeftYPosition;
		Region _region;
		Region _subregion;
		// segment characteristics
		bool _firstSegment;
		float _speed;
		bool _dead;
	};
}

#endif