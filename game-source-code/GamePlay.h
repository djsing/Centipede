#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"
#include "Centipede.h"
#include "Turret.h"
#include "InputHandler.h"
#include "CollisionHandler.h"

namespace GameEngine
{
	class GamePlay: public GameState
	{
	public:
		GamePlay(DataPtr data);
		~GamePlay();
		void Initialise();
		void HandleInput();
		void Update(float dt);
		void Draw();

	private:
		DataPtr _data;
		sf::Sprite _background;
		CentPtr _centipede;
		TurretPtr _turret;
		int _numberOfCentipedeSegments;
		InputHandlerPtr _inputHandler;
		CollisionHandlerPtr _collisionhandler;
	};
}

#endif