#include "DEFINITIONS.h"
#include "LivesHandler.h"

namespace GameEngine
{
LivesHandler::LivesHandler()
    : _livesRemaining(STARTING_LIVES)
{
}

int LivesHandler::LivesRemaining()
{
    return _livesRemaining;
}

void LivesHandler::LifeLost()
{
    _livesRemaining--;
}

void LivesHandler::LifeGained()
{
    if(_livesRemaining < 3)
	{
	    _livesRemaining++;
	}
}

void LivesHandler::ResetLives()
{
    _livesRemaining = STARTING_LIVES;
}

} // namespace GameEngine