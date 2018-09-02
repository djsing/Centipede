#include "Centipede.h"
#include "CentipedeSegment.h"
#include "Game.h"
#include <vector>

namespace GameEngine
{
	Centipede::Centipede(DataPtr data):
	_data(data)
	{
		
	}

	float Centipede::GetLastSpriteXPosition()
	{
		return _centipedeSegments.back().GetTopLeftXPosition();
	}

	void Centipede::SpawnCentipedeSegments(bool firstSegment)
	{
		auto segment = CentipedeSegment(_data, firstSegment);
		_centipedeSegments.push_back(segment);
	}

	void Centipede::DrawCentipedeSegments()
	{
		// traverse the vector and draw the sprites
		for (unsigned int i = 0; i < _centipedeSegments.size(); i++) 
		{
			_centipedeSegments.at(i).DrawSegments();
		}
	}

	void Centipede::MoveCentipede(float dt)
	{
		for (unsigned int i = 0; i < _centipedeSegments.size(); i++ )
		{
			_centipedeSegments.at(i).MoveCentipedeSegments(dt);
		}
	}
}