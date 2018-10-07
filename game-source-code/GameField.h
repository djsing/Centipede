#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <memory>
#include <tuple>
#include <vector>
#include "Bomb.h"
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
    /**
     * @brief Accesses the Mushroom container.
     * @return Returns a reference to std::vector<Mushroom>, i.e. the address
     * of the vector containing all Mushroom objects on the screen.
     */
    std::vector<Mushroom>& GetMushrooms();
    /**
     * @brief Accesses the Spider container.
     * @return Returns a reference to std::vector<Spider>, i.e. the address
     * of the vector containing all Spider objects on the screen.
     */
    std::vector<Spider>& GetSpiders();
    /**
     * @brief Accesses the Scorpions container.
     * @return Returns a reference to std::vector<Scorpion>, i.e. the address
     * of the vector containing all Scorpion objects on the screen.
     */
    std::vector<Scorpion>& GetScorpions();
    /**
     * @brief Accresses the NewMushrooms container.
     * @return Returns a reference to std::vector<std::pair<float, float>>,
     * i.e. the address of the vector containing the coordinates of all new
     * mushrooms to be spawned on the screen in the next iteration of the
     * game loop.
     */
    std::vector<std::pair<float, float>>& GetNewMushrooms();
    /**
     * @brief Accesses the Bombs container.
     * @return Returns a reference to std::vector<Bomb>, i.e the address
     * of the vector containing all Bomb objects on the screen.
     */
    std::vector<Bomb>& GetBombs();

   private:
    std::vector<Bomb> bombs_;
    std::vector<std::pair<float, float>> new_mushrooms_;
    std::vector<Mushroom> mushrooms_;
    std::vector<Spider> spiders_;
    std::vector<Scorpion> scorpions_;
};
using FieldPtr = std::shared_ptr<GameField>;
}  // namespace GameEngine

#endif
