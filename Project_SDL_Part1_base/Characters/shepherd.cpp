#include "shepherd.h"

Shepherd::Shepherd(SDL_Surface* window_surface_ptr_)
    : PlayableCharacter("../media/shepherd.png", window_surface_ptr_,5,std::set<std::string> { "Shepherd"}) {}


Shepherd::~Shepherd() {}