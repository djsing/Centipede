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
     * @brief Displays pause screen.
     */
    void DisplayPause();
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
    sf::Sprite game_paused_;
    sf::Sprite press_enter_to_resume_;
    sf::Sprite resume_background_sprite_;
    sf::Texture resume_background_;
	sf::Sprite press_enter_to_pause_;
	sf::Sprite high_score_;
	sf::Sprite new_high_score_;
    // file paths
    const std::string SPLASH_BACKGROUND_FILEPATH_ = "Resources\\splashscreenbackground.jpg";
    const std::string GAME_TITLE_FILEPATH_ = "Resources\\title.gif";
    const std::string GAME_SUBTITLE_FILEPATH_ = "Resources\\subtitle.jpg";
    const std::string GAME_WON_ = "Resources\\youwin.png";
    const std::string PAUSE_FILEPATH_ = "Resources\\gamepaused.png";
    const std::string PAUSE_ENTER_FILEPATH_ = "Resources\\resume.png";
    const std::string GAME_OVER_FILEPATH_ = "Resources\\gameover.png";
    const std::string GAME_OVER_RESTART_FILEPATH_ = "Resources\\gamerestart.png";
    const std::string GAME_WIN_RESTART_FILEPATH_ = "Resources\\gamerestart.png";
    const std::string GAME_INSTRUCTIONS_ = "Resources\\instructions.png";
    const std::string PRESS_ENTER_TO_PAUSE_FILEPATH_ = "Resources\\pause.png";
    const std::string HIGHSCORE_FILEPATH_ = "Resources\\highscore.png";
    const std::string NEW_HIGHSCORE_FILEPATH_ = "Resources\\newhighscore.png";
};
using StateRenderPtr = std::shared_ptr<StateRenderer>;
}  // namespace GameEngine

#endif