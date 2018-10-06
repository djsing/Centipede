#include <memory>
#include "../game-source-code/CentipedeLogic.h"
#include "../game-source-code/CollisionHandler.h"
#include "../game-source-code/DEFINITIONS.h"
#include "../game-source-code/MushroomLogic.h"
#include "../game-source-code/RegionHandler.h"
#include "../game-source-code/ScorpionLogic.h"
#include "../game-source-code/SpiderLogic.h"
#include "../game-source-code/TurretLogic.h"

using GameEngine::BulletLogic;
using GameEngine::Centipede;
using GameEngine::CentipedeLogic;
using GameEngine::CollisionHandler;
using GameEngine::Direction;
using GameEngine::GameData;
using GameEngine::GameField;
using GameEngine::Mushroom;
using GameEngine::MushroomLogic;
using GameEngine::RegionHandler;
using GameEngine::ScorpionLogic;
using GameEngine::Spider;
using GameEngine::SpiderLogic;
using GameEngine::Trajectory;
using GameEngine::Turret;
using GameEngine::TurretLogic;

#include <doctest.h>

TEST_CASE("Check that bullet-segment collisions are handled correctly.")
{
    auto data = std::make_shared<GameData>();
    auto centipede = std::make_shared<Centipede>();
    auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto bulletLogic = std::make_unique<BulletLogic>(turret->GetBullets());
    auto field = std::make_shared<GameField>();
    auto collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);
    data->keyboard.SetShooting(true);

    CHECK(turret->GetBullets().empty());
    CHECK(centipede->GetCentipede().empty());

    // spawn
    centipedeLogic->Spawn();
    turretLogic->Spawn();

    CHECK(turret->GetBullets().size() == 1);
    CHECK(centipede->GetCentipede().size() == 1);

    CHECK_FALSE(turret->GetBullets().at(0).IsDead());
    CHECK_FALSE(centipede->GetCentipede().at(0).IsDead());

    while(turret->GetBullets().at(0).GetTopLeftYPosition() > SCREEN_TOP)
	{
	    bulletLogic->Move(0.0001);
	}

    CHECK(centipede->GetCentipede().at(0).GetTopLeftYPosition() ==
          doctest::Approx(turret->GetBullets().at(0).GetTopLeftYPosition()).epsilon(0.01));

    // move the centipede into the bullet space, and check for collisions
    while(centipede->GetCentipede().at(0).GetTopLeftXPosition() < turret->GetBullets().at(0).GetTopLeftXPosition())
	{
	    centipedeLogic->Move(0.001);
	    // detect collisions
	    collisionhandler->CheckCollisions();
	}

    CHECK(turret->GetBullets().at(0).IsDead());
    CHECK(centipede->GetCentipede().at(0).IsDead());

    centipedeLogic->CollisionHandle();
    bulletLogic->CollisionHandle();

    CHECK(turret->GetBullets().empty());
    CHECK(centipede->GetCentipede().empty());
}

TEST_CASE("Check that segment-mushroom collisions are handled correctly when trajectory is downward.")
{
    auto data = std::make_shared<GameData>();
    auto centipede = std::make_shared<Centipede>();
    auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto field = std::make_shared<GameField>();
    auto mushLogic = std::make_unique<MushroomLogic>(field);
    auto collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

    CHECK(field->GetMushrooms().empty());
    CHECK(centipede->GetCentipede().empty());

    centipedeLogic->Spawn();
    CHECK(centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::DOWNWARD);

    // spawn a mushroom 2 centipede segment distances away
    auto mushroom = Mushroom(2 * CENTIPEDE_SPRITE_SIDE_SIZE, 0);
    field->GetMushrooms().push_back(mushroom);

    CHECK(field->GetMushrooms().size() == 1);
    CHECK(centipede->GetCentipede().size() == 1);

    while(centipede->GetCentipede().at(0).GetDirection() == Direction::RIGHT)
	{
	    centipedeLogic->Move(0.001);
	    // detect collisions
	    collisionhandler->CheckCollisions();
	}

    // check that when the collision is detected, the direction changes to DOWN
    CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::DOWN);
}

