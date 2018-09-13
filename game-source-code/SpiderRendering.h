#ifndef SPIDERRENDERING_H
#define SPIDERRANDERING_H

#include "EntityRendering.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
	class SpiderRendering: public EntityRendering
	{
	public:
		SpiderRendering(DataPtr data, FieldPtr field);
		void Draw() override;
	private:
		DataPtr _data;
		FieldPtr _field;
	};
}

#endif