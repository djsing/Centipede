#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"
#include "Game.h"
#include "Region.h"

namespace GameEngine
{
/**
 * @class Bullet
 * @author Darrion Singh and Sachin Govender
 * @date 27/09/2018
 * @file Bullet.h
 * @brief Bullet object that is shot from the Turret object.
 * Inherits from Entity. Affects other Entity objects in different
 * manners upon contact, as defined in CollisionHandler.
 */
class Bullet : public Entity
{
   public:
    /**
     * @brief Bullet class constructor. Sets Bomb object's
     * top left x and y position, center x and y position,
     * and default direction of movement to Direction::UP.
     * @param xpos Desired x position to display the Bullet object.
     * @param ypos Desired y position to display the Bullet object.
     */
    Bullet(float xpos, float ypos);
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
};
}  // namespace GameEngine

#endif
