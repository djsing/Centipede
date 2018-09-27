#include <ctime>
#include "StopWatch.h"
using namespace std;

namespace GameEngine
{
StopWatch::StopWatch()
{
    // start clock when instance created
    StartTimer();
}

void StopWatch::StartTimer()
{
    clock_t time = clock();
    _startTime = static_cast<float>(time) / CLOCKS_PER_SEC;
}

void StopWatch::EndTimer()
{
    clock_t time = clock();
    _stopTime = static_cast<float>(time) / CLOCKS_PER_SEC;
}

// return elapsedTime as well as restart the timer
float StopWatch::restart()
{
    EndTimer();
    float elapsedTime = getElapsedTime();
    StartTimer();
    return elapsedTime;
}

// return elapsedTime without affecting timer
float StopWatch::getElapsedTime()
{
    EndTimer();
    float elapsedTime = _stopTime - _startTime;
    return elapsedTime;
}
}  // namespace GameEngine