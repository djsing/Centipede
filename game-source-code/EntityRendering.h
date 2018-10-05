#ifndef ENTITYRENDERING_H
#define ENTITYRENDERING_H

#include <memory>
#include "Centipede.h"
#include "Game.h"
#include "GameField.h"
#include "Turret.h"

namespace GameEngine
{
/**
 * @class EntityRendering
 * @author Darrion Singh and Sachin Govender
 * @date 27/09/2018
 * @file EntityRendering.h
 * @brief Performs drawing-related operations
 * for all Entity objects.
 */
class EntityRendering
{
   public:
    EntityRendering(DataPtr data, TurretPtr turret, CentPtr centipede, FieldPtr field);
    /**
     * @brief Draws all Entity objects to the screen.
     */
    void Draw();

   private:
    /**
     * @brief Draws all Bullet objects.
     */
    void DrawBullets();
    /**
     * @brief Draws all CentipedeSegment objects.
     */
    void DrawCentipede();
    /**
     * @brief Draws all Mushroom objects.
     */
    void DrawMushrooms();
    /**
     * @brief Draws all Scorpion objects.
     */
    void DrawScorpions();
    /**
     * @brief Draws all Spider objects.
     */
    void DrawSpiders();
    /**
     * @brief Draws Turret object.
     */
    void DrawTurret();
    /**
     * @brief Draws all Bomb objects.
     */
    void DrawBombs();
    /**
     * @brief Draws live game score to the screen.
     */
    void DisplayScore();
    // Shared pointer to Data layer.
    DataPtr data_;
    // Shared pointer to Turret object.
    TurretPtr turret_;
    // Shared pointer to Centipede container.
    CentPtr centipede_;
    // Shared pointer to GameField container.
    FieldPtr field_;
    // sprites to display the number of lives
    // the player has remaining.
    sf::Sprite life_;
    sf::Sprite explosion_;
    sf::Sprite score_digit_;
};
using RenderPtr = std::unique_ptr<EntityRendering>;
}  // namespace GameEngine

#endif
