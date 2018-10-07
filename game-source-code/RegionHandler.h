#ifndef REGIONHANDLER_H
#define REGIONHANDLER_H

#include "Region.h"

namespace GameEngine
{
/**
 * @class RegionHandler
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file RegionHandler.h
 * @brief Takes in the center x and y position of an Entity object and determines which region and subregion
 * the Entity object is in.
 */
class RegionHandler
{
   public:
    /**
     * @brief RegionHandler Default Constructor
     */
    RegionHandler()
    {
    }
    /**
     * @brief RegionHandler Constructor. Saves the center x and y position.
     * @param xpos x position to be checked.
     * @param ypos y postion to be checked.
     */
    RegionHandler(float xpos, float ypos);
    /**
     * @brief Returns the major quadrant of the screen.
     * @return Returns the Region of the screen the coordinates
     * are located, as defined in Region.h
     */
    Region GetRegion();
    /**
     * @brief Returns a minor quadrant of the screen within the
     * major quadrant.
     * @return Returns the SubRegion of the screen the coordinates
     * are located, as defined in Region.h
     */
    Region GetSubRegion();

   private:
    float _xpos;
    float _ypos;
    Region _region;
    Region _subregion;
};
}  // namespace GameEngine

#endif