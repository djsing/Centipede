#include "DEFINITIONS.h"
#include "MushroomRendering.h"

namespace GameEngine
{
MushroomRendering::MushroomRendering(DataPtr data, FieldPtr field) : _data(data), _field(field)
{
    _data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
    _data->resources.LoadTexture("Mushroom3", MUSHROOM3_FILEPATH);
    _data->resources.LoadTexture("Poisoned Mushroom", POISONED_MUSHROOM_FILEPATH);
}

void MushroomRendering::Draw()
{
    for(auto& i : _field->GetMushrooms())
	{
	    if(i.IsPoisoned())
		{
		    switch(i.GetLivesRemaining())
			{
			    default:
				i.GetObjectSprite().setTexture(_data->resources.GetTexture("Poisoned Mushroom"));
			}
		}
	    else
		{
		    switch(i.GetLivesRemaining())
			{
			    case 3:
				i.GetObjectSprite().setTexture(_data->resources.GetTexture("Mushroom3"));
				break;
			    default:
				i.GetObjectSprite().setTexture(_data->resources.GetTexture("Mushroom Sprite"));
			}
		}
	    i.GetObjectSprite().setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
	    _data->window.draw(i.GetObjectSprite());
	}
}
}  // namespace GameEngine