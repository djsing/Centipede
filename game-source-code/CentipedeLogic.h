#ifndef CENTIPEDELOGIC_H
#define CENTIPEDELOGIC_H

#include <memory>
#include "Centipede.h"
#include "EntityLogic.h"
#include "Game.h"

namespace GameEngine
{
/**
 * @class CentipedeLogic
 * @author Darrion Singh and Sachin Govender
 * @date 27/09/2018
 * @file CentipedeLogic.h
 * @brief Responsible for all modifications to CentipedeSegment objects.
 * Derived from EntityLogic, polymorphic in nature.
 */
class CentipedeLogic : public EntityLogic
{
   public:
    /**
     * @brief CentipedeLogic Constructor. Saves a shared pointer to the Data layer,
     * as well as sets default movement characteristics.
     * @param data Shared Pointer to the Data layer, used to queue the GameWon
     * state when the player has successfully killed all CentipedeSegment objects.
     * @param centipede Shared pointer to the Centipede container.
     */
    CentipedeLogic(DataPtr data, CentPtr centipede);
    /**
     * @brief Spawns CentipedeSegment objects into the Centipede container.
     * CentipedeSegments spawn in the beginning of the game.
     */
    void Spawn() override;
    /**
     * @brief Moves all CentipedeSegment objects contained in the Centipede container.
     * @param dt Time step of game loop iteration, provided by Run() in Game.h
     */
    void Move(float dt) override;

    /**
     * @brief Deletes all dead CentipedeSegment objects, sets CentipedeSegment
     * objects successive to dead CentipedeSegment objects to be a head.
     */
    void CollisionHandle() override;

   private:
    // Shared pointer to Data layer.
    DataPtr data_;
    // Shared pointer to centipede container.
    CentPtr centipede_;
    // Speed of the centipede.
    float speed_;
    // Move distance for each centipede segment.
    float move_distance_;
    // Tracks initial number of centipede segments.
    unsigned int number_of_centipede_segments_;
    /**
     * @brief Moves CentipedeSegment object downwards.
     * @param index Reference to a CentipedeSegment object.
     */
    void MoveDown(CentipedeSegment& index);
    /**
     * @brief Moves CentipedeSegment object upwards.
     * @param index Reference to a CentipedeSegment object.
     */
    void MoveUp(CentipedeSegment& index);
    /**
     * @brief Moves CentipedeSegment object to the left.
     * @param Current trajectory of the CentipedeSegment,
     * as defined in Trajectory.h
     * @param index Reference to a CentipedeSegment object.
     */
    void MoveLeft(Trajectory trajectory, CentipedeSegment& index);
    /**
     * @brief Moves CentipedeSegment object to the right.
     * @param Current trajectory of the CentipedeSegment,
     * as defined in Trajectory.h
     * @param index Reference to a CentipedeSegment object.
     */
    void MoveRight(Trajectory trajectory, CentipedeSegment& index);
};
}  // namespace GameEngine

#endif
