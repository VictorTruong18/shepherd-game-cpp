#pragma once
#include "../constants.h"
#include "rendered_object.h"

class MovingObject : public RenderedObject{
protected:
    float veloxity_x;
    float veloxity_y;
    double speed;

public:
  MovingObject(const std::string& file_path, 
                SDL_Surface* window_surface_ptr,
                double speed, 
                std::set<std::string> properties);
  ~MovingObject();
  virtual void move() = 0;
  
};