#include "DEFINITIONS.h"
#include "TurretRendering.h"

namespace GameEngine
{
TurretRendering::TurretRendering(DataPtr data, TurretPtr turret) : _data(data), _turret(turret)
{
    // load turret and heart sprites
    _data->resources.LoadTexture("heart sprite", HEART_FILEPATH);
    _data->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
    turret->GetObjectSprite().setTexture(_data->resources.GetTexture("Turret Sprite"));

    // create life indicators
    for(auto i = 0; i < _data->lives.LivesRemaining(); i++)
	{
	    auto heart = sf::Sprite();
	    heart.setTexture(_data->resources.GetTexture("heart sprite"));
	    _lives.push_back(heart);
	}
}

void TurretRendering::Draw()
{
    _turret->GetObjectSprite().setPosition(_turret->GetTopLeftXPosition(), _turret->GetTopLeftYPosition());
    _data->window.draw(_turret->GetObjectSprite());

    while(_lives.size() != static_cast<unsigned int>(_data->lives.LivesRemaining()))
	{
	    if(_lives.size() == 0)
		{
		    break;
		}
	    _lives.pop_back();
	}

    for(unsigned int i = 1; i <= _lives.size(); i++)
	{
	    _lives.at(i - 1).setPosition(SCREEN_WIDTH - i * HEART_SIZE, WINDOW_TOP);
	    _data->window.draw(_lives.at(i - 1));
	}
}
}  // namespace GameEngine