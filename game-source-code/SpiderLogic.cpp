#include "SpiderLogic.h"
#include "Spider.h"
#include "DEFINITIONS.h"
#include "RegionHandler.h"
#include <ctime>
#include <cstdlib>

namespace GameEngine
{
	SpiderLogic::SpiderLogic(FieldPtr field, DataPtr data):
	_data(data),
	_field(field),
	_totalTimePerMovement(0),
	_speed(SPIDER_SPEED)
	{
		std::srand(std::time(nullptr));
		_angle = (std::rand()%90)*PI/180;
	}

	void SpiderLogic::Spawn()
	{
		auto spider = Spider(_data);
		_field->GetSpiders().push_back(spider);
	}

	void SpiderLogic::Move(float dt)
	{
		if (!_field->GetSpiders().empty())
		{
			for (unsigned int i = 0; i < _field->GetSpiders().size(); i++)
			{
				if (_totalTimePerMovement > SPIDER_MOVEMENT_TIME)
				{
					_angle = (std::rand()%360)*PI/180;
					_totalTimePerMovement = 0;
				}
				else if (_field->GetSpiders().at(i).GetTopLeftYPosition() <= TURRET_SCREEN_FRACTION*SCREEN_HEIGHT)
				{
					// keep sprite from moving off screen
					_field->GetSpiders().at(i).SetTopLeftYPosition(TURRET_SCREEN_FRACTION*SCREEN_HEIGHT);
					_field->GetSpiders().at(i).GetObjectSprite().setPosition(_field->GetSpiders().at(i).GetTopLeftXPosition(),
						_field->GetSpiders().at(i).GetTopLeftYPosition());
					// move
					_field->GetSpiders().at(i).GetObjectSprite().move(0, _speed*dt);
					_field->GetSpiders().at(i).SetTopLeftXPosition(_field->GetSpiders().at(i).GetTopLeftXPosition());
					_field->GetSpiders().at(i).SetTopLeftYPosition(_field->GetSpiders().at(i).GetTopLeftYPosition() +
						_speed*dt);
					_angle = (std::rand()%360)*PI/180;
					_totalTimePerMovement += dt;
					continue;
				}
				else if (_field->GetSpiders().at(i).GetTopLeftYPosition() >= SCREEN_HEIGHT - SPIDER_SPRITE_SIZE)
				{
					// keep sprite from moving off screen
					_field->GetSpiders().at(i).SetTopLeftYPosition(SCREEN_HEIGHT - SPIDER_SPRITE_SIZE);
					_field->GetSpiders().at(i).GetObjectSprite().setPosition(_field->GetSpiders().at(i).GetTopLeftXPosition(),
						_field->GetSpiders().at(i).GetTopLeftYPosition());
					// move
					_field->GetSpiders().at(i).GetObjectSprite().move(0, -_speed*dt);
					_field->GetSpiders().at(i).SetTopLeftXPosition(_field->GetSpiders().at(i).GetTopLeftXPosition());
					_field->GetSpiders().at(i).SetTopLeftYPosition(_field->GetSpiders().at(i).GetTopLeftYPosition() -
						_speed*dt);
					_angle = (std::rand()%360)*PI/180;
					_totalTimePerMovement += dt;
					continue;
				}
				else if (_field->GetSpiders().at(i).GetTopLeftXPosition() <= SCREEN_LHS)
				{
					// keep sprite from moving off screen
					_field->GetSpiders().at(i).SetTopLeftXPosition(SCREEN_LHS);
					_field->GetSpiders().at(i).GetObjectSprite().setPosition(_field->GetSpiders().at(i).GetTopLeftXPosition(),
						_field->GetSpiders().at(i).GetTopLeftYPosition());
					// move
					_field->GetSpiders().at(i).GetObjectSprite().move(_speed*dt, 0);
					_field->GetSpiders().at(i).SetTopLeftXPosition(_field->GetSpiders().at(i).GetTopLeftXPosition() +
						_speed*dt);
					_field->GetSpiders().at(i).SetTopLeftYPosition(_field->GetSpiders().at(i).GetTopLeftYPosition());
					_angle = (std::rand()%360)*PI/180;
					_totalTimePerMovement += dt;
					continue;
				}
				else if (_field->GetSpiders().at(i).GetTopLeftXPosition() >= SCREEN_WIDTH - SPIDER_SPRITE_SIZE)
				{
					// keep sprite from moving off screen
					_field->GetSpiders().at(i).SetTopLeftXPosition(SCREEN_WIDTH - SPIDER_SPRITE_SIZE);
					_field->GetSpiders().at(i).GetObjectSprite().setPosition(_field->GetSpiders().at(i).GetTopLeftXPosition(),
						_field->GetSpiders().at(i).GetTopLeftYPosition());
					// move
					_field->GetSpiders().at(i).GetObjectSprite().move(0, -_speed*dt);
					_field->GetSpiders().at(i).SetTopLeftXPosition(_field->GetSpiders().at(i).GetTopLeftXPosition() -
						_speed*dt);
					_field->GetSpiders().at(i).SetTopLeftYPosition(_field->GetSpiders().at(i).GetTopLeftYPosition());
					_angle = (std::rand()%360)*PI/180;
					_totalTimePerMovement += dt;
					continue;
				}
				else
				{
					_field->GetSpiders().at(i).GetObjectSprite().move(_speed*dt*cos(_angle), _speed*dt*sin(_angle));
					_field->GetSpiders().at(i).SetTopLeftXPosition(_field->GetSpiders().at(i).GetTopLeftXPosition() +
						_speed*dt*cos(_angle));
					_field->GetSpiders().at(i).SetTopLeftYPosition(_field->GetSpiders().at(i).GetTopLeftYPosition() +
						_speed*dt*sin(_angle));
					_totalTimePerMovement += dt;
				}

				auto region = RegionHandler(_field->GetSpiders().at(i).GetCenterXPosition(),
					_field->GetSpiders().at(i).GetCenterYPosition());
				_field->GetSpiders().at(i).SetRegion(region.GetRegion());
				_field->GetSpiders().at(i).SetSubRegion(region.GetSubRegion());
			}
		}
	}

	void SpiderLogic::CollisionHandle()
	{
		if (!_field->GetSpiders().empty())
		{
			for (unsigned int i = 0; i < _field->GetSpiders().size(); i++)
			{
				if (_field->GetSpiders().at(i).IsDead())
				{
					_field->GetSpiders().erase(_field->GetSpiders().begin() + i);
					i--;
				}
			}
		}
	}
}