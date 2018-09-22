#ifndef MUSHROOMLOGIC_H
#define MUSHROOMLOGIC_H

#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"
#include "Mushroom.h"
#include <vector>

namespace GameEngine
{
class MushroomLogic : public EntityLogic
{
  public:
    MushroomLogic(FieldPtr field, DataPtr data);
    void Spawn() override;
    void Move(float dt)
    {
    }
    void MoveProjectiles(float dt)
    {
    }
    void CollisionHandle() override; // yet to implement

  private:
    DataPtr _data;
    FieldPtr _field;
};
} // namespace GameEngine

#endif