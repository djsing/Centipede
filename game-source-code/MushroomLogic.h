#ifndef MUSHROOMLOGIC_H
#define MUSHROOMLOGIC_H

#include <vector>
#include "DEFINITIONS.h"
#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
/**
 * @class MushroomLogic
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file MushroomLogic.h
 * @brief Controls the spawning and deletion of Mushroom objects in the game.
 */
class MushroomLogic : public EntityLogic
{
   public:
    /**
     * @brief MushroomLogic Constructor. Saves a shared pointer to the GameField container.
     * Seeds STL rand() function.
     */
    MushroomLogic(FieldPtr field);
    /**
     * @brief Spawns Mushroom object.
     */
    void Spawn() override;
    /**
     * @brief Unused for Mushroom objects. Open for future feature improvements.
     * @param dt Unused in this version of Move().
     */
    void Move(float dt) override;
    /**
     * @brief Evaluates whether Spider bites are fatal. Deletes all dead mushroom objects.
     */
    void CollisionHandle() override;

   private:
    FieldPtr field_;
    int death_chance_;
    const int max_y_levels_ = SCREEN_HEIGHT / MUSHROOM_SPRITE_SIZE;
    const int max_x_levels_ = SCREEN_WIDTH / MUSHROOM_SPRITE_SIZE;
};
}  // namespace GameEngine

#endif
