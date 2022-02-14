#include "animal.h"



Animal::Animal(const std::string& file_path, SDL_Surface* window_surface_ptr, double speed, std::set<std::string> properties) 
: MovingObject(file_path,window_surface_ptr,speed,properties){

  
}

Animal::~Animal() {
  // Free the surface that has the texture for animals
}

void Animal::handle_events(SDL_Event const& event){

}


