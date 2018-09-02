#ifndef GAMESTATE_H
#define GAMESTATE_H

namespace GameEngine
{
	class GameState
	{
	public:
		// All game states should have its own declaration of the following functions
		virtual void Initialise() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw() = 0;

		// empty Functions to represent pause and resume a particular game state
		virtual void Pause(){}
		virtual void Resume(){}
	};
}

#endif