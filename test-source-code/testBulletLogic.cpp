#include "../game-source-code/BulletLogic.h"
#include "../game-source-code/DEFINITIONS.h"
#include "../game-source-code/RegionHandler.h"

using GameEngine::GameData;
using GameEngine::Bullet;
using GameEngine::BulletLogic;
using GameEngine::Region;
using GameEngine::RegionHandler;

#include <doctest.h>

TEST_CASE("Bullet positioned at the upper boundary is set to Dead State.")
{
	auto data = std::make_shared<GameData>();
	auto Bullet_ = Bullet{data, 10, 0};
	std::vector<Bullet> Bullets_;
	Bullets_.push_back(Bullet_);
	auto TestBullet = BulletLogic(Bullets_);
	TestBullet.Move(1);
	CHECK(Bullets_.at(0).IsDead() == true);
	CHECK((Bullets_.at(0).GetRegion() == Region::TOP_LEFT));
}

TEST_CASE("Bullet is positioned below the left half of the upper boundary condition and moves as needed")
{
	auto data = std::make_shared<GameData>();
	auto Bullet_ = Bullet{data, 10, static_cast<float>(SCREEN_HEIGHT/2)};
	std::vector<Bullet> Bullets_;
	Bullets_.push_back(Bullet_);
	auto TestBullet = BulletLogic(Bullets_);
	TestBullet.Move(0.01);	//expecting bullet to move up by 20
	CHECK(Bullets_.at(0).GetTopLeftYPosition() == ((SCREEN_HEIGHT/2) - 20));
	CHECK(Bullets_.at(0).GetRegion() == Region::TOP_LEFT);
}

TEST_CASE("Bullet is positioned below the right half of the upper boundary condition and moves as needed")
{
	auto data = std::make_shared<GameData>();
	// Placed in right plane in the middle
	auto Bullet_ = Bullet{data,static_cast<float>((SCREEN_WIDTH/2) + 10),static_cast<float>(SCREEN_HEIGHT/2)};
	std::vector<Bullet> Bullets_;
	Bullets_.push_back(Bullet_);
	auto TestBullet = BulletLogic(Bullets_);
	TestBullet.Move(0.01);//expecting bullet to move up by 20
	CHECK(Bullets_.at(0).GetTopLeftYPosition() == ((SCREEN_HEIGHT/2) - 20));
	CHECK(Bullets_.at(0).GetRegion() == Region::TOP_RIGHT);
}

TEST_CASE("Bullet is positioned in the bottom left region and moves as needed")
{
	auto data = std::make_shared<GameData>();
	auto Bullet_ = Bullet{data, 10, static_cast<float>(SCREEN_HEIGHT-BULLET_HEIGHT)};
	std::vector<Bullet> Bullets_;
	Bullets_.push_back(Bullet_);
	auto TestBullet = BulletLogic(Bullets_);
	TestBullet.Move(0.001);	//expecting bullet to move up by 2
	CHECK(Bullets_.at(0).GetTopLeftYPosition() == ((SCREEN_HEIGHT-BULLET_HEIGHT) - 2));
	CHECK(Bullets_.at(0).GetRegion() == Region::BOTTOM_LEFT);
}

TEST_CASE("Bullet is positioned in the bottom right region and moves as needed")
{
	auto data = std::make_shared<GameData>();
	auto Bullet_ = Bullet{data, static_cast<float>((SCREEN_WIDTH/2)+10), static_cast<float>(SCREEN_HEIGHT-BULLET_HEIGHT)};
	std::vector<Bullet> Bullets_;
	Bullets_.push_back(Bullet_);
	auto TestBullet = BulletLogic(Bullets_);
	TestBullet.Move(0.001);//expecting bullet to move up by 2
	CHECK(Bullets_.at(0).GetTopLeftYPosition() == ((SCREEN_HEIGHT-BULLET_HEIGHT)-2));
	CHECK((Bullets_.at(0).GetRegion() == Region::BOTTOM_RIGHT));
}
