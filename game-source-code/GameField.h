#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Mushroom.h"
#include "Scorpion.h"
#include "Spider.h"
#include <memory>
#include <vector>

namespace GameEngine
{
	class GameField
	{
	public:
		GameField()
		{
		}
		std::vector<Mushroom>& GetMushrooms();
		std::vector<Spider>& GetSpiders();
		std::vector<Scorpion>& GetScorpions();

	private:
		std::vector<Mushroom> mushrooms_;
		std::vector<Spider> spiders_;
		std::vector<Scorpion> scorpions_;
	};

	using FieldPtr = std::shared_ptr<GameField>;
} // namespace GameEngine

#endif
