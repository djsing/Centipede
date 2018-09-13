#include <memory>
#include "../game-source-code/Bullet.h"
#include "../game-source-code/BulletLogic.h"
#include "../game-source-code/Game.h"
#include "../game-source-code/DEFINITIONS.h"
#include "../game-source-code/RegionHandler.h"

using GameEngine::GameData;
using GameEngine::DataPtr;
using GameEngine::Bullet;
using GameEngine::BulletLogic;
using GameEngine::Region;
using GameEngine::RegionHandler;

#include <doctest.h>

TEST_CASE("Bullet positioned at the upper boundary is set to Dead State.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	auto Bullet_ = Bullet{data,10,0};
	auto TestBullet = BulletLogic(Bullet_);
	TestBullet.Move(1);
	CHECK(Bullet_.IsDead() == true);
	auto bulletRegion = RegionHandler{Bullet_.GetCenterXPosition(), Bullet_.GetCenterYPosition()};
	CHECK((bulletRegion.GetRegion() == Region::TOP_LEFT));
}

TEST_CASE("Bullet is positioned below the left half of the upper boundary condition and moves as needed")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);

	auto Bullet_ = Bullet{data, 10, static_cast<float>(SCREEN_HEIGHT/2)};
	auto TestBullet = BulletLogic(Bullet_);
	TestBullet.Move(0.01);	//expecting bullet to move up by 20
	CHECK(Bullet_.GetTopLeftYPosition() == ((SCREEN_HEIGHT/2) - 20));
	auto bulletRegion = RegionHandler{Bullet_.GetCenterXPosition(), Bullet_.GetCenterYPosition()};
	CHECK(bulletRegion.GetRegion() == Region::TOP_LEFT);
}

TEST_CASE("Bullet is positioned below the right half of the upper boundary condition and moves as needed")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	// Placed in right plane in the middle
	auto Bullet_ = Bullet{data,static_cast<float>((SCREEN_WIDTH/2) + 10),static_cast<float>(SCREEN_HEIGHT/2)};
	auto TestBullet = BulletLogic(Bullet_);
	TestBullet.Move(0.01);//expecting bullet to move up by 20
	CHECK(Bullet_.GetTopLeftYPosition() == ((SCREEN_HEIGHT/2) - 20));
	auto bulletRegion = RegionHandler{Bullet_.GetCenterXPosition(), Bullet_.GetCenterYPosition()};
	CHECK(bulletRegion.GetRegion() == Region::TOP_RIGHT);
}

TEST_CASE("Bullet is positioned in the bottom left region and moves as needed")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	auto Bullet_ = Bullet{data, 10, static_cast<float>(SCREEN_HEIGHT-BULLET_HEIGHT)};
	auto TestBullet = BulletLogic(Bullet_);
	TestBullet.Move(0.001);	//expecting bullet to move up by 2
	CHECK(Bullet_.GetTopLeftYPosition() == ((SCREEN_HEIGHT-BULLET_HEIGHT) - 2));
	auto bulletRegion = RegionHandler{Bullet_.GetCenterXPosition(), Bullet_.GetCenterYPosition()};
	CHECK(bulletRegion.GetRegion() == Region::BOTTOM_LEFT);
}

TEST_CASE("Bullet is positioned in the bottom right region and moves as needed")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	auto Bullet_ = Bullet{data, static_cast<float>((SCREEN_WIDTH/2)+10), static_cast<float>(SCREEN_HEIGHT-BULLET_HEIGHT)};
	auto TestBullet = BulletLogic(Bullet_);
	TestBullet.Move(0.001);//expecting bullet to move up by 2
	CHECK(Bullet_.GetTopLeftYPosition() == ((SCREEN_HEIGHT-BULLET_HEIGHT)-2));
	auto bulletRegion = RegionHandler{Bullet_.GetCenterXPosition(), Bullet_.GetCenterYPosition()};
	CHECK((bulletRegion.GetRegion() == Region::BOTTOM_RIGHT));
}