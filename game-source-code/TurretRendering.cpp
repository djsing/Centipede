#include "DEFINITIONS.h"
#include "TurretRendering.h"

namespace GameEngine
{
TurretRendering::TurretRendering(DataPtr data, TurretPtr turret)
    : _data(data)
    , _turret(turret)
{
    // load turret, bullet, heart sprites
    _data->resources.LoadTexture("heart sprite", HEART_FILEPATH);
    _data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
    _data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
    turret->GetObjectSprite().setTexture(_data->resources.GetTexture("Turret Sprite"));

    _bullets = std::make_unique<BulletRendering>(_data, _turret->GetBullets());

    // create life indicators
    for(int i = 0; i < _turret->GetLivesRemaining(); i++)
	{
	    auto heart = sf::Sprite();
	    heart.setTexture(_data->resources.GetTexture("heart sprite"));
	    _lives.push_back(heart);
	}
}

void TurretRendering::Draw()
{
    _bullets->Draw();
    _turret->GetObjectSprite().setPosition(_turret->GetTopLeftXPosition(), _turret->GetTopLeftYPosition());
    _data->window.draw(_turret->GetObjectSprite());

    while(_lives.size() != static_cast<unsigned int>(_turret->GetLivesRemaining()))
	{
	    if(_lives.size() == 0)
		{
		    break;
		}
	    _lives.pop_back();
	}

    for(unsigned int i = 1; i <= _lives.size(); i++)
	{
	    _lives.at(i - 1).setPosition(SCREEN_WIDTH - i * HEART_SIZE, SCREEN_TOP);
	    _data->window.draw(_lives.at(i - 1));
	}
}
} // namespace GameEngine