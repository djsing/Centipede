#include "MushroomRendering.h"

namespace GameEngine
{
	MushroomRendering::MushroomRendering(DataPtr data, FieldPtr field):
	_data(data),
	_field(field)
	{
		
	}

	void MushroomRendering::Draw()
	{
		for (unsigned int i = 0; i < _field->GetMushrooms().size(); i++)
		{
			if (_field->GetMushrooms().at(i).IsPoisoned())
			{
				_field->GetMushrooms().at(i).GetObjectSprite().setTexture(_data->resources.GetTexture("Poisoned Mushroom"));
			}

			_data->window.draw(_field->GetMushrooms().at(i).GetObjectSprite());
		}
	}
}