#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SFML/Graphics.hpp>
#include <cmath>
const double PI = 4*atan(1);

#define SCREEN_WIDTH sf::VideoMode::getDesktopMode().width
#define SCREEN_HEIGHT sf::VideoMode::getDesktopMode().height
#define SCREEN_LHS 0
#define SCREEN_TOP 0
#define SCREEN_HEIGHT_BUFFER_FACTOR 2
#define TURRET_SCREEN_FRACTION 0.75
#define WINDOW_TITLE "Centipede"

#define SPLASH_TIME 3.0
#define SPLASH_BACKGROUND_FILEPATH "Resources\\splashscreenbackground.jpg"

#define MENU_BACKGROUND_FILEPATH "Resources\\menubackground.jpg"
#define GAME_TITLE_FILEPATH "Resources\\title.gif"
#define GAME_SUBTITLE_FILEPATH "Resources\\subtitle.jpg"

#define GAME_BACKGROUND_FILEPATH ""

#define GAME_OVER_BACKGROUND_FILEPATH "Resources\\losebackground.jpg"
#define GAME_WIN_BACKGROUND_FILEPATH "Resources\\winbackground.jpg"
#define GAME_WON "Resources\\youwin.png"
#define PAUSE_FILEPATH "Resources\\gamepaused.png"
#define PAUSE_SPACE_FILEPATH "Resources\\resume.png"
#define GAME_OVER_FILEPATH "Resources\\gameover.png"
#define GAME_OVER_RESTART_FILEPATH "Resources\\gamerestart.png"
#define GAME_WIN_RESTART_FILEPATH "Resources\\gamerestart.png"
#define GAME_INSTRUCTIONS "Resources\\instructions.png"

#define SEGMENT_FILEPATH "Resources\\centipedesegment.jpg"
#define BODY_SEGMENT_FILEPATH "Resources\\bodycentipedesegment.png"
#define TURRET_FILEPATH "Resources\\turret.png"
#define BULLET_FILEPATH "Resources\\bullet.jpg"
#define MUSHROOM_FILEPATH "Resources\\mushroom.png"
#define POISONED_MUSHROOM_FILEPATH "Resources\\mushroompoisoned.png"
#define SPIDER_FILEPATH "Resources\\spider.png"
#define SCORPION_FILEPATH "Resources\\scorpion.png"

#define CENTIPEDE_SPRITE_SIDE_SIZE 20
#define CENTIPEDE_SEGMENT_HIT_RADIUS 10
#define TURRET_SPRITE_SIDE_SIZE 20
#define TURRET_HIT_RADIUS 10
#define BULLET_WIDTH 8
#define BULLET_HEIGHT 20
#define BULLET_SPEED 2000
#define BULLET_HIT_RADIUS 5
#define TURRET_SPEED 500
#define CENTIPEDE_SPEED 800
#define INITIAL_CENTIPEDE_NUMBER 12
#define MUSHROOMS_SPAWNED 50
#define MUSHROOM_SPRITE_SIZE 20
#define MUSHROOM_HIT_RADIUS 10
#define SPIDER_SPRITE_SIZE 20
#define SPIDER_HIT_RADIUS 10
#define SPIDER_SPEED 500
#define SPIDER_MOVEMENT_TIME 1
#define SCORPION_MOVEMENT_TIME 1
#define SCORPION_SPRITE_SIZE 20
#define SCORPION_HIT_RADIUS 10
#define SCORPION_SPEED 500

#endif