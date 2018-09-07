#include "TurretRendering.h"

namespace GameEngine
{
	TurretRendering::TurretRendering(DataPtr data, TurretPtr turret):
	_data(data),
	_turret(turret)
	{
		
	}

	void TurretRendering::Draw()
	{
		for (unsigned int i = 0; i < _turret->GetBullets().size(); i++)
		{
			_bullet = std::make_unique<BulletRendering>(_data, _turret->GetBullets().at(i));
			_bullet->Draw();
		}
		_data->window.draw(_turret->GetTurretSprite());
	}
}