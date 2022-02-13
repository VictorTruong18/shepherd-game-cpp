#include "moving_object.h"

MovingObject::MovingObject(const std::string& file_path, SDL_Surface* window_surface_ptr,double speed) : 
    RenderedObject(file_path,window_surface_ptr){
    this->veloxity_x = arr[rand() % 2];
    this->veloxity_y = arr[rand() % 2];
    this->speed = speed;
}

MovingObject::~MovingObject(){}