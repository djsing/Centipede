#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include "CentipedeSegment.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace GameEngine
{
class Centipede
{
  public:
    Centipede(DataPtr data);

    // Address Accessor Functions
    std::vector<CentipedeSegment>& GetCentipede();

    // Accessor Fucntions
    float GetLastSpriteXPosition();

  private:
    // pointer to GameData layer
    DataPtr _data;
    // data container to store CentipedeSegments
    std::vector<CentipedeSegment> _centipedeSegments;
};

typedef std::shared_ptr<Centipede> CentPtr;
} // namespace GameEngine

#endif