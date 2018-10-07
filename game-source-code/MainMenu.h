#ifndef MAINMENU_H
#define MAINMENU_H

#include "Game.h"
#include "GameState.h"
#include "StateRenderer.h"

namespace GameEngine
{
/**
 * @class MainMenu
 * @author Darrion Singh and Sachin Govender
 * @date 05/10/2018
 * @file MainMenu.h
 * @brief The version of the game loop which
 * runs before the game has begun, letting the user
 * decide when to begin the game.
 */
class MainMenu : public GameState
{
   public:
    /**
     * @brief MainMenu Constructor. Changes window object to have
     * dimensions of SCREEN_WIDTH and SCREEN_HEIGHT as defined in
     * DEFINITIONS.h. Sets the window top left position to one third of the
     * monitor width, such that the window is centered (the window width
     * is one third of the monitor width, as defined in DEFINITIONS.h).
     * Creates instance of StateRenderer class for drawing purposes.
     * @param data Shared pointer to Data layer, used to queue GamePlay
     * state when the user presses the spacebar to begin the game.
     */
    MainMenu(DataPtr data);
    /**
     * @brief Processes the keyboard input given to
     * game by the player.
     */
    void HandleInput() override;
    /**
     * @brief Reads the High Score.
     * @param dt Unused in this version of Update.
     */
    void Update(float dt) override;
    /**
     * @brief Draws the main menu screen.
     */
    void Draw() override;

   private:
    DataPtr data_;
    StateRenderPtr renderer_;
};

}  // namespace GameEngine
#endif
