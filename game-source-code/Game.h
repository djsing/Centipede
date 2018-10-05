#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "HighScoreManager.h"
#include "KeyboardControlsHandler.h"
#include "LivesHandler.h"
#include "ResourceManager.h"
#include "StateHandler.h"
#include "StopWatch.h"

namespace GameEngine
{
/**
 * @class GameData
 * @author darri
 * @date 27/09/2018
 * @file Game.h
 * @brief Struct containing objects of the Data layer
 * that must be globally accessable for a particular
 * instance of the game, or must persist across multiple
 * instances of the game.
 */
struct GameData
{
    /**
     * @brief Creates an instance of the StateHandler class.
     * Contains the current GameState object, or the current
     * state of the game, defined by the GameState interface
     * class and its derived classes. Has the ability to change
     * or alter the current game state.
     */
    StateHandler statehandler;
    /**
     * @brief Creates an instance of the sf::RenderWindow class.
     * It is through this object that the screen is accessed.
     * The Game loop breaks on the closing of this window.
     */
    sf::RenderWindow window;
    /**
     * @brief Creates an instance of the ResourceManager class.
     * Textures of various game entities are stored in this object.
     * Rendering class uses this object to load various sprites
     * at any point during the game.
     */
    ResourceManager resources;
    /**
     * @brief Creates an instance of the KeyboardControlsHandler class.
     * It is through this object that the keyboard is accessed. Since
     * multiple classes require either the ability to update the user's
     * current push, or performs it's class' operations based on the user's last
     * push must be accessible to all object that need the ability to alter it.
     */
    KeyboardControlsHandler keyboard;
    /**
     * @brief Creates an instance of the LivesHandler class. Contains current
     * number of lives the user has remaining before the game is lost.
     */
    LivesHandler lives;
    /**
     * @brief Creates an instance of the HighScoreManager class. It is through this
     * instance that the score and highscore of the game is updated.
     */
    HighScoreManager score_manager;
};
using DataPtr = std::shared_ptr<GameData>;

class Game
{
   public:
    /**
     * @brief Game Constructor. Called to create an instance of the game.
     */
    Game(int width, int height, std::string windowTitle);

   private:
    /**
     * @brief Frame rate
     * */
    const float dt_ = 1.0f / 120.0f;
    /**
     * @brief Timer which provides the timestep between iterations of
     * the game loop.
     * */
    StopWatch watch_;
    /**
     * @brief Creates an instance of the game Data layer, to which all
     * persisting data elements and globally acessible resources are saved.
     * */
    DataPtr data_ = std::make_shared<GameData>();
    /**
     * @brief Calls the game loop.
     * */
    void Run();
};
}  // namespace GameEngine

#endif
