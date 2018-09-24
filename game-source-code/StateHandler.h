#ifndef STATEHANDLER_H
#define STATEHANDLER_H

#include "GameState.h"
#include <memory>
#include <stack>

namespace GameEngine
{
	class StateHandler
	{
	public:
		// default constructor
		StateHandler()
		{
		}
		// destructor
		~StateHandler()
		{
		}
		// Track whether a state is to be added; assume that the
		// state to be added is replacing the state at the top of the stack
		void AddState ( StatePtr newState, bool replacing = true );
		// manually remove state at top of the stack
		void RemoveState();
		// make changes to the actual data container (stack);
		// runs at the beginning of every game loop in the Game class
		void ProcessStateChanges();
		// return current (active) game state
		StatePtr& GetActiveGameState();

	private:
		// stack data container to store game states
		std::stack<StatePtr> states_;
		// member which tracks a new game state to be added to the stack
		StatePtr new_state_;
		// members to track whether a game state is to be added, replaced, or removed
		bool adding_;
		bool removing_;
		bool replacing_;
	};
} // namespace GameEngine

#endif
