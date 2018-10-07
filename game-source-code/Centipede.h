#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <memory>
#include "CentipedeSegment.h"
#include "Game.h"

namespace GameEngine
{
/**
 * @class Centipede
 * @author Darrion Singh and Sachin Govender
 * @date 27/09/2018
 * @file Centipede.h
 * @brief Contains a vector of CentipedeSegment objects.
 */
class Centipede
{
   public:
    /**
     * @brief CentipedeSegment vector Accessor function.
     * @return Returns a reference to std::vector<CentipedeSegment>,
     * which contains all CentipedeSegment objects in the game.
     */
    std::vector<CentipedeSegment>& GetCentipede();
    /**
     * @brief Returns the x position of the top left corner of
     * the last CentipedeSegment in the container. Used in CentipedeSegment
     * spawning.
     * @return Returns float containing Entity::GetTopLeftXPosition()
     * of the last element in std::vector<CentipedeSegment>.
     */
    float GetLastSpriteXPosition();

   private:
    std::vector<CentipedeSegment> centipede_segments_;
};
using CentPtr = std::shared_ptr<Centipede>;
}  // namespace GameEngine

#endif
