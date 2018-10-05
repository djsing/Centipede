#include <string>
#include "DEFINITIONS.h"
#include "HighScoreManager.h"

namespace GameEngine
{
HighScoreManager::HighScoreManager() : score_(0), high_score_("")
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
    if(score_ > decrement)
	{
	    score_ -= decrement;
	}
    else
	score_ = 0;
}

int HighScoreManager::GetScore()
{
    return score_;
}

std::string HighScoreManager::GetHighScore()
{
    return high_score_;
}

void HighScoreManager::UpdateHighScore()
{
    if(score_ > std::stoi(high_score_))
	{
	    high_score_ = std::to_string(score_);
	    high_score_file_.open(HIGHSCORE_FILEPATH, std::ios::out);
	    high_score_file_ << high_score_;
	    high_score_file_.close();
	}
}

void HighScoreManager::ResetScore()
{
    score_ = 0;
}
}  // namespace GameEngine