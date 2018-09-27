#ifndef SPIDER_H
#define SPIDER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Game.h"

namespace GameEngine
{
class Spider : public Entity
{
   public:
    Spider();
    void SetTopLeftXPosition(float xpos);
    void SetTopLeftYPosition(float ypos);
    void SetAngle(int angle);
    int GetAngle();

   private:
    int angle_;
};
}  // namespace GameEngine

#endif
