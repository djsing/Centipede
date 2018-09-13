#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Mushroom.h"
#include "Spider.h"
#include "Scorpion.h"
#include <vector>
#include <memory>

namespace GameEngine
{
	class GameField
	{
	public:
		GameField(){}
		std::vector<Mushroom> &GetMushrooms();
		std::vector<Spider> &GetSpiders();
		std::vector<Scorpion> &GetScorpions();

	private:
		std::vector<Mushroom> _mushrooms;
		std::vector<Spider> _spiders;
		std::vector<Scorpion> _scorpions;
	};
	
	typedef std::shared_ptr<GameField> FieldPtr;
}

#endif