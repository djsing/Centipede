#include <string>
#include "DEFINITIONS.h"
#include "EntityRendering.h"

namespace GameEngine
{
EntityRendering::EntityRendering(DataPtr data, TurretPtr turret, CentPtr centipede, FieldPtr field)
    : data_(data), turret_(turret), centipede_(centipede), field_(field)
{
    // load all entity related sprites
    data_->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH_);
    data_->resources.LoadTexture("Segment sprite", SEGMENT_FILEPATH_);
    data_->resources.LoadTexture("Body Segment sprite", BODY_SEGMENT_FILEPATH_);
    data_->resources.LoadTexture("Mushroom", MUSHROOM_FILEPATH_);
    data_->resources.LoadTexture("Mushroom3", MUSHROOM3_FILEPATH_);
    data_->resources.LoadTexture("Mushroom2", MUSHROOM2_FILEPATH_);
    data_->resources.LoadTexture("Mushroom1", MUSHROOM1_FILEPATH_);
    data_->resources.LoadTexture("Poisoned Mushroom", POISONED_MUSHROOM_FILEPATH_);
    data_->resources.LoadTexture("Poisoned Mushroom3", POISONED_MUSHROOM3_FILEPATH_);
    data_->resources.LoadTexture("Poisoned Mushroom2", POISONED_MUSHROOM2_FILEPATH_);
    data_->resources.LoadTexture("Poisoned Mushroom1", POISONED_MUSHROOM1_FILEPATH_);
    data_->resources.LoadTexture("Scorpion sprite", SCORPION_FILEPATH_);
    data_->resources.LoadTexture("Spider sprite", SPIDER_FILEPATH_);
    data_->resources.LoadTexture("heart sprite", HEART_FILEPATH_);
    data_->resources.LoadTexture("Turret Sprite", TURRET_FILEPATH_);
    data_->resources.LoadTexture("Bomb sprite", BOMB_FILEPATH_);
    data_->resources.LoadTexture("Explosion sprite", EXPLOSION_FILEPATH_);
    // load score related sprites
    data_->resources.LoadTexture("0", NUMBER_0);
    data_->resources.LoadTexture("1", NUMBER_1);
    data_->resources.LoadTexture("2", NUMBER_2);
    data_->resources.LoadTexture("3", NUMBER_3);
    data_->resources.LoadTexture("4", NUMBER_4);
    data_->resources.LoadTexture("5", NUMBER_5);
    data_->resources.LoadTexture("6", NUMBER_6);
    data_->resources.LoadTexture("7", NUMBER_7);
    data_->resources.LoadTexture("8", NUMBER_8);
    data_->resources.LoadTexture("9", NUMBER_9);
    // bind textures to sprites
    life_.setTexture(data_->resources.GetTexture("heart sprite"));
    explosion_.setTexture(data_->resources.GetTexture("Explosion sprite"));
    turret_sprite_.setTexture(data_->resources.GetTexture("Turret Sprite"));
    body_segment_.setTexture(data_->resources.GetTexture("Body Segment sprite"));
    head_segment_.setTexture(data_->resources.GetTexture("Segment sprite"));
    scorpion_.setTexture(data_->resources.GetTexture("Scorpion sprite"));
    spider_.setTexture(data_->resources.GetTexture("Spider sprite"));
    bomb_.setTexture(data_->resources.GetTexture("Bomb sprite"));
    bullet_.setTexture(data_->resources.GetTexture("Bullet sprite"));
    mushroom_.setTexture(data_->resources.GetTexture("Mushroom"));
    mushroom1_.setTexture(data_->resources.GetTexture("Mushroom1"));
    mushroom2_.setTexture(data_->resources.GetTexture("Mushroom2"));
    mushroom3_.setTexture(data_->resources.GetTexture("Mushroom3"));
    poisoned_mushroom_.setTexture(data_->resources.GetTexture("Poisoned Mushroom"));
    poisoned_mushroom1_.setTexture(data_->resources.GetTexture("Poisoned Mushroom1"));
    poisoned_mushroom2_.setTexture(data_->resources.GetTexture("Poisoned Mushroom2"));
    poisoned_mushroom3_.setTexture(data_->resources.GetTexture("Poisoned Mushroom3"));
    // bind texture related to scores
    zero_.setTexture(data_->resources.GetTexture("0"));
    one_.setTexture(data_->resources.GetTexture("1"));
    two_.setTexture(data_->resources.GetTexture("2"));
    three_.setTexture(data_->resources.GetTexture("3"));
    four_.setTexture(data_->resources.GetTexture("4"));
    five_.setTexture(data_->resources.GetTexture("5"));
    six_.setTexture(data_->resources.GetTexture("6"));
    seven_.setTexture(data_->resources.GetTexture("7"));
    eight_.setTexture(data_->resources.GetTexture("8"));
    nine_.setTexture(data_->resources.GetTexture("9"));
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
    DisplayScore();
}

