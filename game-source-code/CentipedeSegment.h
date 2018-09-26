#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include "Direction.h"
#include "Entity.h"
#include "Game.h"
#include "Region.h"
#include "Trajectory.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class CentipedeSegment : public Entity
	{
	public:
		CentipedeSegment ( bool firstSegment = false);

		// Mutator Functions
		void SetTopLeftXPosition ( float xpos );
		void SetTopLeftYPosition ( float ypos );
		void SetFirstSegment ( bool isFirstSegment );

		// Mutators specific to CentipedeSegment
		void SetTrajectory ( Trajectory trajectory );
		void SetTurningLeft ( bool isTurningLeft );
		void SetPoisoned ( bool isPoisoned );

		// Accessor Functions specifc to Centipede Segment
		Trajectory GetTrajectory();
		bool IsFirstSegment();
		bool IsTurningLeft();
		bool IsPoisoned();

	private:
		// movement information
		bool turning_left_;
		Trajectory trajectory_;
		// segment characteristics
		bool first_segment_;
		bool is_poisoned_;
	};
} // namespace GameEngine

#endif
