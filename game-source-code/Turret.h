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
 * @brief Turret object, inherits from Entity. Shoots Bullet objects. The player controls this object.
 * The Turret object loses a life upon collision with a Spider/CentipedeSegment as defined in
 * CollisionHandler.
 */
class Turret : public Entity
{
   public:
    /**
     * @brief Turret Constructor. Spawns Turret. Sets Turret to
     * default x and y position.
     */
    Turret();
    /**
     * @brief Accesses the Bullet object container.
     * @return Reference to std::vector<Bullet>, i.e. the Bullet object container.
     */
    std::vector<Bullet>& GetBullets();
    /**
     * @brief Sets the top left x position of the object. Sets the center x position
     * of the object based on the size of the object sprite, with reference to the
     * object's top left x position.
     * @param xpos The desired x position.
     */
    virtual void SetTopLeftXPosition(float xpos) override;
    /**
     * @brief Sets the top left y position of the object. Sets the center y position
     * of the object based on the size of the object sprite, with reference to the
     * object's top left y position.
     * @param ypos The desired y position.
     */
    virtual void SetTopLeftYPosition(float ypos) override;
    /**
     * @brief Returns the y position of the top left corner of the
     * most recently fired bullet.
     * @return Returns float containing the y position of the
     * most recently fired bullet.
     */
    float GetLastBulletYPosition();

   private:
    // Container to store all bullets
    std::vector<Bullet> bullets_;
};
using TurretPtr = std::shared_ptr<Turret>;
}  // namespace GameEngine

#endif
