#include <cstdlib>
#include <ctime>
#include "DEFINITIONS.h"
#include "Spider.h"
#include "SpiderLogic.h"

namespace GameEngine
{
SpiderLogic::SpiderLogic(FieldPtr field) : _field(field), _speed(SPIDER_SPEED)
{
    std::srand(std::time(nullptr));
    spawn_timer_.restart();
    move_timer_.restart();
}

void SpiderLogic::Spawn()
{
    if(spawn_timer_.getElapsedTime() > SPIDER_TIME)
	{
	    auto spider = Spider();
	    spider.SetAngle((std::rand() % 181) * PI / 180);
	    _field->GetSpiders().push_back(spider);
	    spawn_timer_.restart();
	}
}

void SpiderLogic::Move(float dt)
{
    if(!_field->GetSpiders().empty())
	{
	    // if it is time to change direction, change the spiders' angle of movement
	    if(move_timer_.getElapsedTime() > SPIDER_MOVEMENT_TIME)
		{
		    for(auto& i : _field->GetSpiders())
			{
			    ChangeDirection(i);
			}
		    move_timer_.restart();
		}

	    // move the spiders across the sreen
	    for(auto& i : _field->GetSpiders())
		{
		    // if the spider is above the player box
		    if(i.GetTopLeftYPosition() <= TURRET_SCREEN_FRACTION * SCREEN_HEIGHT)
			{
			    // keep sprite from moving above player box
			    i.SetTopLeftYPosition(TURRET_SCREEN_FRACTION * SCREEN_HEIGHT);
			    // move
			    i.SetTopLeftXPosition(i.GetTopLeftXPosition());
			    i.SetTopLeftYPosition(i.GetTopLeftYPosition() + _speed * dt);
			    i.SetAngle((std::rand() % 181) * PI / 180);
			    continue;
			}

		    if(i.GetTopLeftYPosition() >= SCREEN_HEIGHT - SPIDER_SPRITE_SIZE)
			{
			    // keep sprite from moving below screen
			    i.SetTopLeftYPosition(SCREEN_HEIGHT - SPIDER_SPRITE_SIZE);
			    // move
			    i.SetTopLeftXPosition(i.GetTopLeftXPosition());
			    i.SetTopLeftYPosition(i.GetTopLeftYPosition() - _speed * dt);
			    i.SetAngle((std::rand() % 361) * PI / 180);
			    continue;
			}

		    i.SetTopLeftXPosition(i.GetTopLeftXPosition() + _speed * dt * cos(i.GetAngle()));
		    i.SetTopLeftYPosition(i.GetTopLeftYPosition() + _speed * dt * sin(i.GetAngle()));
		}
	}
}

void SpiderLogic::CollisionHandle()
{
    if(!_field->GetSpiders().empty())
	{
	    auto deadBegin = std::remove(_field->GetSpiders().begin(), _field->GetSpiders().end(), true);
	    _field->GetSpiders().erase(deadBegin, _field->GetSpiders().end());
	    if(_field->GetSpiders().empty())
		{
		    spawn_timer_.restart();
		}
	}
}

void SpiderLogic::ChangeDirection(Spider& index)
{
    // random angle between 0 and 360 degrees
    index.SetAngle((std::rand() % 361) * PI / 180);
}

}  // namespace GameEngine
