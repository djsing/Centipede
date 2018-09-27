#include "DEFINITIONS.h"
#include "Scorpion.h"
#include "ScorpionLogic.h"

namespace GameEngine
{
ScorpionLogic::ScorpionLogic(FieldPtr field)
    : _field(field), _totalTimePerMovement(0), _angle(0), _speed(SCORPION_SPEED)
{
    std::srand(std::time(nullptr));
}

void ScorpionLogic::Spawn()
{
    if(_field->GetScorpions().empty())
	{
	    auto scorpion = Scorpion();
	    _field->GetScorpions().push_back(scorpion);
	    _angle = (std::rand() % 180) * PI / 180;
	}
}

void ScorpionLogic::Move(float dt)
{
    if(!_field->GetScorpions().empty())
	{
	    for(auto& i : _field->GetScorpions())
		{
		    if(_totalTimePerMovement > SCORPION_MOVEMENT_TIME)
			{
			    _angle = (std::rand() % 360) * PI / 180;
			    _totalTimePerMovement = 0;
			}

		    if(i.GetTopLeftYPosition() <= SCREEN_TOP)
			{
			    // keep sprite from moving off screen
			    i.SetTopLeftYPosition(SCREEN_TOP);
			    // move
			    i.SetTopLeftXPosition(i.GetTopLeftXPosition());
			    i.SetTopLeftYPosition(i.GetTopLeftYPosition() + _speed * dt);
			    _angle = (std::rand() % 180) * PI / 180;
			    _totalTimePerMovement += dt;
			    continue;
			}

		    if(i.GetTopLeftYPosition() >= TURRET_SCREEN_FRACTION * SCREEN_HEIGHT - SCORPION_SPRITE_SIZE)
			{
			    // keep sprite from moving off screen
			    i.SetTopLeftYPosition(TURRET_SCREEN_FRACTION * SCREEN_HEIGHT - SCORPION_SPRITE_SIZE);
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

void ScorpionLogic::CollisionHandle()
{
    if(!_field->GetScorpions().empty())
	{
	    auto deadBegin = std::remove(_field->GetScorpions().begin(), _field->GetScorpions().end(), true);
	    _field->GetScorpions().erase(deadBegin, _field->GetScorpions().end());
	}
}
}  // namespace GameEngine
