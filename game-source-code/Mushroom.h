#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Entity.h"
#include "Game.h"
#include "Region.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
class Mushroom : public Entity
{
  public:
    Mushroom(DataPtr data, float xpos, float ypos);

    // Mutator functions
    void SetPoisoned(bool isPoisoned);
    void DecrementLives();

    // Accessor Functions
    bool IsPoisoned();
    int GetLivesRemaining();

  private:
    DataPtr _data;
    bool _isPoisoned;
    int _livesRemaining;
};
} // namespace GameEngine

#endif