#ifndef ENTITY_H
#define ENTITY_H

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
     * @brief Operator overloading to allow an Entity to be compared to a boolean.
     * @param entity The entity being checked.
     * @param dead True if checking whether the Entity is dead, False if checking
     * whether the Entity is alive.
     * @return Returns dead == entity.IsDead()
     * i.e. If the Entity is being checked to see if it is dead (dead = True):
     * returns True if the Entity object is dead, else False.
     * If the Entity is being checked to see if it is alive (dead = False):
     * returns True if the Entity object is alive, else False.
     */
    friend bool operator==(const Entity& entity, bool dead);
    /**
     * @brief Operator overloading to allow an Entity to be compared to a pair of
     * of regions (Region, Subregion).
     * in that
     * @param entity The entity being checked.
     * @param region std::pair<Region, Region> representing (Region, SubRegion).
     * @return Returns True if the Entity object is located
     * in that Region and Subregion.
     */
    friend bool operator==(const Entity& entity, std::pair<Region, Region> region);
    /**
     * @brief Entity Constructor. Sets object's top left x and y postion. Sets object's
     * default state to alive (dead = False).
     * @param topLeftXPosition The desired x position of the Entity's top left corner.
     * @param topLeftYPosition The desired y position of the Entity's top left corner.
     */
    Entity(float topLeftXPosition, float topLeftYPosition);
    /**
     * @brief Sets Direction of Entity movement.
     * @param direction The desired direction, as defined in Direction.h
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
     * @param isDead True to set the Entity as dead, else False.
     */
    void SetDead(bool isDead = true);
    /**
     * @brief Returns whether the Entity object is dead.
     * @return True if the Entity object is dead, else False.
     */
    bool IsDead() const;
    /**
     * @brief Returns the Direction that the Entity is moving.
     * @return Return current direction, as defined in Direction.h
     */
    Direction GetDirection() const;
    /**
     * @brief Returns the Region in which the Entity exists.
     * @return Returns current region, as defined in Region.h
     */
    Region GetRegion() const;
    /**
     * @brief Returns the subregion of the Region in which the
     * entity exists.
     * @return Returns current subregion as defined in Region.h
     */
    Region GetSubRegion() const;
    /**
     * @brief Returns the top left x position of the Entity.
     * @return Returns float containing x position.
     */
    float GetTopLeftXPosition() const;
    /**
     * @brief Returns the top left y position of the Entity.
     * @return Returns float containing y position.
     */
    float GetTopLeftYPosition() const;
    /**
     * @brief Returns the center x position.
     * @return Returns float containing x position.
     */
    float GetCenterXPosition() const;
    /**
     * @brief Returns the center y position.
     * @return Returns y float containing position.
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
     * @brief Sets the region of the screen in which the Entity is located.
     * @param region The desired region from those defined in Region.h
     */
    void SetRegion(Region region);
    /**
     * @brief Sets the subregion of a particular region which the Entity
     * is found.
     * @param subregion The desired subregion from those defined in Region.h
     */
    void SetSubRegion(Region subregion);
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
