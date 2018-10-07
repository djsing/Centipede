#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Centipede.h"
#include "Game.h"
#include "GameField.h"
#include "Turret.h"

namespace GameEngine
{
/**
 * @class CollisionHandler
 * @author Darrion Singh and Sachin Govender
 * @date 27/09/2018
 * @file CollisionHandler.h
 * @brief Checks for collisions between Entity objects. Sets flags and saves co-ordinates, depending
 * on which objects are colliding.
 */
class CollisionHandler
{
   public:
    /**
     * @brief CollisionHandler Constructor. Saves various shared pointers.
     * @param data Shared pointer to Data layer, which contains the number of lives the player (Turret)
     * has remaining.
     * @param turret Shared pointer to the Turret object.
     * @param centipede Shared pointer to the Centipede container.
     * @param field Shared pointer to the Field container, which contains all instances of Mushroom,
     * Scorpion, and Spider.
     */
    CollisionHandler(DataPtr data, TurretPtr turret, CentPtr centipede, FieldPtr field);
    /**
     * @brief Calls all collision checking functions that are neccessary, based on the
     * current state of the Turret or the Centipede.
     */
    void CheckCollisions();

   private:
    DataPtr data_;
    TurretPtr turret_;
    CentPtr centipede_;
    FieldPtr field_;
    /**
     * @brief Checks collisions between Bullet objects and CentipedeSegment objects.
     */
    void CheckBulletSegmentCollisions();
    /**
     * @brief Checks collisions between CentipedeSegment objects and Mushroom objects.
     */
    void CheckSegmentMushroomCollisions();
    /**
     * @brief Checks collisions between the Turret and CentipedeSegment objects.
     */
    void CheckTurretSegmentCollisions();
    /**
     * @brief Checks collisions between the Turret and Spider objects.
     */
    void CheckTurretSpiderCollisions();
    /**
     * @brief Checks collisions between Mushroom objects and Scorpion objects.
     */
    void CheckMushroomScorpionCollisions();
    /**
     * @brief Checks collisions between Mushroom objects and Spider objects.
     */
    void CheckMushroomSpiderCollisions();
    /**
     * @brief Checks collisions between Bullet objects and Spider objects.
     */
    void CheckBulletSpiderCollisions();
    /**
     * @brief Checks collisions between Bullet objects and Spider objects.
     */
    void CheckBulletMushroomCollisions();
    /**
     * @brief Checks collisions between Bullet objects and Bomb objects.
     */
    void CheckBulletBombCollisions();
    /**
     * @brief Checks collisions between the exploded bomb and other
     * enemy Entity objects.
     */
    void CheckExplosionCollisions();
    /**
     * @brief Checks the distance between two Entity objects.
     * @param entity1 Object of type Entity.
     * @param entity2 Object of type Entity.
     * @return Float containing the distance between entity1 and entity2,
     * calculated using the Cartesian distance formula.
     */
    float CheckDistanceBetweenEntities(Entity& entity1, Entity& entity2);
};
using CollisionHandlerPtr = std::shared_ptr<CollisionHandler>;
}  // namespace GameEngine

#endif
