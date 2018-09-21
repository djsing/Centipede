#include "CentipedeRendering.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	CentipedeRendering::CentipedeRendering(DataPtr data, CentPtr centipede):
	_data(data),
	_centipede(centipede)
	{
		_data->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
		_data->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
	}

	void CentipedeRendering::Draw()
	{
		for (unsigned int i = 0; i < _centipede->GetCentipede().size(); i++)
		{
			if (_centipede->GetCentipede().at(i).IsFirstSegment())
			{
				_centipede->GetCentipede().at(i).GetObjectSprite().setTexture(_data->resources.GetTexture("Segment sprite"));
			}
			else
			{
				_centipede->GetCentipede().at(i).GetObjectSprite().setTexture(_data->resources.GetTexture("Body Segment sprite"));
			}
			_centipede->GetCentipede().at(i).GetObjectSprite().setPosition(
				_centipede->GetCentipede().at(i).GetTopLeftXPosition(),
				_centipede->GetCentipede().at(i).GetTopLeftYPosition());
			_data->window.draw(_centipede->GetCentipede().at(i).GetObjectSprite());
		}
	}
}