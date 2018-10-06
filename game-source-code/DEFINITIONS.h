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
const auto EXPLOSION_TIME = 1;
const auto BOMB_MOVE_TIME = 2;
const auto NUMBER_SIZE = 20;

// game characteristics
const auto SEGMENT_SCORE = 10;
const auto SPIDER_SCORE = 20;
const auto SCORPION_SCORE = 50;
const auto MUSHROOM_SCORE = 5;
const auto PLAYER_DEATH_SCORE_LOSS = 50;

#endif
