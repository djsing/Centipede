#ifndef TURRET_H
#define TURRET_H

#include "Bullet.h"
#include "Direction.h"
#include "Entity.h"
#include "Game.h"
#include "Region.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

namespace GameEngine
{
class Turret : public Entity
{
  public:
    Turret(DataPtr data);

    // Address Accessor functions
    std::vector<Bullet>& GetBullets();

    // Mutator functions
    void SetTopLeftXPosition(float xpos);
    void SetTopLeftYPosition(float ypos);

    // Accessor functions specific to Turret
    float GetLastBulletYPosition();
    int GetLivesRemaining();

  private:
    // Data layer pointer
    DataPtr _data;
    // Container to store all bullets
    std::vector<Bullet> _bullets;
};

// Shared pointer to a Turret Object
typedef std::shared_ptr<Turret> TurretPtr;
} // namespace GameEngine

#endif