void EntityRendering::DrawBullets()
{
    for(auto& i : turret_->GetBullets())
	{
	    bullet_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
	    data_->window.draw(bullet_);
	}
}

void EntityRendering::DrawCentipede()
{
    for(auto& i : centipede_->GetCentipede())
	{
	    if(i.IsFirstSegment())
		{
		    head_segment_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
		    data_->window.draw(head_segment_);
		}
	    else
		{
		    body_segment_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
		    data_->window.draw(body_segment_);
		}
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
			case 3:
			    poisoned_mushroom3_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
			    data_->window.draw(poisoned_mushroom3_);
			    break;
			case 2:
			    poisoned_mushroom2_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
			    data_->window.draw(poisoned_mushroom2_);
			    break;
			case 1:
			    poisoned_mushroom1_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
			    data_->window.draw(poisoned_mushroom1_);
			    break;
			default:
			    poisoned_mushroom_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
			    data_->window.draw(poisoned_mushroom_);
			}
		}
	    else
		{
		    switch(i.GetLivesRemaining())
			{
			case 3:
			    mushroom3_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
			    data_->window.draw(mushroom3_);
			    break;
			case 2:
			    mushroom2_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
			    data_->window.draw(mushroom2_);
			    break;
			case 1:
			    mushroom1_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
			    data_->window.draw(mushroom1_);
			    break;
			default:
			    mushroom_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
			    data_->window.draw(mushroom_);
			}
		}
	}
}

void EntityRendering::DrawScorpions()
{
    if(!field_->GetScorpions().empty())
	{
	    for(auto& i : field_->GetScorpions())
		{
		    scorpion_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
		    data_->window.draw(scorpion_);
		}
	}
}

void EntityRendering::DrawSpiders()
{
    if(!field_->GetSpiders().empty())
	{
	    for(auto& i : field_->GetSpiders())
		{
		    spider_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
		    data_->window.draw(spider_);
		}
	}
}

void EntityRendering::DrawTurret()
{
    turret_sprite_.setPosition(turret_->GetTopLeftXPosition(), turret_->GetTopLeftYPosition());
    data_->window.draw(turret_sprite_);

    // draw number of lives remaining
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
		    explosion_.setPosition(i.GetCenterXPosition() - EXPLOSION_SPRITE_SIZE / 2,
		                           i.GetCenterYPosition() - EXPLOSION_SPRITE_SIZE / 2);
		    data_->window.draw(explosion_);
		}
	    else
		{
		    bomb_.setPosition(i.GetTopLeftXPosition(), i.GetTopLeftYPosition());
		    data_->window.draw(bomb_);
		}
	}
}

void EntityRendering::DisplayScore()
{
    auto score = std::to_string(data_->score_manager.GetScore());
    for(unsigned int i = 0; i < score.size(); i++)
	{
	    switch(score.at(i))
		{
		case '0':
		    zero_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
		    data_->window.draw(zero_);
		    break;
		case '1':
		    one_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
		    data_->window.draw(one_);
		    break;
		case '2':
		    two_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
		    data_->window.draw(two_);
		    break;
		case '3':
		    three_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
		    data_->window.draw(three_);
		    break;
		case '4':
		    four_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
		    data_->window.draw(four_);
		    break;
		case '5':
		    five_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
		    data_->window.draw(five_);
		    break;
		case '6':
		    six_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
		    data_->window.draw(six_);
		    break;
		case '7':
		    seven_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
		    data_->window.draw(seven_);
		    break;
		case '8':
		    eight_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
		    data_->window.draw(eight_);
		    break;
		case '9':
		    nine_.setPosition(i * NUMBER_SIZE, WINDOW_TOP);
		    data_->window.draw(nine_);
		default:
		    break;
		}
	}
}
}  // namespace GameEngine