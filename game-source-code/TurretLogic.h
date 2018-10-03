#ifndef TURRETLOGIC_H
#define TURRETLOGIC_H

#include <memory>
#include "BulletLogic.h"
#include "EntityLogic.h"
#include "Game.h"
#include "Turret.h"

namespace GameEngine
{
/**
 * @class TurretLogic
 * @author Darrion Singh and Sachin Govender
 * @date 29/09/2018
 * @file TurretLogic.h
 * @brief Controls all turret Logic-related operations.
 */
class TurretLogic : public EntityLogic
{
   public:
    /**
     * @brief TurretLogic Constructor.
     * @param data Shared pointer to Data layer.
     * @param turret Shared pointer to Turret object.
     */
    TurretLogic(DataPtr data, TurretPtr turret);
    /**
     * @brief Spawn Bullet objects.
     */
    void Spawn() override;
    /**
     * @brief Moves Turret object.
     * @param dt Timestep given by game loop.
     */
    void Move(float dt) override;
    /**
     * @brief Adds a new instance of the game when
     * the Turret is dead, ends the game when there
     * are no lives remaining.
     */
    void CollisionHandle() override;

   private:
    DataPtr _data;
    TurretPtr _turret;
    float _speed;
};
}  // namespace GameEngine

#endif
