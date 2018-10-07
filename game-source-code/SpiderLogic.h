#ifndef SPIDERLOGIC_H
#define SPIDERLOGIC_H

#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
/**
 * @class SpiderLogic
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file SpiderLogic.h
 * @brief Responsible for all modifications to Spider objects.
 * Derived from EntityLogic, polymorphic in nature.
 */
class SpiderLogic : public EntityLogic
{
   public:
    /**
     * @brief SpiderLogic Constructor. Seeds STL rand() function. Starts spawn and movement timer.
     * Sets movement characteristics to default values.
     * @param field Shared pointer to the GameField container, which contains all
     * Spider objects.
     */
    SpiderLogic(FieldPtr field);
    /**
     * @brief Spawns Spider objects periodically as defined by SPIDER_TIME in DEFINITIONS.h
     */
    void Spawn() override;
    /**
     * @brief Moves all Spider objects in random new directions after a period
     * of time defined by SPIDER_MOVEMENT_TIME in DEFINITIONS.h
     * @param dt Time step of game loop iteration, provided by Run() in Game.h
     */
    void Move(float dt) override;
    /**
     * @brief Deletes all dead Spider objects.
     */
    void CollisionHandle() override;

   private:
    /**
     * @brief Changes current angle of movement of a particular Spider object.
     * @param index Reference to a Spider object.
     */
    void ChangeDirection(Spider& index);
    FieldPtr _field;
    StopWatch spawn_timer_;
    StopWatch move_timer_;
    float _speed;
};
}  // namespace GameEngine

#endif
