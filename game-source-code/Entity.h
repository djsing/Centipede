#ifndef ENTITY_H
#define ENTITY_H

#include "Direction.h"
#include "Region.h"
#include "RegionHandler.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace GameEngine
{
	class Entity
	{
	public:
		Entity ( float topLeftXPosition, float topLeftYPosition );
		// Mutator functions
		virtual void SetDirection ( Direction direction );
		virtual void SetTopLeftXPosition ( float xpos );
		virtual void SetTopLeftYPosition ( float ypos );
		virtual void SetRegion ( Region region );
		virtual void SetSubRegion ( Region subregion );
		virtual void SetDead ( bool isDead );
		virtual void SetCenterXPosition ( float xpos );
		virtual void SetCenterYPosition ( float ypos );

		// Accessor Functions
		sf::Sprite& GetObjectSprite();
		bool IsDead() const;
		Direction GetDirection() const;
		Region GetRegion() const;
		Region GetSubRegion() const;
		float GetTopLeftXPosition() const;
		float GetTopLeftYPosition() const;
		float GetCenterXPosition() const;
		float GetCenterYPosition() const;

	private:
		sf::Sprite object_;
		// Position/Movement Attributes
		Direction direction_;
		float top_left_x_position_;
		float top_left_y_position_;
		float center_x_position_;
		float center_y_position_;
		RegionHandler region_handler_;
		Region region_;
		Region subregion_;
		bool isDead_;
	};
} // namespace GameEngine

#endif
