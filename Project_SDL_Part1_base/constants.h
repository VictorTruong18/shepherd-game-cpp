#pragma once

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>
#include <set>


namespace collision {
bool isColliding(const SDL_Rect& a, const SDL_Rect& b);
bool isCollidingWithEyesight(const SDL_Rect& a, const SDL_Rect& b, int eyeSightRange);
}

namespace mathOperation {
int round(int n);
}
// Defintions
const double frame_rate = 60.0; // refresh rate
const double frame_time = 1. / frame_rate;
const unsigned frame_width = 1400; // Width of window in pixel
const unsigned frame_height = 900; // Height of window in pixel
// Minimal distance of animals to the border
// of the screen
const unsigned frame_boundary = 50;

const int arr[2] = {-1, 1}; // Direction initializiation
const std::string sex[2] = {"Male", "Female"};

const std::string IMG_SHEEP = "../media/sheep.png";
const std::string IMG_SHEEP_SCARED = "../media/sheep_scared.png";
const std::string IMG_SHEEP_MALE = "../media/sheep_male.png";
const std::string IMG_SHEEP_FEMALE = "../media/sheep_female.png";
const std::string IMG_SHEEP_FEMALE_HORNY = "../media/sheep_female_horny.png";
const std::string IMG_WOLF_DEAD = "../media/wolf_bones.png";
const std::string IMG_SHEEP_DEAD = "../media/sheep_tombstone.png";
const std::string IMG_OFFSPRING = "../media/offspring.png";
const std::string IMG_LAMB = "../media/lamb.png";
const std::string IMG_WOLF = "../media/wolf.png";
const std::string IMG_WOLF_STARVING = "../media/wolf_starving.png";
const std::string IMG_BEARMAN = "../media/bearman.png";
const std::string IMG_SHEPHERD = "../media/shepherd.png";


const int TIME_TO_STARVE_SECONDS_WOLF = 20; // The wolf will go N seconds wihtout eating
const int TIME_TO_STARVE_WOLF = 20 * TIME_TO_STARVE_SECONDS_WOLF;
const int TIME_TO_REPRODUCE_COOLDOWN_SECONDS_SHEEP = 10;
const int TIME_TO_REPRODUCE_COOLDOWN_SHEEP = 20 * TIME_TO_REPRODUCE_COOLDOWN_SECONDS_SHEEP;
const int TIME_TO_GROW_SECONDS_TO_SHEEP = 10;
const int TIME_TO_GROW_TO_SHEEP = 20 * TIME_TO_GROW_SECONDS_TO_SHEEP;

const int EYE_SIGHT_SHEEP = 40;
const int EYE_SIGHT_WOLF = 100;
const int TIME_BOOST_SECOND_SHEEP = 3;
const int TIME_BOOST_SHEEP = 20 * TIME_BOOST_SECOND_SHEEP;

const int TIME_MOVEMENT_SHEPHERD = 25;
const int DOG_WAITING_TIME_SECONDS = 2;
const int DOG_WAITING_TIME = 20 * DOG_WAITING_TIME_SECONDS;

const double AVERAGE_SPEED_PLAYABLE = 5;