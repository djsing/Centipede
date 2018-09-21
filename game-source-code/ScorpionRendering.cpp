#include "ScorpionRendering.h"

namespace GameEngine
{
	ScorpionRendering::ScorpionRendering(DataPtr data, FieldPtr field):
	_data(data),
	_field(field)
	{
		
	}

	void ScorpionRendering::Draw()
	{
		if (!_field->GetScorpions().empty())
		{
			for (unsigned int i = 0; i < _field->GetScorpions().size(); i++)
			{
				_field->GetScorpions().at(i).GetObjectSprite().setPosition(
					_field->GetScorpions().at(i).GetTopLeftXPosition(),
					_field->GetScorpions().at(i).GetTopLeftYPosition());
				_data->window.draw(_field->GetScorpions().at(i).GetObjectSprite());
			}
		}
	}
}