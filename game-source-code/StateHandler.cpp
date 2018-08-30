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

			if (!_states.empty())
			{
				_states.top()->Resume();
			}
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
				else // we are just adding, before adding a game state, pause the current state
				{
					_states.top()->Pause();
				}
			}
			// move location of _newState to stack
			_states.push(std::move(_newState));
			// initialise the new game state
			_states.top()->Initialise();
			// we are no longer adding a state
			_isAdding = false;
		}
	}

	StatePtr &StateHandler::GetActiveGameState()
	{
		return _states.top();
	}
}