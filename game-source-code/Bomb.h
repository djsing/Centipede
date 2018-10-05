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
 * @brief Bomb objects. Bombs explode when shot by
 * a bullet and explode, destroying all enemies in
 * a radius.
 */
class Bomb : public Entity
{
   public:
    /**
     * @brief Bomb Constructor.
     * @param xpos Desired x position to store the bomb.
     * @param ypos Desired y position to store the bomb.
     */
    Bomb(float xpos, float ypos);
    /**
     * @brief Sets the top left x position of the object.
     * @param xpos The desired x position.
     */
    void SetTopLeftXPosition(float xpos);

    /**
     * @brief Sets the top left y position of the object.
     * @param xpos The desired y position.
     */
    void SetTopLeftYPosition(float ypos);
    /**
     * @brief Triggers the bomb, as well as destroying the bomb.
     */
    void Explode();
	/**
	 * @brief Returns whether the bomb has been triggered.
	 * @return True if the bomb has exploded, else False.
	 */
	bool IsTriggered();
   private:
	bool is_exploding_;
};
}  // namespace GameEngine

#endif