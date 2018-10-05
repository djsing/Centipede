#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <fstream>

namespace GameEngine
{
class HighScoreFileNotFound
{
};
class HighScoreManager
{
   public:
    HighScoreManager();
    void IncrementScore(int increment);
    void DecrementScore(int decrement);

    int GetScore();
    int GetHighScore();

    void UpdateHighScore();

   private:
    int score_;
    int high_score_;
    std::fstream high_score_file_;
};
}  // namespace GameEngine

#endif