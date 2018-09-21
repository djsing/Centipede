#include "../game-source-code/Bullet.h"
#include "../game-source-code/DEFINITIONS.h"

using GameEngine::GameData;
using GameEngine::Bullet;

#include <doctest.h>

TEST_CASE("Bullet Initialised with correct values.")
{
	auto data = std::make_shared<GameData>();
	auto bullet = Bullet{data, 10, 20};
	CHECK(bullet.GetCenterXPosition() == (10 + BULLET_WIDTH/2));
	CHECK(bullet.GetCenterYPosition() == (20 + BULLET_HEIGHT/2));
}
