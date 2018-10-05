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
    life_.setTexture(data_->resources.GetTexture("heart sprite"));
    data_->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH);
    data_->resources.LoadTexture("Bomb sprite", BOMB_FILEPATH);
    data_->resources.LoadTexture("Explosion sprite", EXPLOSION_FILEPATH);
    explosion_.setTexture(data_->resources.GetTexture("Explosion sprite"));
    turret->GetObjectSprite().setTexture(data_->resources.GetTexture("Turret Sprite"));
}

void EntityRendering::Draw()
{
    DrawBombs();
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

    for(unsigned int i = 1; i <= static_cast<unsigned int>(data_->lives.LivesRemaining()); i++)
	{
	    life_.setPosition(SCREEN_WIDTH - i * HEART_SIZE, WINDOW_TOP);
	    data_->window.draw(life_);
	}
}

void EntityRendering::DrawBombs()
{
    // draw bombs
    for(auto& i : field_->GetBombs())
	{
	    if(i.IsTriggered())
		{
		    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Explosion sprite"));
		    explosion_.setPosition(i.GetCenterXPosition() - EXPLOSION_SPRITE_SIZE / 2,
		                           i.GetCenterYPosition() - EXPLOSION_SPRITE_SIZE / 2);
		    data_->window.draw(explosion_);
		}
	    else
		{
		    i.GetObjectSprite().setTexture(data_->resources.GetTexture("Bomb sprite"));
		    i.GetObjectSprite().setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
		    data_->window.draw(i.GetObjectSprite());
		}
	}
}
}  // namespace GameEngine