TEST_CASE("Check that segment-mushroom collisions are handled correctly when trajectory is upward.")
{
    auto data = std::make_shared<GameData>();
    auto centipede = std::make_shared<Centipede>();
    auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto field = std::make_shared<GameField>();
    auto mushLogic = std::make_unique<MushroomLogic>(field);
    auto collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

    CHECK(field->GetMushrooms().empty());
    CHECK(centipede->GetCentipede().empty());

    centipedeLogic->Spawn();

    // spawn a mushroom 2 centipede segment distances away
    auto mushroom = Mushroom(2 * CENTIPEDE_SPRITE_SIDE_SIZE, 2 * CENTIPEDE_SPRITE_SIDE_SIZE);
    field->GetMushrooms().push_back(mushroom);

    CHECK(field->GetMushrooms().size() == 1);
    CHECK(centipede->GetCentipede().size() == 1);

    // move segment until the segment reaches the bottom of the screen
    while(centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::DOWNWARD)
	{
	    centipedeLogic->Move(0.001);
	}

    CHECK(centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::UPWARD);

    while(centipede->GetCentipede().at(0).GetDirection() == Direction::RIGHT ||
          (centipede->GetCentipede().at(0).GetDirection() == Direction::LEFT))
	{
	    centipedeLogic->Move(0.001);
	    // detect collisions
	    collisionhandler->CheckCollisions();
	}

    // check that when the collision is detected, the direction changes to UP
    CHECK(centipede->GetCentipede().at(0).GetDirection() == Direction::UP);
}

TEST_CASE("Check that segment/poisoned-mushroom collisions are handled correctly.")
{
    auto data = std::make_shared<GameData>();
    auto centipede = std::make_shared<Centipede>();
    auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto field = std::make_shared<GameField>();
    auto mushLogic = std::make_unique<MushroomLogic>(field);
    auto collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);
    // check that newly created containers are empty
    CHECK(field->GetMushrooms().empty());
    CHECK(centipede->GetCentipede().empty());

    // spawn a centipede segment
    centipedeLogic->Spawn();
    CHECK(centipede->GetCentipede().at(0).GetTrajectory() == Trajectory::DOWNWARD);
    // a standalone segment is both the first and last segment of its section
    centipede->GetCentipede().at(0).SetLastSegment(true);
    auto alone = centipede->GetCentipede().at(0).IsFirstSegment() == centipede->GetCentipede().at(0).IsLastSegment();
    CHECK(alone);
    // spawn a mushroom 2 centipede segment distances away
    auto mushroom = Mushroom(2 * CENTIPEDE_SPRITE_SIDE_SIZE, 2 * CENTIPEDE_SPRITE_SIDE_SIZE);
    mushroom.SetPoisoned(true);
    field->GetMushrooms().push_back(mushroom);

    CHECK(field->GetMushrooms().size() == 1);
    CHECK(centipede->GetCentipede().size() == 1);

    // when mushroom is poisoned, no collision has been detected
    while(field->GetMushrooms().at(0).IsPoisoned())
	{
	    centipedeLogic->Move(0.001);
	    // detect collisions
	    collisionhandler->CheckCollisions();
	}

    // check that when the collision is detected, the centipede is poisoned
    CHECK(centipede->GetCentipede().at(0).IsPoisoned());
    CHECK_FALSE(field->GetMushrooms().at(0).IsPoisoned());
}

TEST_CASE("Check if turret loses a life when it collides with a segment.")
{
    auto data = std::make_shared<GameData>();
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto centipede = std::make_shared<Centipede>();
    auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
    auto field = std::make_shared<GameField>();
    auto collision = std::make_unique<CollisionHandler>(data, turret, centipede, field);
    // spawn centipede segment on turret
    centipedeLogic->Spawn();
    centipede->GetCentipede().at(0).SetTopLeftXPosition(turret->GetTopLeftXPosition());
    CHECK(centipede->GetCentipede().at(0).GetTopLeftXPosition() == turret->GetTopLeftXPosition());

    centipede->GetCentipede().at(0).SetTopLeftYPosition(turret->GetTopLeftYPosition());
    CHECK(centipede->GetCentipede().at(0).GetTopLeftYPosition() == turret->GetTopLeftYPosition());

    // check that objects are in same positions
    CHECK(turret->GetTopLeftXPosition() == centipede->GetCentipede().at(0).GetTopLeftXPosition());
    CHECK(turret->GetTopLeftYPosition() == centipede->GetCentipede().at(0).GetTopLeftYPosition());

    // before any collisions, check that turret has 3 lives
    CHECK(data->lives.LivesRemaining() == 3);
    // register a collision with a segment
    collision->CheckCollisions();
    // check that turret resets position to spawn position after losing a life
    CHECK(turret->GetTopLeftXPosition() == SCREEN_WIDTH / 2 - TURRET_SPRITE_SIDE_SIZE / 2);
    CHECK(turret->GetTopLeftYPosition() == doctest::Approx(SCREEN_HEIGHT - TURRET_SPRITE_SIDE_SIZE).epsilon(0.01));
    // check that turret loses a life after registering a collision
    CHECK(data->lives.LivesRemaining() == 2);
}

