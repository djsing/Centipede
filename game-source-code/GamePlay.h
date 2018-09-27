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
class GamePlay : public GameState
{
   public:
    GamePlay(DataPtr data);
    ~GamePlay();

    void HandleInput() override;
    void Update(float dt) override;
    void Draw() override;

	private:
   void SpawnEntities();
   void MoveEntities(float dt);
   void CheckCollisions();
   void DeleteDeadEntities();
    // Data layer pointer
    DataPtr data_;
    // Centipede object shared pointer
    CentPtr centipede_;
    // Centipede logic unique pointer
    LogicPtr centipede_logic_;
    // Centipede Renderer pointer
    RenderPtr centipede_renderer_;
    // Turret object pointer
    TurretPtr turret_;
    // Turret Logic pointer
    LogicPtr turret_logic_;
    // Turret Renderer pointer
    RenderPtr turret_renderer_;
    // Mushroom Logic Pointer
    LogicPtr mush_logic_;
    // Mushroom Renderer pointer
    RenderPtr mush_renderer_;
    // Spider Logic pointer
    LogicPtr spider_logic_;
    // Spider Render pointer
    RenderPtr spider_renderer_;
    // Spider Logic pointer
    LogicPtr scorpion_logic_;
    // Spider Render pointer
    RenderPtr scorpion_renderer_;
    // Input Handler Pointer
    InputHandlerPtr input_handler_;
    // CollisionHandler pointer
    CollisionHandlerPtr collision_handler_;
    // Game field pointer
    FieldPtr field_;
    // bullet logic pointer
    LogicPtr bullet_logic_;
    // bullet renderer pointer
    RenderPtr bullet_renderer_;
};
}  // namespace GameEngine

#endif
