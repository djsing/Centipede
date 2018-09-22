#ifndef SCORPION_H
#define SCORPION_H

#include "Entity.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
class Scorpion : public Entity
{
  public:
    Scorpion(DataPtr data);
    void SetTopLeftXPosition(float xpos);
    void SetTopLeftYPosition(float ypos);

  private:
    DataPtr _data;
};
} // namespace GameEngine

#endif