TEST_CASE("Check if turret loses a life when it collides with a spider.")
{
    auto data = std::make_shared<GameData>();
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto centipede = std::make_shared<Centipede>();
    auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
    auto field = std::make_shared<GameField>();
    auto spiderLogic = std::make_unique<SpiderLogic>(field);
    auto collision = std::make_unique<CollisionHandler>(data, turret, centipede, field);
    // spawn spider directly above turret
    auto spider = Spider();
    field->GetSpiders().push_back(spider);
    CHECK(field->GetSpiders().size() == 1);
    // move turret onto spider
    turret->SetTopLeftXPosition(field->GetSpiders().at(0).GetTopLeftXPosition());
    turret->SetTopLeftYPosition(field->GetSpiders().at(0).GetTopLeftYPosition());

    // check that objects are collided
    CHECK(turret->GetTopLeftXPosition() == field->GetSpiders().at(0).GetTopLeftXPosition());
    CHECK(turret->GetTopLeftYPosition() == field->GetSpiders().at(0).GetTopLeftYPosition());

    // before any collisions, check that turret has 3 lives
    CHECK(data->lives.LivesRemaining() == 3);
    // register a turret collision with a spider
    collision->CheckCollisions();

    // check that turret loses a life after registering a collision
    CHECK(data->lives.LivesRemaining() == 2);
}

TEST_CASE("Check that scorpion-mushroom collisions are handled correctly.")
{
    auto data = std::make_shared<GameData>();
    auto centipede = std::make_shared<Centipede>();
    auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto field = std::make_shared<GameField>();
    auto mushLogic = std::make_unique<MushroomLogic>(field);
    auto scorpionLogic = std::make_unique<ScorpionLogic>(field);
    auto collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

    CHECK(field->GetMushrooms().empty());
    CHECK(field->GetScorpions().empty());
    scorpionLogic->Spawn();
    CHECK(field->GetScorpions().size() == 1);

    // spawn a mushroom at position of scorpion
    auto mushroom =
        Mushroom(field->GetScorpions().at(0).GetTopLeftXPosition(), field->GetScorpions().at(0).GetTopLeftYPosition());
    field->GetMushrooms().push_back(mushroom);
    CHECK(field->GetMushrooms().size() == 1);
    // non essential checks only occur when the centipede is not empty
    centipedeLogic->Spawn();

    collisionhandler->CheckCollisions();

    CHECK(field->GetMushrooms().at(0).IsPoisoned());
}

TEST_CASE("Check that spider-mushroom collisions are handled correctly.")
{
    auto data = std::make_shared<GameData>();
    auto centipede = std::make_shared<Centipede>();
    auto centipedeLogic = std::make_unique<CentipedeLogic>(data, centipede);
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto field = std::make_shared<GameField>();
    auto mushLogic = std::make_unique<MushroomLogic>(field);
    auto spiderLogic = std::make_unique<SpiderLogic>(field);
    auto collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);

    CHECK(field->GetMushrooms().empty());
    CHECK(field->GetSpiders().empty());
    auto spider = Spider();
    field->GetSpiders().push_back(spider);
    CHECK(field->GetSpiders().size() == 1);

    // spawn a mushroom at position of scorpion
    auto mushroom =
        Mushroom(field->GetSpiders().at(0).GetTopLeftXPosition(), field->GetSpiders().at(0).GetTopLeftYPosition());
    field->GetMushrooms().push_back(mushroom);

    // non essential checks only occur when the centipede is not empty
    centipedeLogic->Spawn();

    collisionhandler->CheckCollisions();
    CHECK(field->GetMushrooms().size() == 1);
    CHECK(field->GetMushrooms().at(0).IsBitten());
}

TEST_CASE("Check that bullet-spider collisions are handled correctly.")
{
    auto data = std::make_shared<GameData>();
    auto centipede = std::make_shared<Centipede>();
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto bulletLogic = std::make_unique<BulletLogic>(turret->GetBullets());

    auto field = std::make_shared<GameField>();
    auto spiderLogic = std::make_unique<SpiderLogic>(field);
    auto collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);
    data->keyboard.SetShooting(true);

    // check that containers are empty upon creation
    CHECK(turret->GetBullets().empty());
    CHECK(field->GetSpiders().empty());

    // spawn spider
    auto spider = Spider();
    field->GetSpiders().push_back(spider);
    // spawn bullet
    turretLogic->Spawn();

    CHECK(turret->GetBullets().size() == 1);
    CHECK(field->GetSpiders().size() == 1);
    CHECK_FALSE(turret->GetBullets().at(0).IsDead());
    CHECK_FALSE(field->GetSpiders().at(0).IsDead());

    // move the bullet on the spider
    turret->GetBullets().at(0).SetTopLeftXPosition(field->GetSpiders().at(0).GetTopLeftXPosition());
    turret->GetBullets().at(0).SetTopLeftYPosition(field->GetSpiders().at(0).GetTopLeftYPosition());

    CHECK(field->GetSpiders().at(0).GetTopLeftXPosition() == turret->GetBullets().at(0).GetTopLeftXPosition());
    CHECK(field->GetSpiders().at(0).GetTopLeftYPosition() == turret->GetBullets().at(0).GetTopLeftYPosition());

    collisionhandler->CheckCollisions();

    CHECK(turret->GetBullets().at(0).IsDead());
    CHECK(field->GetSpiders().at(0).IsDead());

    spiderLogic->CollisionHandle();
    bulletLogic->CollisionHandle();

    CHECK(turret->GetBullets().empty());
    CHECK(field->GetSpiders().empty());
}

