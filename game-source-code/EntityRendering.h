#ifndef ENTITYRENDERING_H
#define ENTITYRENDERING_H

#include <memory>

namespace GameEngine
{
	class EntityRendering
	{
	public:
		// All game states should have its own declaration of the following functions
		virtual void Draw() = 0;
	};
	using RenderPtr = std::unique_ptr<EntityRendering>;
} // namespace GameEngine

#endif
