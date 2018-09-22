#include "GameField.h"

namespace GameEngine
{
std::vector<Mushroom>& GameField::GetMushrooms()
{
    return _mushrooms;
}

std::vector<Spider>& GameField::GetSpiders()
{
    return _spiders;
}

std::vector<Scorpion>& GameField::GetScorpions()
{
    return _scorpions;
}
} // namespace GameEngine