#ifndef BULLETRENDERING_H
#define BULLETRENDERING_H

#include "Bullet.h"
#include "EntityRendering.h"
#include "Game.h"
#include <memory>

namespace GameEngine
{
class BulletRendering : public EntityRendering
{
  public:
    BulletRendering(DataPtr data, std::vector<Bullet>& bullets);
    void Draw() override;

  private:
    DataPtr _data;
    std::vector<Bullet>& _bullets;
};

typedef std::unique_ptr<BulletRendering> BulletRenderPtr;
} // namespace GameEngine

#endif