#ifndef GAMEWON_H
#define GAMEWON_H

#include "Game.h"
#include "GameState.h"
#include "StateRenderer.h"

namespace GameEngine
{
/**
 * @class GameWon
 * @author Darrion Singh and Sachin Govender
 * @date 05/10/2018
 * @file GameWon.h
 * @brief The version of the game loop which runs when the game is won.
 */
class GameWon : public GameState
{
   public:
    /**
     * @brief GameWon Constructor
     */
    GameWon(DataPtr data);
    /**
     * @brief Processes the keyboard input given to
     * game by the player.
     */
    void HandleInput() override;
    /**
     * @brief Updates the High Score before displaying.
     * @param dt Unused in this version of Update.
     */
    void Update(float dt) override;
    /**
     * @brief Draws the game-winning screen.
     */
    void Draw() override;

   private:
    StateRenderPtr renderer_;
    DataPtr data_;
};
}  // namespace GameEngine

#endif
