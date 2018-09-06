#include "CentipedeLogic.h"
#include "CentipedeSegment.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	CentipedeLogic::CentipedeLogic(DataPtr data, CentPtr centipede):
	_data(data),
	_centipede(centipede),
	_speed(CENTIPEDE_SPEED),
	_isFirstSegment(true)
	{
		
	}

	void CentipedeLogic::Spawn()
	{
		// creates 'head' spawn at first, then 'body' for the remainder
		auto segment = CentipedeSegment(_data, _isFirstSegment);
		_centipede->GetCentipede().push_back(segment);
		_isFirstSegment = false;
	}

	void CentipedeLogic::Move(float dt)
	{
		
	}

	void CentipedeLogic::CollisionCheck()
	{
		
	}

	void CentipedeLogic::CollisionHandle()
	{
		
	}
}