#include "DEFINITIONS.h"
#include "SpiderRendering.h"

namespace GameEngine
{
SpiderRendering::SpiderRendering(DataPtr data, FieldPtr field) : data_(data), field_(field)
{
    data_->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
}

void SpiderRendering::Draw()
{
    if(!field_->GetSpiders().empty())
	{
	    for(auto& i : field_->GetSpiders())
		{
		    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Spider sprite"));
		    i.GetObjectSprite().setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
		    data_->window.draw(i.GetObjectSprite());
		}
	}
}
}  // namespace GameEngine