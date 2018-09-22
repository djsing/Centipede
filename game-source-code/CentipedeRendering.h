#ifndef CENTIPEDERENDERING_H
#define CENTIPEDERENDERING_H

#include "Centipede.h"
#include "EntityRendering.h"
#include "Game.h"
#include <memory>

namespace GameEngine
{
class CentipedeRendering : public EntityRendering
{
  public:
    CentipedeRendering(DataPtr data, CentPtr centipede);
    void Draw() override;

  private:
    DataPtr _data;
    CentPtr _centipede;
};
} // namespace GameEngine

#endif