#include "wolf.h"



Wolf::Wolf(SDL_Surface* window_surface_ptr_)
    : Animal("../media/wolf.png", window_surface_ptr_,1, std::set<std::string> { "Wolf","Alive", "Predator"}) {
  this->speed = 2.3;
}

Wolf::~Wolf() {}

void Wolf::interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition){
 
  
}