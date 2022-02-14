#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>
#include <set>


namespace collision {
bool isColliding(const SDL_Rect& a, const SDL_Rect& b);
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
const std::string IMG_SHEEP_MALE = "../media/sheep_male.png";
const std::string IMG_SHEEP_FEMALE = "../media/sheep_female.png";
const std::string IMG_SHEEP_FEMALE_HORNY = "../media/sheep_female_horny.png";