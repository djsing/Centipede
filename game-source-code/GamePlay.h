#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"
#include "Centipede.h"
#include "CentipedeLogic.h"
#include "Turret.h"
#include "TurretLogic.h"
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
		// Data layer pointer
		DataPtr _data;
		// background sprite
		// sf::Sprite _background;
		// Centipede object shared pointer
		CentPtr _centipede;
		// Centipede logic unique pointer
		CentLogicPtr _centipedeLogic;
		// Turret object pointer
		TurretPtr _turret;
		// Turret Logic pointer
		TurretLogicPtr _turretLogic;
		// track initially spawned centipede segments
		unsigned int _numberOfCentipedeSegments;
		// Input Handler Pointer
		InputHandlerPtr _inputHandler;
		// CollisionHandler pointer
		CollisionHandlerPtr _collisionhandler;
	};
}

#endif