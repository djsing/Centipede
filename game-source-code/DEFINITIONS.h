#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SFML/Graphics.hpp>
#include <cmath>

// game characteristics
const float PI = 4 * atan(1);
const float SCREEN_WIDTH = sf::VideoMode::getDesktopMode().width / 3;
const float SCREEN_HEIGHT = sf::VideoMode::getDesktopMode().height * 0.95;
const auto SCREEN_LHS = 0;
const auto SCREEN_TOP = 40;
const auto WINDOW_TOP = 0;
const auto SCREEN_HEIGHT_BUFFER_FACTOR = 2;
const auto TURRET_SCREEN_FRACTION = 0.65;
const auto SCORPION_STARTING_Y_POSITION_FRACTION = 0.25;
const auto WINDOW_TITLE = "Centipede";
const auto SPLASH_TIME = 3.0;

// general sprite filepaths
const auto SPLASH_BACKGROUND_FILEPATH = "Resources\\splashscreenbackground.jpg";
const auto GAME_TITLE_FILEPATH = "Resources\\title.gif";
const auto GAME_SUBTITLE_FILEPATH = "Resources\\subtitle.jpg";
const auto GAME_WON = "Resources\\youwin.png";
const auto PAUSE_FILEPATH = "Resources\\gamepaused.png";
const auto PAUSE_SPACE_FILEPATH = "Resources\\resume.png";
const auto GAME_OVER_FILEPATH = "Resources\\gameover.png";
const auto GAME_OVER_RESTART_FILEPATH = "Resources\\gamerestart.png";
const auto GAME_WIN_RESTART_FILEPATH = "Resources\\gamerestart.png";
const auto GAME_INSTRUCTIONS = "Resources\\instructions.png";
const auto NUMBER_0 = "Resources\\0.png";
const auto NUMBER_1 = "Resources\\1.png";
const auto NUMBER_2 = "Resources\\2.png";
const auto NUMBER_3 = "Resources\\3.png";
const auto NUMBER_4 = "Resources\\4.png";
const auto NUMBER_5 = "Resources\\5.png";
const auto NUMBER_6 = "Resources\\6.png";
const auto NUMBER_7 = "Resources\\7.png";
const auto NUMBER_8 = "Resources\\8.png";
const auto NUMBER_9 = "Resources\\9.png";
// entity sprite filepaths
const auto SEGMENT_FILEPATH = "Resources\\centipedesegment.png";
const auto BODY_SEGMENT_FILEPATH = "Resources\\bodycentipedesegment.png";
const auto TURRET_FILEPATH = "Resources\\turret.png";
const auto BULLET_FILEPATH = "Resources\\bullet.jpg";
const auto MUSHROOM_FILEPATH = "Resources\\mushroom.png";
const auto MUSHROOM3_FILEPATH = "Resources\\mushroom3lives.png";
const auto POISONED_MUSHROOM_FILEPATH = "Resources\\mushroompoisoned.png";
const auto SPIDER_FILEPATH = "Resources\\spider.png";
const auto SCORPION_FILEPATH = "Resources\\scorpion.png";
const auto HEART_FILEPATH = "Resources\\lives.png";
const auto BOMB_FILEPATH = "Resources\\bomb.png";
const auto EXPLOSION_FILEPATH = "Resources\\explosion.png";
// Other filepaths
const auto HIGHSCORE_FILEPATH = "Resources\\HighScore.txt";

// entity-specific characteristics
const auto BOMB_SPRITE_SIZE = 20.f;
const auto CENTIPEDE_SPRITE_SIDE_SIZE = 20.f;
const auto CENTIPEDE_SEGMENT_HIT_RADIUS = 9.f;
const auto TURRET_SPRITE_SIDE_SIZE = 20.f;
const auto TURRET_HIT_RADIUS = 9.f;
const auto BULLET_WIDTH = 8.f;
const auto BULLET_HEIGHT = 20.f;
const auto BULLET_SPEED = 1000.f;
const auto BULLET_HIT_RADIUS = 9.f;
const auto TURRET_SPEED = 300.f;
const auto CENTIPEDE_SPEED = 400.f;
const auto INITIAL_CENTIPEDE_NUMBER = 12;
const auto MUSHROOMS_SPAWNED = 40;
const auto BOMBS_SPAWNED = 4;
const auto MUSHROOM_SPRITE_SIZE = 20.f;
const auto MUSHROOM_HIT_RADIUS = 9.f;
const auto SPIDER_SPRITE_SIZE = 20.f;
const auto SPIDER_HIT_RADIUS = 9.f;
const auto SPIDER_SPEED = 400.f;
const auto SPIDER_MOVEMENT_TIME = 1;
const auto SCORPION_MOVEMENT_TIME = 2;
const auto SCORPION_SPRITE_SIZE = 20.f;
const auto SCORPION_HIT_RADIUS = 9.f;
const auto SCORPION_SPEED = 400.f;
const auto HEART_SIZE = 20.f;
const auto STARTING_LIVES = 3;
const auto SPIDER_BITE_DEATH_CHANCE = 5;
const auto SPIDER_TIME = 2;
const auto BOMB_HIT_RADIUS = 9.f;
const auto EXPLOSION_SPRITE_SIZE = 100.f;
const auto EXPLOSION_HIT_RADIUS = 50.f;
const auto EXPLOSION_TIME = 2;
const auto BOMB_MOVE_TIME = 4;
const auto NUMBER_SIZE = 20;

const auto SEGMENT_SCORE = 10;
const auto SPIDER_SCORE = 20;
const auto SCORPION_SCORE = 50;
const auto MUSHROOM_SCORE = 5;
const auto PLAYER_DEATH_SCORE_LOSS = 100;

#endif
