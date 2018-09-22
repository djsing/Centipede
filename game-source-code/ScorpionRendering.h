#ifndef SCORPIONRENDERING_H
#define SCORPIONRENDERING_H

#include "EntityRendering.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
class ScorpionRendering : public EntityRendering
{
  public:
    ScorpionRendering(DataPtr data, FieldPtr field);
    void Draw() override;

  private:
    DataPtr _data;
    FieldPtr _field;
};
} // namespace GameEngine

#endif