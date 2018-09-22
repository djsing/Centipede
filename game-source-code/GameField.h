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
    std::vector<Mushroom> _mushrooms;
    std::vector<Spider> _spiders;
    std::vector<Scorpion> _scorpions;
};

typedef std::shared_ptr<GameField> FieldPtr;
} // namespace GameEngine

#endif