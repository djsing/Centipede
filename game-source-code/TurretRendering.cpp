#include "TurretRendering.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	TurretRendering::TurretRendering(DataPtr data, TurretPtr turret):
	_data(data),
	_turret(turret)
	{
		for (int i = 0; i < _turret->GetLivesRemaining(); i++)
		{
			auto heart = sf::Sprite();
			heart.setTexture(_data->resources.GetTexture("heart sprite"));
			_lives.push_back(heart);
		}
	}

	void TurretRendering::Draw()
	{
		for (unsigned int i = 0; i < _turret->GetBullets().size(); i++)
		{
			_bullet = std::make_unique<BulletRendering>(_data, _turret->GetBullets().at(i));
			_bullet->Draw();
		}
		_data->window.draw(_turret->GetTurretSprite());

		while (_lives.size() != static_cast<unsigned int>(_turret->GetLivesRemaining()))
		{
			if (_lives.size() == 0)
			{
				break;
			}
			_lives.pop_back();
		}

		for (unsigned int i = 1; i <= _lives.size(); i++)
		{
			_lives.at(i - 1).setPosition(SCREEN_WIDTH - i*HEART_SIZE, SCREEN_TOP);
			_data->window.draw(_lives.at(i - 1));
		}
	}
}