#include <string>
#include "DEFINITIONS.h"
#include "HighScoreManager.h"

namespace GameEngine
{
HighScoreManager::HighScoreManager() : high_score_surpassed_(false), score_(0), high_score_("")
{
    high_score_file_.open(HIGHSCORE_FILEPATH, std::ios::in);
    try
	{
	    if(!high_score_file_.is_open())
		{
		    throw HighScoreFileNotFound();
		}
	}
    catch(HighScoreFileNotFound)
	{
	    std::ofstream high_score_file_(HIGHSCORE_FILEPATH);
	    high_score_file_ << 100;
	}

    high_score_file_ >> high_score_;
    high_score_file_.close();
}

void HighScoreManager::IncrementScore(unsigned int increment)
{
    score_ += increment;
}

void HighScoreManager::DecrementScore(unsigned int decrement)
{
    if(score_ > decrement)
	{
	    score_ -= decrement;
	}
    else
	score_ = 0;
}

unsigned int HighScoreManager::GetScore()
{
    return score_;
}

std::string HighScoreManager::GetHighScore()
{
    return high_score_;
}

void HighScoreManager::UpdateHighScore()
{
    high_score_surpassed_ = false;
    if(score_ >= static_cast<unsigned int>(std::stoi(high_score_)))
	{
	    high_score_ = std::to_string(score_);
	    high_score_file_.open(HIGHSCORE_FILEPATH, std::ios::out);
	    high_score_file_ << high_score_;
	    high_score_file_.close();
	    high_score_surpassed_ = true;
	}
}

void HighScoreManager::ResetScore()
{
    score_ = 0;
}

bool HighScoreManager::HighScoreSurpassed()
{
    return high_score_surpassed_;
}
}  // namespace GameEngine