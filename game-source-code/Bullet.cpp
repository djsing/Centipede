#include "Bullet.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	Bullet::Bullet ( float xpos, float ypos )
		: Entity ( xpos, ypos )
	{
		Entity::SetCenterXPosition ( Entity::GetTopLeftXPosition() + BULLET_WIDTH / 2 );
		Entity::SetCenterYPosition ( Entity::GetTopLeftYPosition() + BULLET_HEIGHT / 2 );
		Entity::SetDirection ( Direction::UP );
	}

	void Bullet::SetTopLeftXPosition ( float xpos )
	{
		Entity::SetTopLeftXPosition ( xpos );
		Entity::SetCenterXPosition ( Entity::GetTopLeftXPosition() + BULLET_WIDTH / 2 );
	}

	void Bullet::SetTopLeftYPosition ( float ypos )
	{
		Entity::SetTopLeftYPosition ( ypos );
		Entity::SetCenterYPosition ( Entity::GetTopLeftYPosition() + BULLET_HEIGHT / 2 );
	}
} // namespace GameEngine
