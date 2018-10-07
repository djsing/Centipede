#include "DEFINITIONS.h"
#include "LivesHandler.h"

namespace GameEngine
{
LivesHandler::LivesHandler() : lives_remaining_(STARTING_LIVES)
{
}

unsigned int LivesHandler::LivesRemaining()
{
    return lives_remaining_;
}

void LivesHandler::LifeLost()
{
    lives_remaining_--;
}

void LivesHandler::LifeGained()
{
    if(lives_remaining_ < STARTING_LIVES)
	{
	    lives_remaining_++;
	}
}

void LivesHandler::ResetLives()
{
    lives_remaining_ = STARTING_LIVES;
}

}  // namespace GameEngine
