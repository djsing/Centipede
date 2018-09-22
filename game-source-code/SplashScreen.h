#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "Game.h"
#include "GameState.h"
#include "StopWatch.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
class SplashScreen : public GameState
{
  public:
    SplashScreen(DataPtr data);

    void HandleInput() override;
    void Update(float dt) override;
    void Draw() override;

  private:
    DataPtr _data;
    StopWatch _watch;
    sf::Sprite _background;
};

} // namespace GameEngine
#endif