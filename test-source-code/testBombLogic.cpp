#include "../game-source-code/BombLogic.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::Bomb;
using GameEngine::BombLogic;
using GameEngine::FieldPtr;
using GameEngine::GameField;
using GameEngine::LogicPtr;

#include <doctest.h>

TEST_CASE("Check that move function causes bomb to move to a random new position.")
{
    FieldPtr field = std::make_shared<GameField>();
    LogicPtr logic = std::make_unique<BombLogic>(field);
    logic->Spawn();
    CHECK(field->GetBombs().size() == 1);
    auto x = field->GetBombs().at(0).GetTopLeftXPosition();
    auto y = field->GetBombs().at(0).GetTopLeftYPosition();
    CHECK(y == field->GetBombs().at(0).GetTopLeftYPosition());
    CHECK(x == field->GetBombs().at(0).GetTopLeftXPosition());
    logic->Move(5);
    // move bombs
    logic->Move(1);
    CHECK_FALSE(field->GetBombs().at(0).GetTopLeftXPosition() == x);
    CHECK_FALSE(field->GetBombs().at(0).GetTopLeftYPosition() == y);
}