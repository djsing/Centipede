#include "DEFINITIONS.h"
#include "ScorpionRendering.h"

namespace GameEngine
{
ScorpionRendering::ScorpionRendering(DataPtr data, FieldPtr field) : _data(data), _field(field)
{
    _data->resources.LoadTexture("Scorpion sprite", SCORPION_FILEPATH);
}

void ScorpionRendering::Draw()
{
    if(!_field->GetScorpions().empty())
	{
	    for(auto& i : _field->GetScorpions())
		{
		    i.GetObjectSprite().setTexture(_data->resources.GetTexture("Scorpion sprite"));
		    i.GetObjectSprite().setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
		    _data->window.draw(i.GetObjectSprite());
		}
	}
}
}  // namespace GameEngine