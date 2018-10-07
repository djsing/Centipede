#ifndef BULLETLOGIC_H
#define BULLETLOGIC_H

#include <memory>
#include "Bullet.h"
#include "EntityLogic.h"
#include "Game.h"

namespace GameEngine
{
/**
 * @class BulletLogic
 * @author Darrion Singh and Sachin Govender
 * @date 27/09/2018
 * @file BulletLogic.h
 * @brief Controls the movement/deletion of Bullets currently in the game.
 */
class BulletLogic : public EntityLogic
{
   public:
    /**
     * @brief BulletLogic Constructor. Saves address of the bullet vector, sets speed to default
     * values.
     * @param bullets Address of vector containing all existing Bullet objects in the game.
     */
    BulletLogic(std::vector<Bullet>& bullets);
    /**
     * @brief Empty function for future features.
     */
    void Spawn() override;
    /**
     * @brief Moves all bullets currently in the game.
     * @param dt Timestep given from the Game loop.
     */
    void Move(float dt) override;
    /**
     * @brief Deletes all dead bullets from the game.
     */
    void CollisionHandle() override;

   private:
    std::vector<Bullet>& bullets_;
    float speed_;
};
}  // namespace GameEngine

#endif
