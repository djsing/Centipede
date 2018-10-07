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
#include "StateRenderer.h"
#include "Turret.h"

namespace GameEngine
{
/**
 * @class GamePlay
 * @author Darrion Singh and Sachin Govender
 * @date 28/09/2018
 * @file GamePlay.h
 * @brief The version of the game loop which runs when the game is in play.
 */
class GamePlay : public GameState
{
   public:
    /**
     * @brief GamePlay Constructor. Creates all instances of vital Entity
     * objects, Entity containers, all instances of logic objects neccessary
     * to process the changes made to the Entity objects. Creates all instances
     * of the EntityRendering and StateRendering class, for drawing all Entity
     * related sprites as well as State related sprites.
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
     * @param dt Time step of game loop iteration, provided by Run() in Game.h
     * Given to the Move() functions of the particular Entity objects.
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
     * @brief Calls all move functions from EntityLogic for all Entity types.
     * Each type Entity type moves conditionally, explicitly defined in their
     * respective Move() functions.
     * @param dt Time step of game loop iteration, provided by Run() in Game.h
     * Given to the Move() functions of the particular Entity objects.
     */
    void MoveEntities(float dt);
    /**
     * @brief Calls CollisionHandler class to perform collision checking.
     */
    void CheckCollisions();
    /**
     * @brief Calss all collision handling from EntityLogic for all Entity
     * types. Each type handles collisions conditionally, explicitly defined
     * in their respective CollisionHandle() functions.
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
    // Entity Rendering class pointer
    RenderPtr renderer_;
    // State Rendering class pointer
    StateRenderPtr state_renderer_;
};
}  // namespace GameEngine

#endif
