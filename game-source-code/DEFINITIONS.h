#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH sf::VideoMode::getDesktopMode().width
#define SCREEN_HEIGHT sf::VideoMode::getDesktopMode().height
#define WINDOW_TITLE "Centipede"

#define SPLASH_TIME 3.0
#define SPLASH_BACKGROUND_FILEPATH "Resources\\splashscreenbackground.jpg"

#define MENU_BACKGROUND_FILEPATH "Resources\\menubackground.jpg"
#define GAME_TITLE_FILEPATH "Resources\\title.gif"
#define GAME_SUBTITLE_FILEPATH "Resources\\subtitle.jpg"

#define GAME_BACKGROUND_FILEPATH ""

#define GAME_OVER_BACKGROUND_FILEPATH "Resources\\losebackground.jpg"
#define GAME_WIN_BACKGROUND_FILEPATH "Resources\\winbackground.jpg"
#define PAUSE_BACKGROUND_FILEPATH "Resources\\pausebackground.jpg"

#define SEGMENT_FILEPATH "Resources\\centipedesegment.jpg"
#define BODY_SEGMENT_FILEPATH "Resources\\bodycentipedesegment.jpg"

#define CENTIPEDE_SPRITE_SIDE_SIZE 20

#endif