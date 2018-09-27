#ifndef BULLETLOGIC_H
#define BULLETLOGIC_H

#include <memory>
#include "Bullet.h"
#include "EntityLogic.h"
#include "Game.h"

namespace GameEngine
{
class BulletLogic : public EntityLogic
{
   public:
    BulletLogic(std::vector<Bullet>& bullets);
    void Spawn() override;
    void Move(float dt) override;
    void CollisionHandle() override;

   private:
    std::vector<Bullet>& bullets_;
    float speed_;
};
}  // namespace GameEngine

#endif
