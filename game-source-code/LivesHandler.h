#ifndef LIVESHANDLER_H
#define LIVESHANDLER_H

namespace GameEngine
{
/**
 * @class LivesHandler
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file LivesHandler.h
 * @brief Manages the number of lives that the player has remaining.
 * Part of Data layer, so that the number of lives is persistent
 * throughout instances of the game.
 */
class LivesHandler
{
   public:
    /**
     * @brief LivesHandler Constructor. Sets starting lives to the number
     * defined STARTING_LIVES in DEFINITIONS.h
     */
    LivesHandler();
    /**
     * @brief Returns the number of lives the player has remaining.
     * @return Returns integer that is the number of lives remaining.
     */
    unsigned int LivesRemaining();
    /**
     * @brief Decrements number of lives by 1.
     */
    void LifeLost();
    /**
     * @brief Increments number of lives by 1. Does not increment
     * lives when the number of lives remaining is equal to STARTING_LIVES
     * as defined in DEFINITIONS.h
     */
    void LifeGained();
    /**
     * @brief Resets number of lives remaining to STARTING_LIVES as defined
     * in DEFINITIONS.h
     */
    void ResetLives();

   private:
    int lives_remaining_;
};
}  // namespace GameEngine

#endif
