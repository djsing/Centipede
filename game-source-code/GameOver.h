#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Game.h"
#include "GameState.h"
#include "StateRenderer.h"

namespace GameEngine
{
/**
 * @class GameOver
 * @author Darrion Singh and Sachin Govender
 * @date 05/10/2018
 * @file GameOver.h
 * @brief The version of the game loop which runs when the game is lost.
 */
class GameOver : public GameState
{
   public:
    /**
     * @brief GameOver Constructor. Creates an instance of the StateRenderer
     * class for drawing capability.
     * @param data Shared pointer to Data layer. Used to load/read textures.
     */
    GameOver(DataPtr data);
    /**
     * @brief Processes the keyboard input given to
     * game by the player.
     */
    void HandleInput() override;
    /**
     * @brief Updates the High Score.
     * @param dt Unused in this version of Update.
     */
    void Update(float dt) override;
    /**
     * @brief Draws the game-losing screen.
     */
    void Draw() override;

   private:
    StateRenderPtr renderer_;
    DataPtr data_;
};
}  // namespace GameEngine
#endif
