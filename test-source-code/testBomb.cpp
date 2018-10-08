#include "../game-source-code/Bomb.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::Bomb;

#include <doctest.h>

TEST_CASE("Bomb initialised with correct values.")
{
    auto bomb = Bomb{0, 0};
    CHECK(bomb.GetTopLeftXPosition() == 0);
    CHECK(bomb.GetTopLeftYPosition() == 0);
    CHECK(bomb.GetCenterXPosition() == BOMB_SPRITE_SIZE / 2);
    CHECK(bomb.GetCenterYPosition() == BOMB_SPRITE_SIZE / 2);
}