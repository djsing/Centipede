#ifndef BOMBLOGIC_H
#define BOMBLOGIC_H

#include <tuple>
#include "DEFINITIONS.h"
#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
class BombLogic : public EntityLogic
{
   public:
    BombLogic(FieldPtr field);
    void Spawn() override;
    void Move(float dt) override;
    void CollisionHandle() override;

   private:
    std::pair<float, float> GetRandomPositions();
	StopWatch timer_;
    FieldPtr field_;
    float time_elapsed_;
    const int max_y_levels_ = SCREEN_HEIGHT / MUSHROOM_SPRITE_SIZE;
    const int max_x_levels_ = SCREEN_WIDTH / MUSHROOM_SPRITE_SIZE;
};
}  // namespace GameEngine

#endif