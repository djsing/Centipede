#include "ScorpionLogic.h"
#include "Scorpion.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	ScorpionLogic::ScorpionLogic(FieldPtr field, DataPtr data):
	_data(data),
	_field(field),
	_totalTimePerMovement(0),
	_angle(0),
	_speed(SCORPION_SPEED)
	{
		std::srand(std::time(nullptr));
	}

	void ScorpionLogic::Spawn()
	{
		if (_field->GetScorpions().empty())
		{
			auto scorpion = Scorpion(_data);
			_field->GetScorpions().push_back(scorpion);
			_angle = (std::rand()%180)*PI/180;
		}
	}

	void ScorpionLogic::Move(float dt)
	{
		if (!_field->GetScorpions().empty())
		{
			for (unsigned int i = 0; i < _field->GetScorpions().size(); i++)
			{
				if (_totalTimePerMovement > SCORPION_MOVEMENT_TIME)
				{
					_angle = (std::rand()%360)*PI/180;
					_totalTimePerMovement = 0;
				}

				if (_field->GetScorpions().at(i).GetTopLeftYPosition() <= SCREEN_TOP)
				{
					// keep sprite from moving off screen
					_field->GetScorpions().at(i).SetTopLeftYPosition(SCREEN_TOP);
					// move
					_field->GetScorpions().at(i).SetTopLeftXPosition(_field->GetScorpions().at(i).GetTopLeftXPosition());
					_field->GetScorpions().at(i).SetTopLeftYPosition(_field->GetScorpions().at(i).GetTopLeftYPosition() +
						_speed*dt);
					_angle = (std::rand()%180)*PI/180;
					_totalTimePerMovement += dt;
					continue;
				}

				if (_field->GetScorpions().at(i).GetTopLeftYPosition() >= TURRET_SCREEN_FRACTION*SCREEN_HEIGHT - SCORPION_SPRITE_SIZE)
				{
					// keep sprite from moving off screen
					_field->GetScorpions().at(i).SetTopLeftYPosition(TURRET_SCREEN_FRACTION*SCREEN_HEIGHT - SCORPION_SPRITE_SIZE);
					// move
					_field->GetScorpions().at(i).SetTopLeftXPosition(_field->GetScorpions().at(i).GetTopLeftXPosition());
					_field->GetScorpions().at(i).SetTopLeftYPosition(_field->GetScorpions().at(i).GetTopLeftYPosition() -
						_speed*dt);
					_angle = (std::rand()%360)*PI/180;
					_totalTimePerMovement += dt;
					continue;
				}

				_field->GetScorpions().at(i).SetTopLeftXPosition(_field->GetScorpions().at(i).GetTopLeftXPosition() +
					_speed*dt*cos(_angle));
				_field->GetScorpions().at(i).SetTopLeftYPosition(_field->GetScorpions().at(i).GetTopLeftYPosition() +
					_speed*dt*sin(_angle));
				_totalTimePerMovement += dt;
			}
		}
	}

	void ScorpionLogic::CollisionHandle()
	{
		if (!_field->GetScorpions().empty())
		{
			for (unsigned int i = 0; i < _field->GetScorpions().size(); i++)
			{
				if (_field->GetScorpions().at(i).IsDead())
				{
					_field->GetScorpions().erase(_field->GetScorpions().begin() + i);
					i--;
				}
			}
		}
	}
}