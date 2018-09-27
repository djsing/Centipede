#include "CentipedeRendering.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
CentipedeRendering::CentipedeRendering(DataPtr data, CentPtr centipede) : data_(data), centipede_(centipede)
{
    data_->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
    data_->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
}

void CentipedeRendering::Draw()
{
    for(auto& i : centipede_->GetCentipede())
	{
	    if(i.IsFirstSegment())
		{
		    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Segment sprite"));
		}
	    else
		{
		    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Body Segment sprite"));
		}

	    i.GetObjectSprite().setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
	    data_->window.draw(i.GetObjectSprite());
	}
}
}  // namespace GameEngine
