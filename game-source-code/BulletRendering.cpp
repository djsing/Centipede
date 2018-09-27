#include "BulletRendering.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
BulletRendering::BulletRendering(DataPtr data, std::vector<Bullet>& bullets) : data_(data), bullets_(bullets)
{
    data_->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
}

void BulletRendering::Draw()
{
    for(auto& i : bullets_)
	{
	    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Bullet sprite"));
	    i.GetObjectSprite().setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
	    data_->window.draw(i.GetObjectSprite());
	}
}
}  // namespace GameEngine
