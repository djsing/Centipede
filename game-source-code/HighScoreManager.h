#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <fstream>

namespace GameEngine
{
/**
 * @class HighScoreFileNotFound
 * @author Darrion Singh and Sachin Govender
 * @date 05/10/2018
 * @file HighScoreManager.h
 * @brief Empty class used as an exception for when the
 * highscore file cannot be opened.
 */
class HighScoreFileNotFound
{
};
/**
 * @class HighScoreManager
 * @author Darrion Singh and Sachin Govender
 * @date 05/10/2018
 * @file HighScoreManager.h
 * @brief Stores and Updates the current game score,
 * as well as reads the high score which perists throughout
 * all instances of running the game executable.
 */
class HighScoreManager
{
   public:
    /**
     * @brief HighScoreManager Constructor
     */
    HighScoreManager();
    /**
     * @brief Increases the current game score.
     * @param increment Score increment.
     */
    void IncrementScore(int increment);
    /**
     * @brief Decreases the current game score.
     * @param decrement Score decrement.
     */
    void DecrementScore(int decrement);
    /**
     * @brief Returns the current score of the player.
     * @return Integer score value.
     */
    int GetScore();
    /**
     * @brief Returns the current High score.
     * @return String containing the high score value.
     */
    std::string GetHighScore();
    /**
     * @brief Changes the high score if the player succeeds
     * in surpassing it.
     */
    void UpdateHighScore();
    /**
     * @brief Resets the player score to zero.
     */
    void ResetScore();
    /**
     * @brief Returns whether the high score has been surpassed
     * by the current score.
     * @return True if the current score is higher than the High Score,
     * else False.
     */
    bool HighScoreSurpassed();

   private:
    bool high_score_surpassed_;
    int score_;
    std::string high_score_;
    std::fstream high_score_file_;
};
}  // namespace GameEngine

#endif