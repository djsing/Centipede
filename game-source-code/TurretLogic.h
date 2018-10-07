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
 * @brief Responsible for all modifications to Turret object.
 * Derived from EntityLogic, polymorphic in nature.
 */
class TurretLogic : public EntityLogic
{
   public:
    /**
     * @brief TurretLogic Constructor. Sets default movement characteristics.
     * @param data Shared pointer to Data layer.
     * @param turret Shared pointer to Turret object.
     */
    TurretLogic(DataPtr data, TurretPtr turret);
    /**
     * @brief Spawn Bullet object. Only spawns when most recently fired bullet
     * has no positional overlap with the Turret object.
     */
    void Spawn() override;
    /**
     * @brief Moves Turret object. Movement determined by direction saved in
     * KeyboardControlsHandler instance in the Data layer.
     * @param dt Time step of game loop iteration, provided by Run() in Game.h
     */
    void Move(float dt) override;
    /**
     * @brief Adds a new instance of the game and decrements Turret lives when
     * the Turret dies after a fatal collision with specific Entity objects.
     * Ends the game when there are no more Turret lives remaining.
     */
    void CollisionHandle() override;

   private:
    DataPtr data_;
    TurretPtr turret_;
    float speed_;
};
}  // namespace GameEngine

#endif
