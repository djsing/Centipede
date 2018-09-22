#ifndef TURRETLOGIC_H
#define TURRETLOGIC_H

#include "BulletLogic.h"
#include "EntityLogic.h"
#include "Game.h"
#include "Turret.h"
#include <memory>

namespace GameEngine
{
class TurretLogic : public EntityLogic
{
  public:
    TurretLogic(DataPtr data, TurretPtr turret);
    // for turret class, spawn() refers to spawning bullets
    void Spawn() override;
    // for turret class, move() refers to turret movement
    void Move(float dt) override;
    // for turret class, MoveProjectiles() refers to moving bullets
    void MoveProjectiles(float dt) override;
    // deletes dead bullets, ends game if turret collides with deadly entity
    void CollisionHandle() override;

  private:
    DataPtr _data;
    TurretPtr _turret;
    BulletLogicPtr _bulletLogic;
    float _speed;
};
} // namespace GameEngine

#endif