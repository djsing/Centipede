#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "Game.h"
#include "GameState.h"
#include "StateRenderer.h"
#include "StopWatch.h"

namespace GameEngine
{
/**
 * @class SplashScreen
 * @author Darrion Singh and Sachin Govender
 * @date 05/10/2018
 * @file SplashScreen.h
 * @brief The version of the game loop which
 * runs before the menu is shown.
 */
class SplashScreen : public GameState
{
   public:
    /**
     * @brief SplashScreen Constructor
     */
    SplashScreen(DataPtr data);
    /**
     * @brief Processes the keyboard input given to
     * game by the player.
     */
    void HandleInput() override;
    /**
     * @brief Ensures that the splashscreen is shown for three seconds.
     * @param dt Unused in this version of Update.
     */
    void Update(float dt) override;
    /**
     * @brief Draws the main menu screen.
     */
    void Draw() override;

   private:
    DataPtr data_;
    StopWatch _watch;
    StateRenderPtr renderer_;
};

}  // namespace GameEngine
#endif