#ifndef CENTIPEDERENDERING_H
#define CENTIPEDERENDERING_H

#include "EntityRendering.h"
#include "Centipede.h"
#include "Game.h"
#include <memory>

namespace GameEngine
{
	class CentipedeRendering: public EntityRendering
	{
	public:
		CentipedeRendering(DataPtr data, CentPtr centipede);
		void Draw();
	private:
		DataPtr _data;
		CentPtr _centipede;
	};

	typedef std::unique_ptr<CentipedeRendering> CentRenderPtr;
}

#endif