#include "Entity.h"

namespace GameEngine
{
	Entity::Entity ( float topLeftXPosition, float topLeftYPosition )
		: top_left_x_position_ ( topLeftXPosition )
		, top_left_y_position_ ( topLeftYPosition )
		, isDead_ ( false )
	{
	}

	void Entity::SetDirection ( Direction direction )
	{
		direction_ = direction;
	}

	void Entity::SetTopLeftXPosition ( float xpos )
	{
		top_left_x_position_ = xpos;
	}

	void Entity::SetTopLeftYPosition ( float ypos )
	{
		top_left_y_position_ = ypos;
	}

	void Entity::SetRegion ( Region region )
	{
		region_ = region;
	}

	void Entity::SetSubRegion ( Region subregion )
	{
		subregion_ = subregion;
	}

	void Entity::SetDead ( bool isDead )
	{
		isDead_ = isDead;
	}

	void Entity::SetCenterXPosition ( float xpos )
	{
		center_x_position_ = xpos;

		region_handler_ = RegionHandler{center_x_position_, center_y_position_};
		SetRegion ( region_handler_.GetRegion() );
		SetSubRegion ( region_handler_.GetSubRegion() );
	}

	void Entity::SetCenterYPosition ( float ypos )
	{
		center_y_position_ = ypos;

		region_handler_ = RegionHandler{center_x_position_, center_y_position_};
		SetRegion ( region_handler_.GetRegion() );
		SetSubRegion ( region_handler_.GetSubRegion() );
	}

	sf::Sprite& Entity::GetObjectSprite()
	{
		return object_;
	}

	bool Entity::IsDead() const
	{
		return isDead_;
	}

	Direction Entity::GetDirection() const
	{
		return direction_;
	}

	Region Entity::GetRegion() const
	{
		return region_;
	}

	Region Entity::GetSubRegion() const
	{
		return subregion_;
	}

	float Entity::GetTopLeftXPosition() const
	{
		return top_left_x_position_;
	}

	float Entity::GetTopLeftYPosition() const
	{
		return top_left_y_position_;
	}

	float Entity::GetCenterXPosition() const
	{
		return center_x_position_;
	}

	float Entity::GetCenterYPosition() const
	{
		return center_y_position_;
	}
} // namespace GameEngine
