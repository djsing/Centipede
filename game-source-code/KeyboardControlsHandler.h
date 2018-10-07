#ifndef KEYBOARDCONTROLSHANDLER_H
#define KEYBOARDCONTROLSHANDLER_H

#include "Direction.h"

namespace GameEngine
{
/**
 * @class KeyboardControlsHandler
 * @author Darrion Singh and Sachin Govender
 * @date 29/09/2018
 * @file KeyboardControlsHandler.h
 * @brief Stores the Direction of Turret object's movement
 * and current shooting state (whether the user is attempting
 * to shoot).
 */
class KeyboardControlsHandler
{
   public:
    /**
     * @brief KeyboardControlsHandler Constructor. By default,
     * sets shooting state to False, and Turret direction to
     * Direction::HOVER.
     */
    KeyboardControlsHandler();
    /**
     * @brief Returns whether or not the player has sent the
     * Turret a shoot command.
     * @return True if the player has sent a shoot command, else False.
     */
    bool IsShooting();
    /**
     * @brief Sets the Turret shoot command.
     * @param isShooting True if the player has sent the shoot
     * command, else False.
     */
    void SetShooting(bool isShooting);
    /**
     * @brief Returns the current Direction of movement of the Turret.
     * @return Current Turret direction, as defined in Direction.h
     */
    Direction GetDirection();
    /**
     * @brief Sets the current Direction of movement of the Turret.
     * @param direction Desired Turret direction, as defined in Direction.h
     */
    void SetDirection(Direction direction);

   private:
    Direction direction_;
    bool is_shooting_;
};
}  // namespace GameEngine

#endif
