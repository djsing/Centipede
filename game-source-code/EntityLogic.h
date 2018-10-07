#ifndef ENTITYLOGIC_H
#define ENTITYLOGIC_H

#include <memory>

namespace GameEngine
{
/**
 * @class EntityLogic
 * @author Darrion Singh and Sachin Govender
 * @date 27/09/2018
 * @file EntityLogic.h
 * @brief Interface class for all Logic-related operations.
 * Polymorphic in nature, see EntityLogic derived
 * classes for Entity-specific logic functionailty.
 */
class EntityLogic
{
   public:
    /**
     * @brief Spawns Entity object.
     */
    virtual void Spawn() = 0;
    /**
     * @brief Moves Entity object.
     * @param dt Time step of game loop iteration, provided by Run() in Game.h
     */
    virtual void Move(float dt) = 0;
    /**
     * @brief Performs all post-collision checking Entity handling. This includes
     * object deletion, object creation, and various flag-checking and/or
     * flag-setting operations.
     */
    virtual void CollisionHandle() = 0;
};
using LogicPtr = std::unique_ptr<EntityLogic>;
}  // namespace GameEngine

#endif
