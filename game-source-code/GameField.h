#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <memory>
#include <tuple>
#include <vector>
#include "Mushroom.h"
#include "Scorpion.h"
#include "Spider.h"

namespace GameEngine
{
/**
 * @class GameField
 * @author Darrion Singh and Sachin Govender.
 * @date 28/09/2018
 * @file GameField.h
 * @brief Object which creates the data containers that contain
 * all objects of the playing field that is neither the player
 * (Turret) or the enemy (Centipede).
 */
class GameField
{
   public:
    GameField()
    {
    }
    /**
     * @brief Accesses the Mushroom container.
     * @return Returns the address of the vector
     * containing all Mushrooms on the screen.
     */
    std::vector<Mushroom>& GetMushrooms();
    /**
     * @brief Accesses the Spider container.
     * @return Returns the address of the vector
     * containing all Spiders on the screen.
     */
    std::vector<Spider>& GetSpiders();
    /**
     * @brief Accesses the Scorpions container.
     * @return Returns the address of the vector
     * containing all Scorpions on the screen.
     */
    std::vector<Scorpion>& GetScorpions();
    /**
     * @brief Accresses the NewMushrooms container.
     * @return Returns the address of the vector
     * containing the coordinates of all new mushrooms
     * on the screen.
     */
    std::vector<std::tuple<float, float>>& GetNewMushrooms();

   private:
    std::vector<std::tuple<float, float>> new_mushrooms_;
    std::vector<Mushroom> mushrooms_;
    std::vector<Spider> spiders_;
    std::vector<Scorpion> scorpions_;
};
using FieldPtr = std::shared_ptr<GameField>;
}  // namespace GameEngine

#endif
