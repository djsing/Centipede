#ifndef STATERENDERER_H
#define STATERENDERER_H

#include <SFML/Graphics.hpp>
#include "Game.h"

namespace GameEngine
{
/**
 * @class StateRenderer
 * @author Darrion Singh and Sachin Govender
 * @date 05/10/2018
 * @file StateRenderer.h
 * @brief Handles all rendering not related to Entity objects.
 */
class StateRenderer
{
   public:
    /**
     * @brief StateRenderer Constructor
     */
    StateRenderer(DataPtr data);
    /**
     * @brief Draws HighScore to the Screen.
     */
    void DisplayHighScore();
    /**
     * @brief Displays game-winning screen.
     */
    void DisplayWin();
    /**
     * @brief Displays game-losing screen.
     */
    void DisplayLoss();
    /**
     * @brief Displays main menu.
     */
    void DisplayMenu();
    /**
     * @brief Displays the splash screen.
     */
    void DisplaySplashScreen();

   private:
    DataPtr data_;
    // State-specific sprites
    sf::Sprite game_over_;
    sf::Sprite game_won_;
    sf::Sprite press_f12_to_restart_;
    sf::Sprite title_;
    sf::Sprite subtitle_;
    sf::Sprite instructions_;
    sf::Sprite background_;
	sf::Sprite score_digit_;
};
using StateRenderPtr = std::shared_ptr<StateRenderer>;
}  // namespace GameEngine

#endif