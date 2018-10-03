#include "GameField.h"

namespace GameEngine
{
std::vector<Mushroom>& GameField::GetMushrooms()
{
    return mushrooms_;
}

std::vector<Spider>& GameField::GetSpiders()
{
    return spiders_;
}

std::vector<Scorpion>& GameField::GetScorpions()
{
    return scorpions_;
}

std::vector<std::tuple<float, float>>& GameField::GetNewMushrooms()
{
    return new_mushrooms_;
}

}  // namespace GameEngine
