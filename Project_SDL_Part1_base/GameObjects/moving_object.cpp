#include "moving_object.h"

MovingObject::MovingObject(const std::string& file_path, 
                            SDL_Surface* window_surface_ptr,
                            double speed,
                            std::set<std::string> properties) : 
    RenderedObject(file_path,window_surface_ptr,properties){
    this->veloxity_x = arr[rand() % 2];
    this->veloxity_y = arr[rand() % 2];
    this->speed = speed;
}

MovingObject::~MovingObject(){}

float MovingObject::get_direction_x(){
    return this->veloxity_x;
}

float MovingObject::get_direction_y(){
    return this->veloxity_y;
}