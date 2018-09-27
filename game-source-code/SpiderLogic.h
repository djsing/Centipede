#ifndef SPIDERLOGIC_H
#define SPIDERLOGIC_H

#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
class SpiderLogic : public EntityLogic
{
   public:
    SpiderLogic(FieldPtr field);
    void Spawn() override;
    void Move(float dt) override;
    void CollisionHandle() override;

   private:
    void ChangeDirection(Spider& index);
    FieldPtr _field;
    StopWatch spawn_timer_;
    StopWatch move_timer_;
    float _speed;
};
}  // namespace GameEngine

#endif