TEST_CASE("Check that bullet-mushroom collisions are handled correctly.")
{
    auto data = std::make_shared<GameData>();
    auto centipede = std::make_shared<Centipede>();
    auto turret = std::make_shared<Turret>();
    auto turretLogic = std::make_unique<TurretLogic>(data, turret);
    auto bulletLogic = std::make_unique<BulletLogic>(turret->GetBullets());

    auto field = std::make_shared<GameField>();
    auto mushLogic = std::make_unique<MushroomLogic>(field);
    auto collisionhandler = std::make_shared<CollisionHandler>(data, turret, centipede, field);
    data->keyboard.SetShooting(true);

    CHECK(turret->GetBullets().empty());
    CHECK(field->GetMushrooms().empty());

    // spawn entities in known positions
    auto mushroom = Mushroom(10, 10);
    field->GetMushrooms().push_back(mushroom);
    turretLogic->Spawn();
    CHECK(turret->GetBullets().size() == 1);
    CHECK(field->GetMushrooms().size() == 1);
    CHECK_FALSE(turret->GetBullets().at(0).IsDead());
    CHECK_FALSE(field->GetMushrooms().at(0).IsDead());

    // move the bullet onto the mushroom
    turret->GetBullets().at(0).SetTopLeftXPosition(field->GetMushrooms().at(0).GetTopLeftXPosition());
    turret->GetBullets().at(0).SetTopLeftYPosition(field->GetMushrooms().at(0).GetTopLeftYPosition());

    CHECK(field->GetMushrooms().at(0).GetTopLeftXPosition() == turret->GetBullets().at(0).GetTopLeftXPosition());
    CHECK(field->GetMushrooms().at(0).GetTopLeftYPosition() == turret->GetBullets().at(0).GetTopLeftYPosition());

    // lives drop from 4 to 3
    CHECK(field->GetMushrooms().at(0).GetLivesRemaining() == 4);
    collisionhandler->CheckCollisions();
    CHECK(turret->GetBullets().at(0).IsDead());
    CHECK_FALSE(field->GetMushrooms().at(0).IsDead());
    CHECK(field->GetMushrooms().at(0).GetLivesRemaining() == 3);
    bulletLogic->CollisionHandle();
    CHECK(turret->GetBullets().empty());

    // spawn a new bullet and collide with mushroom
    data->keyboard.SetShooting(true);
    turretLogic->Spawn();
    CHECK(turret->GetBullets().size() == 1);
    CHECK(field->GetMushrooms().size() == 1);
    CHECK_FALSE(turret->GetBullets().at(0).IsDead());
    CHECK_FALSE(field->GetMushrooms().at(0).IsDead());

    // move the bullet onto the mushroom
    turret->GetBullets().at(0).SetTopLeftXPosition(field->GetMushrooms().at(0).GetTopLeftXPosition());
    turret->GetBullets().at(0).SetTopLeftYPosition(field->GetMushrooms().at(0).GetTopLeftYPosition());
    CHECK(field->GetMushrooms().at(0).GetTopLeftXPosition() == turret->GetBullets().at(0).GetTopLeftXPosition());
    CHECK(field->GetMushrooms().at(0).GetTopLeftYPosition() == turret->GetBullets().at(0).GetTopLeftYPosition());
    // decrease mushroom lives to 1
    field->GetMushrooms().at(0).DecrementLives();
    field->GetMushrooms().at(0).DecrementLives();
    CHECK(field->GetMushrooms().at(0).GetLivesRemaining() == 1);
    // check if the mushroom is dead
    collisionhandler->CheckCollisions();
    CHECK(field->GetMushrooms().at(0).GetLivesRemaining() == 0);

    CHECK(field->GetMushrooms().at(0).IsDead());
    mushLogic->CollisionHandle();
    CHECK(field->GetMushrooms().empty());

    bulletLogic->CollisionHandle();
    CHECK(turret->GetBullets().empty());
}
