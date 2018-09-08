#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH sf::VideoMode::getDesktopMode().width
#define SCREEN_HEIGHT sf::VideoMode::getDesktopMode().height
#define TURRET_SCREEN_FRACTION 0.6
#define WINDOW_TITLE "Centipede"

#define SPLASH_TIME 3.0
#define SPLASH_BACKGROUND_FILEPATH "Resources\\splashscreenbackground.jpg"

#define MENU_BACKGROUND_FILEPATH "Resources\\menubackground.jpg"
#define GAME_TITLE_FILEPATH "Resources\\title.gif"
#define GAME_SUBTITLE_FILEPATH "Resources\\subtitle.jpg"

#define GAME_BACKGROUND_FILEPATH ""

#define GAME_OVER_BACKGROUND_FILEPATH "Resources\\losebackground.jpg"
#define GAME_WIN_BACKGROUND_FILEPATH "Resources\\winbackground.jpg"
#define PAUSE_FILEPATH "Resources\\gamepaused.png"
#define PAUSE_SPACE_FILEPATH "Resources\\resume.png"

#define SEGMENT_FILEPATH "Resources\\centipedesegment.jpg"
#define BODY_SEGMENT_FILEPATH "Resources\\bodycentipedesegment.jpg"
#define TURRET_FILEPATH "Resources\\turret.jpg"
#define BULLET_FILEPATH "Resources\\bullet.jpg"
#define MUSHROOM_FILEPATH "Resources\\mushroom.jpg"

#define CENTIPEDE_SPRITE_SIDE_SIZE 20
#define CENTIPEDE_SEGMENT_HIT_RADIUS 10
#define TURRET_SPRITE_SIDE_SIZE 20
#define BULLET_WIDTH 8
#define BULLET_HEIGHT 20
#define BULLET_SPEED 1000
#define BULLET_HIT_RADIUS 5
#define TURRET_SPEED 500
#define CENTIPEDE_SPEED 500
#define INITIAL_CENTIPEDE_NUMBER 12
#define MUSHROOMS_SPAWNED 50
#define MUSHROOM_SPRITE_SIZE 20
#define MUSHROOM_HIT_RADIUS 10

#endif