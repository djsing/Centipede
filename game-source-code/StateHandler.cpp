#include "StateHandler.h"

namespace GameEngine
{
	void StateHandler::AddState(StatePtr newState, bool isReplacing)
	{
		// track changes to be made
		_isAdding = true;
		_isReplacing = isReplacing;
		// move location of newState to _newState
		_newState = std::move(newState);
	}

	void StateHandler::RemoveState()
	{
		_isRemoving = true;
	}

	void StateHandler::ProcessStateChanges()
	{
		if (_isRemoving && !_states.empty())
		{
			_states.pop();
			_isRemoving = false;
		}

		if (_isAdding)
		{
			if (!_states.empty())
			{	// if we are replacing, first remove the state at the top of the stack
				if (_isReplacing)
				{
					_states.pop();
				}
			}
			// move location of _newState to stack
			_states.push(std::move(_newState));
			// we are no longer adding a state
			_isAdding = false;
		}
	}

	StatePtr &StateHandler::GetActiveGameState()
	{
		return _states.top();
	}
}