#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include "Direction.h"
#include "Entity.h"
#include "Game.h"
#include "Region.h"
#include "Trajectory.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
class CentipedeSegment : public Entity
{
  public:
    CentipedeSegment(DataPtr data, bool firstSegment);

    // Mutator Functions
    void SetTopLeftXPosition(float xpos);
    void SetTopLeftYPosition(float ypos);
    void SetFirstSegment(bool isFirstSegment);

    // Mutators specific to CentipedeSegment
    void SetTrajectory(Trajectory trajectory);
    void SetTurningLeft(bool isTurningLeft);
    void SetPoisoned(bool isPoisoned);

    // Accessor Functions specifc to Centipede Segment
    Trajectory GetTrajectory();
    bool IsFirstSegment();
    bool IsTurningLeft();
    bool IsPoisoned();

  private:
    // pointer to GameData layer
    DataPtr _data;
    // movement information
    bool _turningLeft;
    Trajectory _trajectory;
    // segment characteristics
    bool _firstSegment;
    bool _isPoisoned;
};
} // namespace GameEngine

#endif