#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <memory>

namespace GameEngine
{
class GameState
{
  public:
    // All game states should have its own declaration of the following functions
    virtual void HandleInput() = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw() = 0;
};

typedef std::unique_ptr<GameState> StatePtr;
} // namespace GameEngine

#endif