#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"
#include "StopWatch.h"

namespace GameEngine
{
	class SplashScreen: public GameState
	{
	public:
		SplashScreen(DataPtr data);

		void HandleInput() override;
		void Update(float dt) override;
		void Draw() override;

	private:
		DataPtr _data;
		StopWatch _watch;
		sf::Sprite _background;
	};

}
#endif