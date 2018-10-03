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
 * @brief Controls the spawning of CentipedeSegment objects into a particular
 * Centipede, the movements of all CentipedeSegment objects of a particualr
 * Centipede, the deletion of all dead CentipedeSegment objects, all well as
 * setting flags of surrounding CentipedeSegment objects that are triggered
 * by collisions.
 */
class CentipedeLogic : public EntityLogic
{
   public:
    /**
     * @brief CentipedeLogic Constructor.
     * @param data Shared Pointer to the Data layer, used to queue the GameWon
     * state when the Centipede is empty, i.e. when the player has successfully
     * killed all CentipedeSegment objects.
     * @param centipede Shared pointer to the Centipede container.
     */
    CentipedeLogic(DataPtr data, CentPtr centipede);
    /**
     * @brief Spawns CentipedeSegment objects into a particular Centipede.
     */
    void Spawn() override;
    /**
     * @brief Moves all CentipedeSegment objects contained in the Centipede.
     * @param dt Timestep given by the Game loop.
     */
    void Move(float dt) override;

    /**
     * @brief Deletes all dead CentipedeSegment objects, sets CentipedeSegment
     * objects successive to dead CentipedeSegment objects to be a head.
     */
    void CollisionHandle() override;

   private:
    /**
     * @brief Shared pointer to Data layer.
     */
    DataPtr data_;
    /**
     * @brief Shared pointer to centipede container.
     */
    CentPtr centipede_;
    /**
     * @brief Speed of the centipede.
     */
    float speed_;
    /**
     * @brief Move distance for each centipede segment.
     */
    float move_distance_;
    /**
     * @brief Tracks initial number of centipede segments.
     */
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
     * @param index Reference to a CentipedeSegment object.
     */
    void MoveLeft(Trajectory trajectory, CentipedeSegment& index);
    /**
     * @brief Moves CentipedeSegment object to the right.
     * @param index Reference to a CentipedeSegment object.
     */
    void MoveRight(Trajectory trajectory, CentipedeSegment& index);
};
}  // namespace GameEngine

#endif
