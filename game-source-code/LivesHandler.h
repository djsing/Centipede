#ifndef LIVESHANDLER_H
#define LIVESHANDLER_H

namespace GameEngine
{
	class LivesHandler
	{
	public:
		LivesHandler();

		int LivesRemaining();

		void LifeLost();
		void LifeGained();
		void ResetLives();

	private:
		int lives_remaining_;
	};
} // namespace GameEngine

#endif
