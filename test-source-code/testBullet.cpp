#include "../game-source-code/Bullet.h"
#include "../game-source-code/BulletLogic.h"
#include "../game-source-code/Game.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::DataPtr;
using GameEngine::Bullet;

#include <doctest.h>

TEST_CASE("Bullet Initialised with correct values.")
{
	DataPtr data = std::make_shared<GameData>();
	data->resources.LoadTexture("Bullet sprite", BULLET_FILEPATH);
	auto bullet = Bullet{data,10,20};
	CHECK(bullet.GetCenterXPosition() == (10+CENTIPEDE_SPRITE_SIDE_SIZE/2));
	CHECK(bullet.GetCenterYPosition() == (20+CENTIPEDE_SPRITE_SIDE_SIZE/2));
}
