#ifndef BOMB_H
#define BOMB_H

#include "Entity.h"

namespace GameEngine
{
/**
 * @class Bomb
 * @author Darrion Singh and Sachin Govender
 * @date 03/10/2018
 * @file Bomb.h
 * @brief Bomb objects, inherits from Entity. Bombs explode when shot by
 * a bullet and destroy all non-Turret Entity objects in a radius. Does
 * not destroy other Bomb objects.
 */
class Bomb : public Entity
{
   public:
    /**
     * @brief Bomb Constructor. Sets Bomb object's top left x and y position,
     * center x and y position, and default direction of movement to Direction::HOVER.
     * @param xpos Desired x position to display the Bomb object.
     * @param ypos Desired y position to display the Bomb object.
     */
    Bomb(float xpos, float ypos);
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