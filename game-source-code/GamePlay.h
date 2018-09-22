#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"
#include "EntityLogic.h"
#include "EntityRendering.h"
#include "Centipede.h"
#include "Turret.h"
#include "InputHandler.h"
#include "CollisionHandler.h"
#include "GameField.h"

namespace GameEngine
{
	class GamePlay: public GameState
	{
	public:
		GamePlay(DataPtr data);
		~GamePlay();

		void HandleInput() override;
		void Update(float dt) override;
		void Draw() override;

	private:
		// Data layer pointer
		DataPtr _data;
		// background sprite
		// sf::Sprite _background;
		// Centipede object shared pointer
		CentPtr _centipede;
		// Centipede logic unique pointer
		LogicPtr _centipedeLogic;
		// Centipede Renderer pointer
		RenderPtr _centipedeRenderer;
		// Turret object pointer
		TurretPtr _turret;
		// Turret Logic pointer
		LogicPtr _turretLogic;
		// Turret Renderer pointer
		RenderPtr _turretRenderer;
		// Mushroom Logic Pointer
		LogicPtr _mushLogicPtr;
		// Mushroom Renderer pointer
		RenderPtr _mushRenderer;
		// Spider Logic pointer
		LogicPtr _spiderLogic;
		// Spider Render pointer
		RenderPtr _spiderRenderer;
		// Spider Logic pointer
		LogicPtr _scorpionLogic;
		// Spider Render pointer
		RenderPtr _scorpionRenderer;
		// Input Handler Pointer
		InputHandlerPtr _inputHandler;
		// CollisionHandler pointer
		CollisionHandlerPtr _collisionhandler;
		// Game field pointer
		FieldPtr _field;
	};
}

#endif