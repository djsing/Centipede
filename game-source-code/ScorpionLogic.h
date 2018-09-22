#ifndef SCORPIONLOGIC_H
#define SCORPIONLOGIC_H

#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
class ScorpionLogic : public EntityLogic
{
  public:
    ScorpionLogic(FieldPtr field, DataPtr data);
    void Spawn() override;
    void Move(float dt) override;
    void MoveProjectiles(float dt)
    {
    }
    void CollisionHandle() override;

  private:
    DataPtr _data;
    FieldPtr _field;
    float _totalTimePerMovement;
    float _angle;
    float _speed;
};
} // namespace GameEngine

#endif