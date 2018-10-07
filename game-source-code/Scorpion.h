#ifndef SCORPION_H
#define SCORPION_H

#include "Entity.h"
#include "Game.h"

namespace GameEngine
{
/**
 * @class Scorpion
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file Scorpion.h
 * @brief Scorpion objects, inherits from Entity. Scorpions poison mushrooms
 * upon collision, as defined in CollisionHandler.
 */
class Scorpion : public Entity
{
   public:
    /**
     * @brief Scorpion Constructor. Sets top left x and y position, and center x
     * and y positions to default values.
     */
    Scorpion();
    /**
     * @brief Sets the top left x position of the object. Sets the center x position
     * of the object based on the size of the object sprite, with reference to the
     * object's top left x position. Wraps position around screen in the x direction.
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
