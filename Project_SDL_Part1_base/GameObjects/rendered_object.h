#pragma once
#include "../constants.h"
#include "interracting_object.h"

class RenderedObject : public InterractingObject {
protected:
  SDL_Surface* image_ptr_;
  SDL_Surface* window_surface_ptr_;
  SDL_Rect image_position_;
  SDL_Rect boxCollision_position;

public:
  RenderedObject(const std::string& file_path, SDL_Surface* window_surface_ptr,
                 std::set<std::string> properties);
  ~RenderedObject();
  SDL_Rect get_position();
  SDL_Rect get_boxCollision_position();
  void modify_picture(const std::string& file_path);
  void set_position(SDL_Rect position);
  void draw();
};