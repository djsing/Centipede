#ifndef ENTITYRENDERING_H
#define ENTITYRENDERING_H

namespace GameEngine
{
	class EntityRendering
	{
	public:
		// All game states should have its own declaration of the following functions
		virtual void Draw() = 0;
	};
}

#endif