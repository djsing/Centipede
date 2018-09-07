#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <ctime>

namespace GameEngine
{
	class StopWatch
	{
		public:
			// Default Constructor
			StopWatch();
			// Destructor
			~StopWatch(){};
			// returns time elapsed between the call and 
			// the last restart() or instance creation
			float getElapsedTime();

			// returns time elapsed between the call and the last 
			// restart() or instance creation and restarts clock
			float restart();
		private:
			void StartTimer();
			void EndTimer();
			float _startTime;
			float _stopTime;
	}; 
}

#endif
