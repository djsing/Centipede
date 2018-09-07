#ifndef BULLETRENDERING_H
#define BULLETRENDERING_H

#include "EntityRendering.h"
#include "Bullet.h"
#include "Game.h"
#include <memory>

namespace GameEngine
{
	class BulletRendering: public EntityRendering
	{
	public:
		BulletRendering(DataPtr data, Bullet &bullet);
		void Draw();
	private:
		DataPtr _data;
		Bullet &_bullet;
	};

	typedef std::unique_ptr<BulletRendering> BulletRenderPtr;
}

#endif