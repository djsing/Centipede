#include "Centipede.h"
#include "Direction.h"
#include "Trajectory.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	Centipede::Centipede(DataPtr data):
	_data(data),
	_direction(Direction::RIGHT),
	_trajecory(Trajectory::DOWNWARD),
	_topLeftPosition(0),
	_turningLeft(true)
	{
		
	}

	void Centipede::DrawSegments()
	{
		for (unsigned int i = 0; i < _centipedeSegmentSprites.size(); i++) 
		{
			_data->window.draw(_centipedeSegmentSprites.at(i));
		}
	}

	void Centipede::SpawnCentipedeSegments()
	{
		sf::Sprite segment;
		segment.setTexture(_data->resources.GetTexture("Segment sprite"));
		segment.setPosition(0, 0);
		_centipedeSegmentSprites.push_back(segment);
	}

	void Centipede::MoveCentipedeSegments(float dt)
	{
		auto moveDistance = CENTIPEDE_MOVEMENT_SPEED*dt;
		// move sprite moveDistance away in the current direction
		for (unsigned int i = 0; i < _centipedeSegmentSprites.size(); i++)
		{
			// Check whether centipede is moving to the bottom/top  of screen
			switch (_trajecory)
			{
				// check direction of centipede movement
				case Trajectory::DOWNWARD:
					switch (_direction)
					{
						case Direction::RIGHT:
						if ((_topLeftPosition + 100) > (SCREEN_WIDTH))
						{
							_direction = Direction::DOWN;
						} else _centipedeSegmentSprites.at(i).move(moveDistance, 0);
					}
			}
		}
	}
}