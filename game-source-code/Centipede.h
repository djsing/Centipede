#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <SFML/Graphics.hpp>
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
 * @brief Contains a set of CentipedeSegment objects.
 */
class Centipede
{
   public:
    /**
     * @brief Centipede Constructor.
     */
    Centipede();
    /**
     * @brief CentipedeSegment vector Accessor function.
     * @return Returns a reference to the vector of CentipedeSegment objects.
     */
    std::vector<CentipedeSegment>& GetCentipede();
    /**
     * @brief Returns the x position of the top left corner of
     * the last CentipedeSegment in the container.
     * @return Returns the x position of top left corner of the
     * last element in the container.
     */
    float GetLastSpriteXPosition();

   private:
    /**
     * @brief Data container to store CentipedeSegments.
     */
    std::vector<CentipedeSegment> centipede_segments_;
};
using CentPtr = std::shared_ptr<Centipede>;
}  // namespace GameEngine

#endif
