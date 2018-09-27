#ifndef MUSHROOMLOGIC_H
#define MUSHROOMLOGIC_H

#include <vector>
#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"
#include "Mushroom.h"

namespace GameEngine
{
class MushroomLogic : public EntityLogic
{
   public:
    MushroomLogic(FieldPtr field);
    void Spawn() override;
    void Move(float dt)
    {
    }
    void CollisionHandle() override;

   private:
    FieldPtr _field;
    int _deathChance;
    const int maxYLevels = SCREEN_HEIGHT / MUSHROOM_SPRITE_SIZE;
    const int maxXLevels = SCREEN_WIDTH / MUSHROOM_SPRITE_SIZE;
};
}  // namespace GameEngine

#endif
