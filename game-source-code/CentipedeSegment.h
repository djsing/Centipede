#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Entity.h"
#include "Game.h"
#include "Region.h"
#include "Trajectory.h"

namespace GameEngine
{
/**
 * @class CentipedeSegment
 * @author Darrion Singh and Sachin Govender
 * @date 27/09/2018
 * @file CentipedeSegment.h
 * @brief CentipedeSegment objects.
 */
class CentipedeSegment : public Entity
{
   public:
    /**
     * @brief CentipedeSegment Constructor
     * @param firstSegment Sets whether the segment is a head segment or a body segment,
     * set to false by default.
     */
    CentipedeSegment(bool firstSegment = false);
    /**
     * @brief Sets CentipedeSegment object's top left x position.
     * @param xpos Desired x position.
     */
    void SetTopLeftXPosition(float xpos);
    /**
     * @brief Sets CentipedeSegment object's top left y position.
     * @param ypos Desired y position.
     */
    void SetTopLeftYPosition(float ypos);
    /**
     * @brief Sets whether the CentipedeSegment is a head or body segment.
     * @param isFirstSegment True if a head segment is required, false if
     * a body segment is required.
     */
    void SetFirstSegment(bool isFirstSegment);
    /**
     * @brief Sets whether the segment is moving to the bottom of the screen
     * or the top of the screen
     * @param trajectory Desired trajectory, either UPWARDS or DOWNWARDS,
     * given in Trajectory.h.
     */
    void SetTrajectory(Trajectory trajectory);
    /**
     * @brief Sets whether the CentipedeSegment is turning right or left at the
     * next impassable collision, i.e. at a wall or a mushroom.
     * @param isTurningLeft True to set the segment to turn right,
     * False to make the segment turn right.
     */
    void SetTurningLeft(bool isTurningLeft);
    /**
     * @brief Sets whether the CentipedeSegment is poisoned after collisons
     * with a poisoned mushroom.
     * @param isPoisoned True if the segment is poisoned, else false.
     */
    void SetPoisoned(bool isPoisoned);
    /**
     * @brief Returns whether the segment is moving towards the top or the
     * bottom of the screen.
     * @return Either UPWARD or DOWNWARD - See Trajectory.h
     */
    Trajectory GetTrajectory();
    /**
     * @brief Returns whether the segment is a head or body segment.
     * @return True if the segment is a head, else returns False.
     */
    bool IsFirstSegment();
    /**
     * @brief Returns whether the segment is turning left or right at the
     * next impassable collision.
     * @return True if turning left, False if turning right.
     */
    bool IsTurningLeft();
    /**
     * @brief Returns whether the segment is poisoned.
     * @return True if poisoned, else false.
     */
    bool IsPoisoned();

   private:
    // movement information
    bool turning_left_;
    Trajectory trajectory_;
    // segment characteristics
    bool first_segment_;
    bool is_poisoned_;
};
}  // namespace GameEngine

#endif
