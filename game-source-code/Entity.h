#ifndef ENTITY_H
#define ENTITY_H

#include "Region.h"
#include "Direction.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace GameEngine
{
	class Entity
	{
	public:
		Entity(Direction direction, float topLeftXPosition,
				float topLeftYPosition);
		// Mutator functions
		virtual void SetTopLeftXPosition(float xpos);
		virtual void SetTopLeftYPosition(float ypos);
		virtual void SetRegion(Region region);
		virtual void SetSubRegion(Region subregion);
		virtual void SetDead(bool isDead);

		// Accessor Functions
		virtual bool IsDead() const;
		virtual Direction GetDirection() const;
		virtual Region GetRegion() const;
		virtual Region GetSubRegion() const;
		virtual float GetTopLeftXPosition() const;
		virtual float GetTopLeftYPosition() const;

	private:
		// Turret Position/Movement Attributes
		Direction _direction;
		float _topLeftXPosition;
		float _topLeftYPosition;
		Region _region;
		Region _subregion;
		bool _isDead;
	};
}

#endif