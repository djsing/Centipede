#ifndef BOMBLOGIC_H
#define BOMBLOGIC_H

#include <tuple>
#include "DEFINITIONS.h"
#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
/**
 * @class BombLogic
 * @author Darrion Singh and Sachin Govender
 * @date 06/10/2018
 * @file BombLogic.h
 * @brief Responsible for all modifications to Bomb objects.
 * Derived from EntityLogic, polymorphic in nature.
 */
class BombLogic : public EntityLogic
{
   public:
    /**
     * @brief BombLogic Constructor. Seeds STL rand() function. Starts spawn timer.
     * @param field Shared pointer to the GameField container, which contains all
     * Bomb objects.
     */
    BombLogic(FieldPtr field);
    /**
     * @brief Spawns Bomb objects when the Bomb container has less Bomb objects
     * than BOMBS_SPAWNED in DEFINITIONS.h
     */
    void Spawn() override;
    /**
     * @brief Moves all alive Bomb objects to a random new positions after a period
     * of time defined by BOMB_MOVE_TIME in DEFINITIONS.h
     * @param dt Time step of game loop iteration, provided by Run() in Game.h
     */
    void Move(float dt) override;
    /**
     * @brief Deletes all dead Bomb objects after a period of time defined by
     * EXPLOSION_TIME in DEFINITIONS.h
     */
    void CollisionHandle() override;

   private:
    /**
     * @brief Randomly generates the spawning positions of Bomb objects. Defines
     * a box on the screen in which Bomb objects may be spawned. Disallows Bomb
     * objects from being spawned on the boundaries of regions and subregions
     * as defined in Region.h
     * @return std::pair<float, float> containing a random spawn position.
     */
    std::pair<float, float> GetRandomPositions();
    StopWatch timer_;
    FieldPtr field_;
    float time_elapsed_;
    const int max_y_levels_ = SCREEN_HEIGHT / MUSHROOM_SPRITE_SIZE;
    const int max_x_levels_ = SCREEN_WIDTH / MUSHROOM_SPRITE_SIZE;
};
}  // namespace GameEngine

#endif