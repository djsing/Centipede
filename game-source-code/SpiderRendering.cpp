#include "SpiderRendering.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	SpiderRendering::SpiderRendering(DataPtr data, FieldPtr field):
	_data(data),
	_field(field)
	{
		_data->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
	}

	void SpiderRendering::Draw()
	{
		if (!_field->GetSpiders().empty())
		{
			for (unsigned int i = 0; i < _field->GetSpiders().size(); i++)
			{
				_field->GetSpiders().at(i).GetObjectSprite().setTexture(_data->resources.GetTexture("Spider sprite"));
				_field->GetSpiders().at(i).GetObjectSprite().setPosition(
					_field->GetSpiders().at(i).GetTopLeftXPosition(),
					_field->GetSpiders().at(i).GetTopLeftYPosition());
				_data->window.draw(_field->GetSpiders().at(i).GetObjectSprite());
			}
		}
	}
}