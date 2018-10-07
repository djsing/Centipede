#ifndef SPIDER_H
#define SPIDER_H

#include "Entity.h"
#include "Game.h"

namespace GameEngine
{
/**
 * @class Spider
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file Spider.h
 * @brief Spider objects, inherits from Entity. Spiders bite mushrooms
 * upon collision, causing a chance of death, as defined in CollisionHandler.
 * Collision with a spider is fatal to the Turret object.
 */
class Spider : public Entity
{
   public:
    /**
     * @brief Spider Constructor. Sets top left x and y position, and center x
     * and y positions to default values.
     */
    Spider();
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
    /**
     * @brief Sets the angle of movement of the Spider.
     * @param angle Integer value in degrees (i.e. 0 <= angle <= 360).
     */
    void SetAngle(int angle);
    /**
     * @brief Returns the angle of movement of the Spider.
     * @return Integer value in degrees (i.e. 0 <= angle <= 360).
     */
    int GetAngle();

   private:
    int angle_;
};
}  // namespace GameEngine

#endif
