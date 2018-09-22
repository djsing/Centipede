#ifndef MAINMENU_H
#define MAINMENU_H

#include "Game.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
class MainMenu : public GameState
{
  public:
    MainMenu(DataPtr data);

    void HandleInput() override;
    void Update(float dt) override;
    void Draw() override;

  private:
    DataPtr _data;
    sf::Sprite _background;
    sf::Sprite _title;
    sf::Sprite _subtitle;
    sf::Sprite _instructions;
};

} // namespace GameEngine
#endif