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
		_bullet.GetObjectSprite().setPosition(_bullet.GetTopLeftXPosition(), _bullet.GetTopLeftYPosition());
		_data->window.draw(_bullet.GetObjectSprite());
	}
}