#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <memory>

namespace GameEngine
{
/**
 * @class GameState
 * @author Darrion Singh and Sachin Govender
 * @date 06/10/2018
 * @file GameState.h
 * @brief Interface class for all Game Engine layer related operations.
 * Polymorphic in nature. Describes the state that the game is in.
 * Game loop given in Game::Run() calls the following functions from
 * the active GameState, i.e. All GameState derived classes form
 * different versions of the game loop.
 */
class GameState
{
   public:
    /**
     * @brief Processes the keyboard input given to
     * game by the player.
     */
    virtual void HandleInput() = 0;
    /**
     * @brief Updates all relevant Entity objects and processes
     * in a particular state of the game.
     * @param dt Time step of game loop iteration, provided by Run() in Game.h
     */
    virtual void Update(float dt) = 0;
    /**
     * @brief Draws all sprites pertaining to that particular state of the game.
     */
    virtual void Draw() = 0;
};

using StatePtr = std::unique_ptr<GameState>;
}  // namespace GameEngine

#endif
