#include "StateHandler.h"

namespace GameEngine
{
void StateHandler::AddState(StatePtr newState, bool replacing)
{
    // track changes to be made
    adding_ = true;
    replacing_ = replacing;
    // move location of newState to new_state_
    new_state_ = std::move(newState);
}

void StateHandler::RemoveState()
{
    removing_ = true;
}

void StateHandler::ProcessStateChanges()
{
    if(removing_ && !states_.empty())
	{
	    states_.pop();
	    removing_ = false;
	}

    if(adding_)
	{
	    if(!states_.empty())
		{
		    // if we are replacing, first remove the state at the top of the stack
		    if(replacing_)
			{
			    states_.pop();
			}
		}

	    // move location of new_state_ to stack
	    states_.push(std::move(new_state_));
	    // we are no longer adding a state
	    adding_ = false;
	}
}

StatePtr& StateHandler::GetActiveGameState()
{
    return states_.top();
}
}  // namespace GameEngine
