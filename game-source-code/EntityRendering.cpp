#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "EntityRendering.h"

namespace GameEngine
{
EntityRendering::EntityRendering(DataPtr data, TurretPtr turret, CentPtr centipede, FieldPtr field)
    : data_(data), turret_(turret), centipede_(centipede), field_(field)
{
    data_->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
    data_->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH);
    data_->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH);
    data_->resources.LoadTexture("Mushroom Sprite", MUSHROOM_FILEPATH);
    data_->resources.LoadTexture("Mushroom3", MUSHROOM3_FILEPATH);
    data_->resources.LoadTexture("Poisoned Mushroom", POISONED_MUSHROOM_FILEPATH);
    data_->resources.LoadTexture("Scorpion sprite", SCORPION_FILEPATH);
    data_->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH);
    data_->resources.LoadTexture("heart sprite", HEART_FILEPATH);
    data_->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
    turret->GetObjectSprite().setTexture(data_->resources.GetTexture("Turret Sprite"));

    // create life indicators
    for(auto i = 0; i < data_->lives.LivesRemaining(); i++)
	{
	    auto heart = sf::Sprite();
	    heart.setTexture(data_->resources.GetTexture("heart sprite"));
	    lives_.push_back(heart);
	}
}

void EntityRendering::Draw()
{
    DrawMushrooms();
    DrawCentipede();
    DrawScorpions();
    DrawBullets();
    DrawTurret();
    DrawSpiders();
}

void EntityRendering::DrawBullets()
{
    for(auto& i : turret_->GetBullets())
	{
	    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Bullet sprite"));
	    i.GetObjectSprite().setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
	    data_->window.draw(i.GetObjectSprite());
	}
}

void EntityRendering::DrawCentipede()
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

void EntityRendering::DrawMushrooms()
{
    for(auto& i : field_->GetMushrooms())
	{
	    if(i.IsPoisoned())
		{
		    switch(i.GetLivesRemaining())
			{
			default:
			    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Poisoned Mushroom"));
			}
		}
	    else
		{
		    switch(i.GetLivesRemaining())
			{
			case 3:
			    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Mushroom3"));
			    break;
			default:
			    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Mushroom Sprite"));
			}
		}
	    i.GetObjectSprite().setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
	    data_->window.draw(i.GetObjectSprite());
	}
}

void EntityRendering::DrawScorpions()
{
    if(!field_->GetScorpions().empty())
	{
	    for(auto& i : field_->GetScorpions())
		{
		    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Scorpion sprite"));
		    i.GetObjectSprite().setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
		    data_->window.draw(i.GetObjectSprite());
		}
	}
}

void EntityRendering::DrawSpiders()
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

void EntityRendering::DrawTurret()
{
    turret_->GetObjectSprite().setPosition(turret_->GetTopLeftXPosition(), turret_->GetTopLeftYPosition());
    data_->window.draw(turret_->GetObjectSprite());

    while(lives_.size() != static_cast<unsigned int>(data_->lives.LivesRemaining()))
	{
	    if(lives_.size() == 0)
		{
		    break;
		}
	    lives_.pop_back();
	}

    for(unsigned int i = 1; i <= lives_.size(); i++)
	{
	    lives_.at(i - 1).setPosition(SCREEN_WIDTH - i * HEART_SIZE, WINDOW_TOP);
	    data_->window.draw(lives_.at(i - 1));
	}
}
}  // namespace GameEngine