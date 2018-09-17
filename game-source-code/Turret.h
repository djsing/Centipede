#ifndef TURRET_H
#define TURRET_H

#include "Game.h"
#include "Bullet.h"
#include "Direction.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Entity.h"
#include "Region.h"

namespace GameEngine
{
	class Turret: public Entity
	{
	public:
		Turret(DataPtr data);

		// Address Accessor functions
		sf::Sprite &GetTurretSprite();
		std::vector<Bullet> &GetBullets();

		// Mutator functions
		void SetSpritePosition(float xpos, float ypos);
		void SetTopLeftXPosition(float xpos);
		void SetTopLeftYPosition(float ypos);
		void SetRegion(Region region);
		void SetSubRegion(Region subregion);
		void SetDead(bool isDead);
		void DecrementLives();

		// Accessor functions specific to Turret
		float GetLastBulletYPosition();
		int GetLivesRemaining();

	private:
		// Data layer pointer
		DataPtr _data;
		// Turret sprite
		sf::Sprite _turret;
		// Container to store all visible bullets
		std::vector<Bullet> _bullets;
		int _livesRemaining;
	};

	// Shared pointer to a Turret Object
	typedef std::shared_ptr<Turret> TurretPtr;
}

#endif