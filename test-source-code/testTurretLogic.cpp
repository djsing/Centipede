#include "../game-source-code/CentipedeLogic.h"
#include "../game-source-code/CollisionHandler.h"
#include "../game-source-code/DEFINITIONS.h"
#include "../game-source-code/Game.h"
#include "../game-source-code/GameField.h"
#include "../game-source-code/GameState.h"
#include "../game-source-code/KeyboardControlsHandler.h"
#include "../game-source-code/TurretLogic.h"

using GameEngine::BulletLogic;
using GameEngine::Centipede;
using GameEngine::CentipedeLogic;
using GameEngine::CollisionHandler;
using GameEngine::Direction;
using GameEngine::GameData;
using GameEngine::GameField;
using GameEngine::GameState;
using GameEngine::KeyboardControlsHandler;
using GameEngine::Turret;
using GameEngine::TurretLogic;

#include <doctest.h>

TEST_CASE("Check if turret stays within the confines of the left/right wall, the bottom of the game screen, and the "
          "fraction of the screen height that is permitted.")
{
    auto data = std::make_shared<GameData>();
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    data->keyboard.SetDirection(Direction::LEFT);

    // move 10x500 units to the left, check if turret is stopped at a x position of 0
    for(unsigned int i = 0; i < 10; i++)
	{
	    turretLogic->Move(1);
	}

    CHECK(turret->GetTopLeftXPosition() == 0);

    data->keyboard.SetDirection(Direction::RIGHT);

    // move 10x500 units to the right, check if turret is stopped at a x position of SCREEN_WIDTH
    for(unsigned int i = 0; i < 10; i++)
	{
	    turretLogic->Move(1);
	}

    CHECK(turret->GetTopLeftXPosition() == SCREEN_WIDTH - TURRET_SPRITE_SIDE_SIZE);

    data->keyboard.SetDirection(Direction::UP);

    // move 10x500 units UP, check if turret is stopped at a y position of TURRET_SCREEN_FRACTION*SCREEN_HEIGHT
    for(unsigned int i = 0; i < 10; i++)
	{
	    turretLogic->Move(1);
	}

    // allow for a 1% error as a result of floating point accuracy
    CHECK(turret->GetTopLeftYPosition() == doctest::Approx(TURRET_SCREEN_FRACTION * SCREEN_HEIGHT).epsilon(0.01));

    data->keyboard.SetDirection(Direction::DOWN);

    // move 10x500 units DOWN, check if turret is stopped at a y position of SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE
    for(unsigned int i = 0; i < 10; i++)
	{
	    turretLogic->Move(1);
	}

    CHECK(turret->GetTopLeftYPosition() == doctest::Approx(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE).epsilon(0.01));
}

TEST_CASE("Check that bullets are automatically deleted when it hits the boundary.")
{
    auto data = std::make_shared<GameData>();
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto bulletLogic = std::make_unique<BulletLogic>(turret->GetBullets());

    // emulate the spacebar being pressed
    data->keyboard.SetShooting(true);
    // spawn a bullet
    turretLogic->Spawn();
    // check that bullet has spawned
    CHECK(turret->GetBullets().size() == 1);
    // check that turret is at correct spawn position
    CHECK(turret->GetTopLeftYPosition() == doctest::Approx(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE).epsilon(0.01));
    // check that bullet has spawned at the same y position as turret
    CHECK(turret->GetBullets().at(0).GetTopLeftYPosition() == turret->GetTopLeftYPosition());
    // move 40 units up
    bulletLogic->Move(0.02);
    // check that turret hasn't moved
    CHECK(turret->GetTopLeftYPosition() == doctest::Approx(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE).epsilon(0.01));
    // check that bullet has moved
    CHECK(turret->GetBullets().at(0).GetTopLeftYPosition() == turret->GetTopLeftYPosition() - BULLET_SPEED * 0.02);

    data->keyboard.SetShooting(true);
    // spawn another bullet
    turretLogic->Spawn();

    // move bullets to one bullet height away from the top of the screen
    while(turret->GetBullets().at(0).GetTopLeftYPosition() > SCREEN_TOP + BULLET_HEIGHT)
	{
	    bulletLogic->Move(0.001);
	}

    // check that both bullets are present
    CHECK(turret->GetBullets().size() == 2);

    // move until first bullet reaches the end of the screen
    while(turret->GetBullets().at(0).GetTopLeftYPosition() > SCREEN_TOP)
	{
	    bulletLogic->Move(0.0001);
	}

    // check that first bullet is at the top of the screen
    CHECK(turret->GetBullets().at(0).GetTopLeftYPosition() == doctest::Approx(SCREEN_TOP).epsilon(0.01));
    // move first bullet off screen
    bulletLogic->Move(0.001);
    // check that first bullet is marked as dead, but not the second
    CHECK(turret->GetBullets().at(0).IsDead());
    CHECK_FALSE(turret->GetBullets().at(1).IsDead());
    // handle collisions
    bulletLogic->CollisionHandle();
    // check if the first bullet is deleted, but the second is not
    CHECK(turret->GetBullets().size() == 1);
}
