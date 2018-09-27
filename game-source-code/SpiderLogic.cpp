#include <cstdlib>
#include <ctime>
#include "DEFINITIONS.h"
#include "Spider.h"
#include "SpiderLogic.h"

namespace GameEngine
{
SpiderLogic::SpiderLogic(FieldPtr field) : _field(field), _totalTimePerMovement(0), _speed(SPIDER_SPEED)
{
    std::srand(std::time(nullptr));
}

void SpiderLogic::Spawn()
{
    if(_field->GetSpiders().empty())
	{
	    auto spider = Spider();
	    _field->GetSpiders().push_back(spider);
	    _angle = (std::rand() % 180) * PI / 180;
	}
}

void SpiderLogic::Move(float dt)
{
    if(!_field->GetSpiders().empty())
	{
	    for(auto& i : _field->GetSpiders())
		{
		    if(_totalTimePerMovement > SPIDER_MOVEMENT_TIME)
			{
			    _angle = (std::rand() % 360) * PI / 180;
			    _totalTimePerMovement = 0;
			}

		    if(i.GetTopLeftYPosition() <= TURRET_SCREEN_FRACTION * SCREEN_HEIGHT)
			{
			    // keep sprite from moving off screen
			    i.SetTopLeftYPosition(TURRET_SCREEN_FRACTION * SCREEN_HEIGHT);
			    // move
			    i.SetTopLeftXPosition(i.GetTopLeftXPosition());
			    i.SetTopLeftYPosition(i.GetTopLeftYPosition() + _speed * dt);
			    _angle = (std::rand() % 180) * PI / 180;
			    _totalTimePerMovement += dt;
			    continue;
			}

		    if(i.GetTopLeftYPosition() >= SCREEN_HEIGHT - SPIDER_SPRITE_SIZE)
			{
			    // keep sprite from moving off screen
			    i.SetTopLeftYPosition(SCREEN_HEIGHT - SPIDER_SPRITE_SIZE);
			    // move
			    i.SetTopLeftXPosition(i.GetTopLeftXPosition());
			    i.SetTopLeftYPosition(i.GetTopLeftYPosition() - _speed * dt);
			    _angle = (std::rand() % 360) * PI / 180;
			    _totalTimePerMovement += dt;
			    continue;
			}

		    i.SetTopLeftXPosition(i.GetTopLeftXPosition() + _speed * dt * cos(_angle));
		    i.SetTopLeftYPosition(i.GetTopLeftYPosition() + _speed * dt * sin(_angle));
		    _totalTimePerMovement += dt;
		}
	}
}

void SpiderLogic::CollisionHandle()
{
    if(!_field->GetSpiders().empty())
	{
	    auto deadBegin = std::remove(_field->GetSpiders().begin(), _field->GetSpiders().end(), true);
	    _field->GetSpiders().erase(deadBegin, _field->GetSpiders().end());
	}
}
}  // namespace GameEngine
