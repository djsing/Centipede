#ifndef DIRECTION_H
#define DIRECTION_H

namespace GameEngine
{
/**
∗ @class Direction
∗ @author Darrion Singh and Sachin Govender
∗ @date 06/10/2018
∗ @file Direction.h
∗ @brief Scoped Enumeration to define states of movement.
*/
enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    HOVER
};
}  // namespace GameEngine

#endif