#ifndef PAUSEGAME_H
#define PAUSEGAME_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameState.h"

namespace GameEngine
{
class PauseGame : public GameState
{
   public:
    PauseGame(DataPtr data);

    void HandleInput() override;
    void Update(float dt) override;
    void Draw() override;

   private:
    DataPtr data_;
    sf::Sprite game_paused_;
    sf::Sprite press_space_to_resume_;
    sf::Sprite background_;
    sf::Texture resume_background_;
};
}  // namespace GameEngine

#endif
