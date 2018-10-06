#ifndef TURRET_H
#define TURRET_H

#include <memory>
#include <vector>
#include "Bullet.h"
#include "Direction.h"
#include "Entity.h"
#include "Game.h"
#include "Region.h"

namespace GameEngine
{
/**
 * @class Turret
 * @author Darrion Singh and Sachin Govender
 * @date 29/09/2018
 * @file Turret.h
 * @brief Turret object.
 */
class Turret : public Entity
{
   public:
    /**
     * @brief Turret Constructor. Spawns Turret.
     */
    Turret();
    /**
     * @brief Accesses the Bullet object container.
     * @return Reference to Bullet object container.
     */
    std::vector<Bullet>& GetBullets();
    /**
     * @brief Sets x position of top left corner of turret.
     * @param xpos Desired x position.
     */
    void SetTopLeftXPosition(float xpos);
    /**
     * @brief Sets y position of top left corner of turret.
     * @param ypos Desired y position.
     */
    void SetTopLeftYPosition(float ypos);
    /**
     * @brief Returns the y position of the top left corner of the
     * most recently fired bullet.
     * @return Returns y position.
     */
    float GetLastBulletYPosition();

   private:
    // Container to store all bullets
    std::vector<Bullet> bullets_;
};
using TurretPtr = std::shared_ptr<Turret>;
}  // namespace GameEngine

#endif
