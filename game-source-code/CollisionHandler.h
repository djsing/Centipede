#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Centipede.h"
#include "Game.h"
#include "GameField.h"
#include "Turret.h"

namespace GameEngine
{
class CollisionHandler
{
  public:
    CollisionHandler(DataPtr data, TurretPtr turret, CentPtr centipede, FieldPtr field);
    void CheckCollisions();

  private:
    DataPtr _data;
    TurretPtr _turret;
    CentPtr _centipede;
    FieldPtr _field;
    void CheckBulletSegmentCollisions();
    void CheckSegmentMushroomCollisions();
    void CheckTurretSegmentCollisions();
    void CheckTurretSpiderCollisions();
    void CheckMushroomScorpionCollisions();
    void CheckMushroomSpiderCollisions();
    void CheckBulletSpiderCollisions();
    void CheckBulletMushroomCollisions();
    float CheckDistanceBetweenEntities(Entity& entity1, Entity& entity2);
};

typedef std::shared_ptr<CollisionHandler> CollisionHandlerPtr;
} // namespace GameEngine

#endif