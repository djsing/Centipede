#ifndef CENTIPEDELOGIC_H
#define CENTIPEDELOGIC_H

#include <memory>
#include "Centipede.h"
#include "EntityLogic.h"
#include "Game.h"

namespace GameEngine
{
class CentipedeLogic : public EntityLogic
{
   public:
    CentipedeLogic(DataPtr data, CentPtr centipede);
    // for centipede class, spawn() refers to spawning centipede segments
    void Spawn() override;
    // for centipede class, move() refers to centipede segments
    void Move(float dt) override;
    // deletes centipede segments
    void CollisionHandle() override;

   private:
    DataPtr data_;
    CentPtr centipede_;
    float speed_;
    float move_distance_;
    // track initially spawned centipede segments
    unsigned int number_of_centipede_segments_;
    void MoveDown(CentipedeSegment& index);
    void MoveUp(CentipedeSegment& index);
    void MoveLeft(Trajectory trajectory, CentipedeSegment& index);
    void MoveRight(Trajectory trajectory, CentipedeSegment& index);
};
}  // namespace GameEngine

#endif
