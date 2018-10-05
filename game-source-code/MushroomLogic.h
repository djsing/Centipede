#ifndef MUSHROOMLOGIC_H
#define MUSHROOMLOGIC_H

#include <vector>
#include "DEFINITIONS.h"
#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"

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
    FieldPtr field_;
    int death_chance_;
    const int max_y_levels_ = SCREEN_HEIGHT / MUSHROOM_SPRITE_SIZE;
    const int max_x_levels_ = SCREEN_WIDTH / MUSHROOM_SPRITE_SIZE;
};
}  // namespace GameEngine

#endif
