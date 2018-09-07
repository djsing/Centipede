#include "BulletRendering.h"

namespace GameEngine
{
	BulletRendering::BulletRendering(DataPtr data, Bullet &bullet):
	_data(data),
	_bullet(bullet)
	{
		
	}

	void BulletRendering::Draw()
	{
		_data->window.draw(_bullet.GetBullet());
	}
}