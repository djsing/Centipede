#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Centipede.h"
#include "CollisionHandler.h"
#include "EntityLogic.h"
#include "EntityRendering.h"
#include "Game.h"
#include "GameField.h"
#include "GameState.h"
#include "InputHandler.h"
#include "Turret.h"

namespace GameEngine
{
/**
 * @class GamePlay
 * @author Darrion Singh and Sachin Govender
 * @date 28/09/2018
 * @file GamePlay.h
 * @brief The game screen, i.e. the state of
 * the game where the player still has one life
 * remaining and the game is neither won, nor lost.
 */
class GamePlay : public GameState
{
   public:
    /**
     * @brief GamePlay Constructor.
     * @param data Shared pointer to Data layer.
     */
    GamePlay(DataPtr data);
    /**
     * @brief Processes the keyboard input given to
     * game by the player.
     */
    void HandleInput() override;
    /**
     * @brief Updates all Entity objects in that
     * instance of the game. Spawns/Moves/Checks/Deletes
     * all Entity objects currently in the game.
     * @param dt Timestep given by the game loop.
     * Given to the Move() functions of the particular
     * Entity objects.
     */
    void Update(float dt) override;
    /**
     * @brief Draws all Entity objects to the screen.
     */
    void Draw() override;

   private:
    /**
     * @brief Calls all spawn functions from EntityLogic
     * for all Entity types. Each type spawns conditionally,
     * explicitly defined in their respective Spawn() functions.
     */
    void SpawnEntities();
    /**
     * @brief Moves all Entity objects currently in the game.
     * @param dt Timestep given by game loop.
     */
    void MoveEntities(float dt);
    /**
     * @brief Checks collisions between all Entity objects,
     * sets all relevant flags associated with collisions.
     */
    void CheckCollisions();
    /**
     * @brief Handles all operations caused by collisions,
     * including deletion and other logical operations.
     */
    void HandleCollisions();
    // Data layer pointer
    DataPtr data_;
    // Object pointers
    CentPtr centipede_;
    FieldPtr field_;
    TurretPtr turret_;
    // Logic pointers
    LogicPtr bullet_logic_;
    LogicPtr centipede_logic_;
    LogicPtr turret_logic_;
    LogicPtr mush_logic_;
    LogicPtr spider_logic_;
    LogicPtr scorpion_logic_;
	LogicPtr bombs_logic_;
    // Input Handler Pointer
    InputHandlerPtr input_handler_;
    // CollisionHandler pointer
    CollisionHandlerPtr collision_handler_;
    // Rendering class pointer
    RenderPtr renderer_;
};
}  // namespace GameEngine

#endif
