#include "DEFINITIONS.h"
#include "MushroomRendering.h"

namespace GameEngine
{
MushroomRendering::MushroomRendering(DataPtr data, FieldPtr field)
    : _data(data)
    , _field(field)
{
    _data->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
    _data->resources.LoadTexture("Mushroom3", MUSHROOM3_FILEPATH);
    _data->resources.LoadTexture("Poisoned Mushroom", POISONED_MUSHROOM_FILEPATH);
}

void MushroomRendering::Draw()
{
    for(unsigned int i = 0; i < _field->GetMushrooms().size(); i++)
	{
	    if(_field->GetMushrooms().at(i).IsPoisoned())
		{
		    switch(_field->GetMushrooms().at(i).GetLivesRemaining())
			{
			default:
			    _field->GetMushrooms().at(i).GetObjectSprite().setTexture(
			        _data->resources.GetTexture("Poisoned Mushroom"));
			}
		}
	    else
		{
		    switch(_field->GetMushrooms().at(i).GetLivesRemaining())
			{
			case 3:
			    _field->GetMushrooms().at(i).GetObjectSprite().setTexture(
			        _data->resources.GetTexture("Mushroom3"));
			    break;
			default:
			    _field->GetMushrooms().at(i).GetObjectSprite().setTexture(
			        _data->resources.GetTexture("Mushroom Sprite"));
			}
		}
	    _field->GetMushrooms().at(i).GetObjectSprite().setPosition(
	        _field->GetMushrooms().at(i).GetTopLeftXPosition(), _field->GetMushrooms().at(i).GetTopLeftYPosition());
	    _data->window.draw(_field->GetMushrooms().at(i).GetObjectSprite());
	}
}
} // namespace GameEngine