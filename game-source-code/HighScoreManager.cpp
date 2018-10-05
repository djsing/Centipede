#include "DEFINITIONS.h"
#include "HighScoreManager.h"

namespace GameEngine
{
HighScoreManager::HighScoreManager() : score_(0), high_score_(0)
{
    high_score_file_.open(HIGHSCORE_FILEPATH, std::ios::in);

    if(!high_score_file_.is_open())
	{
	    throw HighScoreFileNotFound();
	}
    high_score_file_ >> high_score_;
    high_score_file_.close();
}

void HighScoreManager::IncrementScore(int increment)
{
    score_ += increment;
}

void HighScoreManager::DecrementScore(int decrement)
{
    score_ -= decrement;
}

int HighScoreManager::GetScore()
{
    return score_;
}

int HighScoreManager::GetHighScore()
{
    return high_score_;
}

void HighScoreManager::UpdateHighScore()
{
    if(score_ > high_score_)
	{
	    high_score_ = score_;
	    high_score_file_.open(HIGHSCORE_FILEPATH, std::ios::out);
	    high_score_file_ << high_score_;
	    high_score_file_.close();
	}
}
}  // namespace GameEngine