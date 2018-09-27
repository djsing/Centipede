#ifndef TURRETRENDERING_H
#define TURRETRENDERING_H

#include "BulletRendering.h"
#include "EntityRendering.h"
#include "Game.h"
#include "Turret.h"
#include <memory>
#include <vector>

namespace GameEngine
{
class TurretRendering : public EntityRendering
{
  public:
    TurretRendering(DataPtr data, TurretPtr turret);
    void Draw() override;

  private:
    DataPtr _data;
    TurretPtr _turret;
    std::vector<sf::Sprite> _lives;
};
} // namespace GameEngine

#endif