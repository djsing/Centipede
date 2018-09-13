#include "CentipedeRendering.h"

namespace GameEngine
{
	CentipedeRendering::CentipedeRendering(DataPtr data, CentPtr centipede):
	_data(data),
	_centipede(centipede)
	{
		
	}

	void CentipedeRendering::Draw()
	{
		for (unsigned int i = 0; i < _centipede->GetCentipede().size(); i++)
		{
			if (_centipede->GetCentipede().at(i).IsFirstSegment())
			{
				_centipede->GetCentipede().at(i).GetSegmentSprite().setTexture(_data->resources.GetTexture("Segment sprite"));
			}
			_data->window.draw(_centipede->GetCentipede().at(i).GetSegmentSprite());
		}
	}
}