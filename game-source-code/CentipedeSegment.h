#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

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
 * @brief CentipedeSegment object that is stored in the Centipede
 * container. Inherits from Entity. Affects other Entity objects
 * in different manners upon contact, as defined in CollisionHandler.
 */
class CentipedeSegment : public Entity
{
   public:
    /**
     * @brief CentipedeSegment Constructor. Sets object's top left x and y position,
     * center x and y position, as well as default movement/other characteristics.
     * @param firstSegment Sets whether the CentipedeSegment is a head segment
     * or a body segment. True if the CentipedeSegment is a head segment, else false.
     * Set to false by default.
     */
    CentipedeSegment(bool firstSegment = false);
    /**
     * @brief Sets the top left x position of the object. Sets the center x position
     * of the object based on the size of the object sprite, with reference to the
     * object's top left x position.
     * @param xpos The desired x position.
     */
    virtual void SetTopLeftXPosition(float xpos) override;
    /**
     * @brief Sets the top left y position of the object. Sets the center y position
     * of the object based on the size of the object sprite, with reference to the
     * object's top left y position.
     * @param ypos The desired y position.
     */
    virtual void SetTopLeftYPosition(float ypos) override;
    /**
     * @brief Sets whether the CentipedeSegment is a head segment.
     * @param isFirstSegment True if a head segment is required, false if
     * a body segment is required.
     */
    void SetFirstSegment(bool isFirstSegment);
    /**
     * @brief Sets whether the CentipedeSegment is the last segment of a
     * centipede section.
     * @param IsLastSegment True if the segment is the end of a section of
     * the Centipede container.
     */
    void SetLastSegment(bool IsLastSegment);
    /**
     * @brief Sets whether the segment is moving to the bottom of the screen
     * or the top of the screen.
     * @param trajectory Desired trajectory as defined in Trajectory.h.
     */
    void SetTrajectory(Trajectory trajectory);
    /**
     * @brief Sets whether the CentipedeSegment is turning right or left at the
     * next edge of the screen or Mushroom object.
     * @param isTurningLeft True to set the segment to turn right,
     * False to make the segment turn right.
     */
    void SetTurningLeft(bool isTurningLeft);
    /**
     * @brief Sets whether the CentipedeSegment is poisoned after a collison
     * with a poisoned mushroom.
     * @param isPoisoned True if the segment is poisoned, else false.
     */
    void SetPoisoned(bool isPoisoned);
    /**
     * @brief Returns whether the CentipedeSegment object is moving towards
     * the top or the bottom of the screen.
     * @return Current trajectory as defined in Trajectory.h.
     */
    Trajectory GetTrajectory() const;
    /**
     * @brief Returns whether the CentipedeSegment is a head or body segment.
     * @return True if the segment is a head, else returns False.
     */
    bool IsFirstSegment() const;
    /**
     * @brief Returns whether the CentipedeSegment is the last segment of a
     * centipede section.
     * @return True if the segment is the end of a section of the Centipede
     * container.
     */
    bool IsLastSegment() const;
    /**
     * @brief Returns whether the CentipedeSegment is turning right or left at the
     * next edge of the screen or Mushroom object.
     * @return True if turning left, False if turning right.
     */
    bool IsTurningLeft() const;
    /**
     * @brief Returns whether the CentipedeSegment object is poisoned.
     * @return True if poisoned, else false.
     */
    bool IsPoisoned() const;

   private:
    // movement information
    bool turning_left_;
    Trajectory trajectory_;
    // segment characteristics
    bool first_segment_;
    bool last_segment_;
    bool is_poisoned_;
};
}  // namespace GameEngine

#endif
