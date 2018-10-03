#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <tuple>
#include "Direction.h"
#include "Region.h"
#include "RegionHandler.h"

namespace GameEngine
{
/**
 * @class Entity
 * @author Darrion Singh and Sachin Govender
 * @date 27/09/2018
 * @file Entity.h
 * @brief Parent class from which all Entity objects inherit.
 */
class Entity
{
   public:
    /**
     * @brief Operator overloading to allow an Entity to be compared to a boolean,
     * returns true if the Entity object is dead, i.e. when IsDead() returns true.
     * @param entity The entity being checked.
     * @param dead True if checking whether the Entity is dead, False if checking
     * whether the Entity is alive.
     */
    friend bool operator==(const Entity& entity, bool dead);
    /**
     * @brief Operator overloading to allow an Entity to be compared to a pair of
     * of regions (Region, Subregion), returns true if the Entity object is located
     * in that Region and Subregion.
     * in that
     * @param entity The entity being checked.
     * @param region A pair of type Region and SubRegion.
     */
    friend bool operator==(const Entity& entity, std::pair<Region, Region> region);
    /**
     * @brief Entity Constructor.
     * @param topLeftXPosition The desired x position of the Entity's top left corner.
     * @param topLeftYPosition The desired y position of the Entity's top left corner.
     */
    Entity(float topLeftXPosition, float topLeftYPosition);
    /**
     * @brief Sets Direction of the Entity
     * @param direction The desired direction from those defined in Direction.h
     */
    void SetDirection(Direction direction);
    /**
     * @brief Sets the top left x position of the Entity.
     * @param xpos The desired x position.
     */
    virtual void SetTopLeftXPosition(float xpos);
    /**
     * @brief Sets the top left y position of the Entity.
     * @param ypos the desired y position.
     */
    virtual void SetTopLeftYPosition(float ypos);
    /**
     * @brief Sets whether the Entity is dead.
     * @param isDead True if the Entity is dead, else False.
     */
    void SetDead(bool isDead);
    /**
     * @brief Returns the Entity's sprite.
     * @return Address of the sprite sf::Sprite&
     */
    sf::Sprite& GetObjectSprite();
    /**
     * @brief Returns whether the Entity is dead.
     * @return True if the entity is dead, else false.
     */
    bool IsDead() const;
    /**
     * @brief Returns the Direction that the Entity is moving.
     * @return Return type Direction, as defined in Direction.h
     */
    Direction GetDirection() const;
    /**
     * @brief Returns the Region in which the Entity exists.
     * @return Returns type Region, as defined in Region.h
     */
    Region GetRegion() const;
    /**
     * @brief Returns the subregion of the Region in which the
     * entity exists.
     * @return Returns type Region as defined in Region.h
     */
    Region GetSubRegion() const;
    /**
     * @brief Returns the top left x position of the Entity.
     * @return Returns x position.
     */
    float GetTopLeftXPosition() const;
    /**
     * @brief Returns the top left y position of the Entity.
     * @return Returns y position.
     */
    float GetTopLeftYPosition() const;
    /**
     * @brief Returns the center x position.
     * @return Returns x position.
     */
    float GetCenterXPosition() const;
    /**
     * @brief Returns the center y position.
     * @return Returns y position.
     */
    float GetCenterYPosition() const;

   protected:
    /**
     * @brief Sets the center x position of the Entity.
     * @param xpos The desired x position.
     */
    void SetCenterXPosition(float xpos);
    /**
     * @brief Sets the center y position of the Entity.
     * @param ypos The desired y position.
     */
    void SetCenterYPosition(float ypos);

   private:
    /**
     * @brief Sets the region of the screen which the Entity is found
     * @param region The desired region from those defined in Region.h
     */
    void SetRegion(Region region);
    /**
     * @brief Sets the subregion of a particular region which the Entity
     * is found.
     * @param subregion The desired subregion from those defined in Region.h
     */
    void SetSubRegion(Region subregion);
    sf::Sprite object_;
    // Position/Movement Attributes
    Direction direction_;
    float top_left_x_position_;
    float top_left_y_position_;
    float center_x_position_;
    float center_y_position_;
    RegionHandler region_handler_;
    Region region_;
    Region subregion_;
    bool isDead_;
};
}  // namespace GameEngine

#endif
