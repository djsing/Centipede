#ifndef PAUSEGAME_H
#define PAUSEGAME_H

#include "Game.h"
#include "GameState.h"
#include "StateRenderer.h"

namespace GameEngine
{
/**
 * @class PauseGame
 * @author Darrion Singh and Sachin Govender
 * @date 05/10/2018
 * @file PauseGame.h
 * @brief The version of the game loop which
 * runs when the game is paused.
 */
class PauseGame : public GameState
{
   public:
    /**
     * @brief PauseGame Constructor. Shared pointer to Data layer. Creates
     * instance of the StateRenderer class for drawing purposes.
     */
    PauseGame(DataPtr data);
    /**
     * @brief Processes the keyboard input given to
     * game by the player.
     */
    void HandleInput() override;
    /**
     * @brief Unused in this version of the game loop. Open for future feature improvements.
     * @param dt Unused in this version of Update.
     */
    void Update(float dt) override;
    /**
     * @brief Draws the pause screen.
     */
    void Draw() override;

   private:
    DataPtr data_;
    StateRenderPtr renderer_;
};
}  // namespace GameEngine

#endif
