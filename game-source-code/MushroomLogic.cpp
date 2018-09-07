#include "MushroomLogic.h"

namespace GameEngine
{
	MushroomLogic::MushroomLogic(FieldPtr field):
	_field(field)
	{
		
	}

	void MushroomLogic::CollisionHandle()
	{
		for (unsigned int i = 0; i < _field->GetMushrooms().size(); i++)
		{
			
		}
	}
}