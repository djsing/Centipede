#ifndef MUSHROOMRENDERING_H
#define MUSHROOMRENDERING_H

#include "EntityRendering.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
class MushroomRendering : public EntityRendering
{
  public:
    MushroomRendering(DataPtr data, FieldPtr field);
    void Draw() override;

  private:
    DataPtr _data;
    FieldPtr _field;
};
} // namespace GameEngine

#endif