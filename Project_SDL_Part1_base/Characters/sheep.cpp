#include "sheep.h"

Sheep::Sheep(SDL_Surface* window_surface_ptr_)
    : Animal("../media/sheep.png", window_surface_ptr_,1) {
  this->speed = 1;
}

Sheep::~Sheep() {}