#include "shepherd_dog.h"

ShepherdDog::ShepherdDog(SDL_Surface* window_surface_ptr_)
    : Pet(window_surface_ptr_, "../media/doggo.png") {
  this->speed = 1;
}

ShepherdDog::~ShepherdDog() {}

void ShepherdDog::interract(){}