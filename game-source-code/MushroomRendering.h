#ifndef MUSHROOMRENDERING_H
#define MUSHROOMRENDERING_H

#include "EntityRendering.h"
#include "GameField.h"
#include "Game.h"

namespace GameEngine
{
	class MushroomRendering: public EntityRendering
	{
	public:
		MushroomRendering(DataPtr data, FieldPtr field);
		void Draw();
	private:
		DataPtr _data;
		FieldPtr _field;
	};
}

#endif