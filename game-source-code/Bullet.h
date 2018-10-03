#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
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
 * @brief Bullet object that is shot from the Turret.
 */
class Bullet : public Entity
{
   public:
    /**
     * @brief Bullet class constructor
     * @brief xpos bullet x position
     * @param ypos bullet y position
     */
    Bullet(float xpos, float ypos);
    /**
     * @brief Sets bullet x position of top left corner.
     * @param xpos Desired bullet x position
     */
    void SetTopLeftXPosition(float xpos);
    /**
     * @brief Sets bullet y position of top left corner.
     * @param ypos Desired bullet y position
     */
    void SetTopLeftYPosition(float ypos);
};
}  // namespace GameEngine

#endif
