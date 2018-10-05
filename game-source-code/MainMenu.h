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
     * @brief MainMenu Constructor
     */
    MainMenu(DataPtr data);
    /**
     * @brief Processes the keyboard input given to
     * game by the player.
     */
    void HandleInput() override;
    /**
     * @brief Reads the High Score before displaying.
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
