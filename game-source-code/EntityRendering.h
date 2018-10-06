#ifndef ENTITYRENDERING_H
#define ENTITYRENDERING_H

#include <SFML/Graphics.hpp>
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
    // sprite to display lives remaining
    sf::Sprite life_;
    // sprite to display score
    sf::Sprite zero_;
	sf::Sprite one_;
	sf::Sprite two_;
	sf::Sprite three_;
	sf::Sprite four_;
	sf::Sprite five_;
	sf::Sprite six_;
	sf::Sprite seven_;
	sf::Sprite eight_;
	sf::Sprite nine_;
    // sprites for Entity objects
    sf::Sprite turret_sprite_;
    sf::Sprite body_segment_;
    sf::Sprite head_segment_;
    sf::Sprite scorpion_;
    sf::Sprite spider_;
    sf::Sprite bullet_;
    // sprites for non-triggered and triggered states of the bomb
    sf::Sprite bomb_;
    sf::Sprite explosion_;
    // sprites for mushrooms with varying lives remaining and poisoned state
    sf::Sprite mushroom_;
    sf::Sprite mushroom1_;
    sf::Sprite mushroom2_;
    sf::Sprite mushroom3_;
    sf::Sprite poisoned_mushroom_;
    sf::Sprite poisoned_mushroom1_;
    sf::Sprite poisoned_mushroom2_;
    sf::Sprite poisoned_mushroom3_;
    // file paths to entity related sprites
    const std::string SEGMENT_FILEPATH_ = "Resources\\centipedesegment.png";
    const std::string BODY_SEGMENT_FILEPATH_ = "Resources\\bodycentipedesegment.png";
    const std::string TURRET_FILEPATH_ = "Resources\\turret.png";
    const std::string BULLET_FILEPATH_ = "Resources\\bullet.jpg";
    const std::string MUSHROOM_FILEPATH_ = "Resources\\mushroom.png";
    const std::string MUSHROOM3_FILEPATH_ = "Resources\\mushroom3lives.png";
    const std::string MUSHROOM2_FILEPATH_ = "Resources\\mushroom2lives.png";
    const std::string MUSHROOM1_FILEPATH_ = "Resources\\mushroom1life.png";
    const std::string POISONED_MUSHROOM_FILEPATH_ = "Resources\\mushroompoisoned.png";
    const std::string POISONED_MUSHROOM3_FILEPATH_ = "Resources\\mushroompoisoned3lives.png";
    const std::string POISONED_MUSHROOM2_FILEPATH_ = "Resources\\mushroompoisoned2lives.png";
    const std::string POISONED_MUSHROOM1_FILEPATH_ = "Resources\\mushroompoisoned1life.png";
    const std::string SPIDER_FILEPATH_ = "Resources\\spider.png";
    const std::string SCORPION_FILEPATH_ = "Resources\\scorpion.png";
    const std::string HEART_FILEPATH_ = "Resources\\lives.png";
    const std::string BOMB_FILEPATH_ = "Resources\\bomb.png";
    const std::string EXPLOSION_FILEPATH_ = "Resources\\explosion.png";
};
using RenderPtr = std::unique_ptr<EntityRendering>;
}  // namespace GameEngine

#endif
