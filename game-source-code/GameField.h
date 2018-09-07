#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Mushroom.h"
#include <vector>
#include <memory>

namespace GameEngine
{
	class GameField
	{
	public:
		GameField(){}
		std::vector<Mushroom> &GetMushrooms();
	private:
		std::vector<Mushroom> _mushrooms;
	};
	
	typedef std::shared_ptr<GameField> FieldPtr;
}

#endif