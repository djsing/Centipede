#ifndef TRAJECTORY_H
#define TRAJECTORY_H

namespace GameEngine
{
/**
 * @class Trajectory
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file Trajectory.h
 * @brief Scoped enumeration that defines whether a CentipedeSegment
 * object is moving toward the top or the bottom of the screen.
 */
enum class Trajectory
{
    UPWARD,
    DOWNWARD
};
}  // namespace GameEngine

#endif