#include "BulletRendering.h"

namespace GameEngine
{
BulletRendering::BulletRendering(DataPtr data, std::vector<Bullet>& bullets)
    : _data(data)
    , _bullets(bullets)
{
}

void BulletRendering::Draw()
{
    for(unsigned int i = 0; i < _bullets.size(); i++)
	{
	    _bullets.at(i).GetObjectSprite().setTexture(_data->resources.GetTexture("Bullet sprite"));
	    _bullets.at(i).GetObjectSprite().setPosition(_bullets.at(i).GetTopLeftXPosition(),
	                                                 _bullets.at(i).GetTopLeftYPosition());
	    _data->window.draw(_bullets.at(i).GetObjectSprite());
	}
}
} // namespace GameEngine