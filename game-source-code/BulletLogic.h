#ifndef BULLETLOGIC_H
#define BULLETLOGIC_H

#include "Bullet.h"
#include "EntityLogic.h"
#include "Game.h"
#include <memory>

namespace GameEngine
{
class BulletLogic : public EntityLogic
{
  public:
    BulletLogic(std::vector<Bullet>& bullets);
    void Spawn() override;
    // for Bullet class, move() refers to moving the bullet
    void Move(float dt) override;
    void MoveProjectiles(float dt) override;
    void CollisionHandle() override;

  private:
    std::vector<Bullet>& _bullets;
    float _speed;
};

typedef std::unique_ptr<BulletLogic> BulletLogicPtr;
} // namespace GameEngine

#endif