#include "Turret.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	Turret::Turret(DataPtr data):
	Entity(SCREEN_WIDTH/2 - TURRET_SPRITE_SIDE_SIZE/2,
			SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE),
	_data(data),
	_livesRemaining(3)
	{
		Entity::SetDirection(Direction::HOVER);
		_turret.setTexture(_data->resources.GetTexture("Turret Sprite"));
		_turret.setPosition(Entity::GetTopLeftXPosition(),Entity::GetTopLeftYPosition());
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + TURRET_SPRITE_SIDE_SIZE/2);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + TURRET_SPRITE_SIDE_SIZE/2);
	}

	sf::Sprite &Turret::GetTurretSprite()
	{
		return _turret;
	}

	std::vector<Bullet> &Turret::GetBullets()
	{
		return _bullets;
	}

	void Turret::SetSpritePosition(float xpos, float ypos)
	{
		_turret.setPosition(xpos, ypos);
	}

	void Turret::SetTopLeftXPosition(float xpos)
	{
		Entity::SetTopLeftXPosition(xpos);
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + TURRET_SPRITE_SIDE_SIZE/2);
	}

	void Turret::SetTopLeftYPosition(float ypos)
	{
		Entity::SetTopLeftYPosition(ypos);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + TURRET_SPRITE_SIDE_SIZE/2);
	}

	void Turret::SetRegion(Region region)
	{
		Entity::SetRegion(region);
	}

	void Turret::SetSubRegion(Region subregion)
	{
		Entity::SetSubRegion(subregion);
	}

	void Turret::SetDead(bool isDead)
	{
		Entity::SetDead(isDead);
	}

	void Turret::DecrementLives()
	{
		Entity::SetTopLeftXPosition(SCREEN_WIDTH/2 - TURRET_SPRITE_SIDE_SIZE/2);
		Entity::SetTopLeftYPosition(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE);
		_turret.setPosition(Entity::GetTopLeftXPosition(),Entity::GetTopLeftYPosition());
		Entity::SetCenterXPosition(Entity::GetTopLeftXPosition() + TURRET_SPRITE_SIDE_SIZE/2);
		Entity::SetCenterYPosition(Entity::GetTopLeftYPosition() + TURRET_SPRITE_SIDE_SIZE/2);
		_livesRemaining--;
	}

	float Turret::GetLastBulletYPosition()
	{
		if (_bullets.empty())
		{
			return GetTopLeftYPosition() - BULLET_HEIGHT;
		}
		return _bullets.back().GetTopLeftYPosition();
	}

	int Turret::GetLivesRemaining()
	{
		return _livesRemaining;
	}
}