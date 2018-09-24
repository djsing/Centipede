#ifndef TURRET_H
#define TURRET_H

#include "Bullet.h"
#include "Direction.h"
#include "Entity.h"
#include "Game.h"
#include "Region.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

namespace GameEngine
{
	class Turret : public Entity
	{
	public:
		Turret ();

		// Address Accessor functions
		std::vector<Bullet>& GetBullets();

		// Mutator functions
		void SetTopLeftXPosition ( float xpos );
		void SetTopLeftYPosition ( float ypos );

		// Accessor functions specific to Turret
		float GetLastBulletYPosition();
		int GetLivesRemaining();

	private:
		// Container to store all bullets
		std::vector<Bullet> bullets_;
	};

	using TurretPtr = std::shared_ptr<Turret>;
} // namespace GameEngine

#endif
