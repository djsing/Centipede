#ifndef TURRETRENDERING_H
#define TURRETRENDERING_H

#include "EntityRendering.h"
#include "Turret.h"
#include "BulletRendering.h"
#include "Game.h"
#include <memory>
#include <vector>

namespace GameEngine
{
	class TurretRendering: public EntityRendering
	{
	public:
		TurretRendering(DataPtr data, TurretPtr turret);
		void Draw() override;
	private:
		DataPtr _data;
		TurretPtr _turret;
		BulletRenderPtr _bullet;
		std::vector<sf::Sprite> _lives;
		
	};
}

#endif