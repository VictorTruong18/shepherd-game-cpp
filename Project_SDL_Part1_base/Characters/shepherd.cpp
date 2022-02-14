#include "shepherd.h"

Shepherd::Shepherd(SDL_Surface* window_surface_ptr_)
    : PlayableCharacter("../media/shepherd.png", window_surface_ptr_,5,std::set<std::string> { "Shepherd", "Alive"}) {}


Shepherd::~Shepherd() {}

void Shepherd::interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition, const float& interractingObjectDirectionX, const float& interractingObjectDirectionY){}

void Shepherd::update_status() {
    
}