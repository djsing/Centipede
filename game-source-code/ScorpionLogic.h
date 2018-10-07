#ifndef SCORPIONLOGIC_H
#define SCORPIONLOGIC_H

#include "EntityLogic.h"
#include "Game.h"
#include "GameField.h"

namespace GameEngine
{
/**
 * @class ScorpionLogic
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file ScorpionLogic.h
 * @brief Responsible for all modifications to Scorpion objects.
 * Derived from EntityLogic, polymorphic in nature.
 */
class ScorpionLogic : public EntityLogic
{
   public:
    /**
     * @brief ScorpionLogic Constructor. Seeds STL rand() function. Starts movement timer.
     * Sets movement characteristics to default values.
     * @param field Shared pointer to the GameField container, which contains all
     * Scorpion objects.
     */
    ScorpionLogic(FieldPtr field);
    /**
     * @brief Spawns Scorpion objects when the Scorpion container is empty.
     */
    void Spawn() override;
    /**
     * @brief Moves all Scorpion objects in random new directions after a period
     * of time defined by SCORPION_MOVEMENT_TIME in DEFINITIONS.h
     * @param dt Time step of game loop iteration, provided by Run() in Game.h
     */
    void Move(float dt) override;
    /**
     * @brief Deletes all dead Scorpion objects.
     */
    void CollisionHandle() override;

   private:
    FieldPtr _field;
    float _totalTimePerMovement;
    float _angle;
    float _speed;
};
}  // namespace GameEngine

#endif
