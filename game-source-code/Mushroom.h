#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Entity.h"
#include "Game.h"
#include "Region.h"

namespace GameEngine
{
/**
 * @class Mushroom
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file Mushroom.h
 * @brief Mushroom objects, inherits from Entity. Mushrooms have four lives,
 * decreasing whenever a Bullet object collides with it. Instantly destoryed
 * when inside the explosion radius of a Bomb object.
 */
class Mushroom : public Entity
{
   public:
    /**
     * @brief Mushroom Constructor. Sets Mushroom object's top left x and y position,
     * center x and y position, default direction of movement to Direction::HOVER,
     * sets the starting number of lives of each object to MUSHROOM_LIVES as defined
     * in DEFINITIONS.h. Sets default false value to the object's poisoned and bitten state.
     * @param xpos Desired x position to display the Mushroom object.
     * @param ypos Desired y position to display the Mushroom object.
     */
    Mushroom(float xpos, float ypos);
    /**
     * @brief Sets whether the Mushroom is being bitten by a Spider object. Mushrooms
     * are bitten by Spider objects upon collision, as defined in CollisionHandler.
     * @param isBitten True if the Mushroom object is being bitten, else false.
     */
    void SetBitten(bool isBitten);
    /**
     * @brief Sets whether the Mushroom has been poisoned by a Scorpion object. Mushrooms
     * are bitten by Scorpion objects upon collision, as defined in CollisionHandler.
     * @param isPoisoned True if the Mushroom object has been poisoned, else false.
     */
    void SetPoisoned(bool isPoisoned);
    /**
     * @brief Decreases number of Mushroom object's lives by 1.
     */
    void DecrementLives();
    /**
     * @brief Returns whether the Mushroom object is being bitten by a Spider object.
     * @return True if the Mushroom object is being bitten by a Spider object, else False.
     */
    bool IsBitten();
    /**
     * @brief Returns whether the Mushroom object has been poisoned by a Scorpion object.
     * @return True if the Mushroom object has been poisoned by a Scorpion object, else False.
     */
    bool IsPoisoned();
    /**
     * @brief Returns the number of lives the Mushroom object has remaining.
     * @return Returns integer number of lives remaining.
     */
    unsigned int GetLivesRemaining();

   private:
    bool is_bitten_;
    bool is_poisoned_;
    unsigned int lives_remaining_;
};
}  // namespace GameEngine

#endif
