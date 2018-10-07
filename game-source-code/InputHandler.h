#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Window/Event.hpp>
#include <memory>
#include "Direction.h"
#include "Game.h"

namespace GameEngine
{
/**
 * @class InputHandler
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file InputHandler.h
 * @brief Keyboard Interface between player and the game.
 */
class InputHandler
{
   public:
    /**
     * @brief InputHandler Constructor. By default, sets all key press flags to false,
     * desired direction to Direction::HOVER, and shooting flag to false (user is not
     * attempting to shoot bullets.
     */
    InputHandler(DataPtr data);
    /**
     * @brief Processes Keyboard input events and saves the final result to
     * KeyboardControlsHandler, in the Data layer.
     * @param event Any event triggered by the user pressing/releasing a button
     * on the keyboard.
     */
    void SetControls(sf::Event event);

   private:
    DataPtr data_;
    bool is_shooting_;
    Direction direction_;
    bool is_left_;
    bool is_right_;
    bool is_up_;
    bool is_down_;
};

using InputHandlerPtr = std::shared_ptr<InputHandler>;
}  // namespace GameEngine

#endif
