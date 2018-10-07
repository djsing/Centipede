#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <ctime>

namespace GameEngine
{
/**
 * @class StopWatch
 * @author Darrion Singh and Sachin Govender
 * @date 29/09/2018
 * @file StopWatch.h
 * @brief Timer object. Provides alternative to sf::Clock object.
 */
class StopWatch
{
   public:
    /**
     * @brief Stopwatch Constructor. Begins timer.
     */
    StopWatch();
    /**
     * @brief Returns time elapsed between the current time and
     * the last time StartTimer() was called.
     * @return Elapsed time as a floating point number.
     */
    float getElapsedTime();
    /**
     * @brief Returns time elapsed between the last time
     * StartTimer() was called. Restarts timer.
     * @return Elapsed time as a floating point number.
     */
    float restart();

   private:
    /**
     * @brief Begins timer. Saves starting time.
     */
    void StartTimer();
    /**
     * @brief Ends timer. Saves ending time.
     */
    void EndTimer();
    float start_time_;
    float stop_time_;
};
}  // namespace GameEngine

#endif
