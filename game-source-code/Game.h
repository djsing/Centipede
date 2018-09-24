#ifndef GAME_H
#define GAME_H

#include "KeyboardControlsHandler.h"
#include "LivesHandler.h"
#include "ResourceManager.h"
#include "StateHandler.h"
#include "StopWatch.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

namespace GameEngine
{
struct GameData
{
    StateHandler statehandler;
    sf::RenderWindow window;
    ResourceManager resources;
    KeyboardControlsHandler keyboard;
    LivesHandler lives;
};

typedef std::shared_ptr<GameData> DataPtr;

class Game
{
  public:
    Game(int width, int height, std::string windowTitle);

  private:
    const float _dt = 1.0f / 120.0f;
    StopWatch _watch;
    DataPtr _data = std::make_shared<GameData>();
    // Starts game loop
    void Run();
};
} // namespace GameEngine

#endif