#pragma once
#include "../constants.h"


class RenderedObject {
protected:
    SDL_Surface* image_ptr_;
    SDL_Surface* window_surface_ptr_;
    SDL_Rect image_position_;
    SDL_Rect boxCollision_position;
    
public:
  RenderedObject(const std::string& file_path,SDL_Surface* window_surface_ptr);
  ~RenderedObject();
  SDL_Rect get_position();
  SDL_Rect get_boxCollision_position();
  void draw();
};