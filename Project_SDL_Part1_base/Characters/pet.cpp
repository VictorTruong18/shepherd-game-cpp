#include "pet.h"

Pet::Pet(SDL_Surface* window_surface_ptr_, std::string picture_path)
    : Animal(picture_path, window_surface_ptr_,1, std::set<std::string> { "Dog"}) {
  this->speed = 1;
}

Pet::~Pet() {}

void Pet::move(SDL_Rect shepherdPosition){
  if(this->angle < 360.00){
    this->angle += 0.05;
  } else {
    this->angle = 0;
  }
  this->image_position_.x = shepherdPosition.x + cos(this->angle)*100;
  this->image_position_.y = shepherdPosition.y + sin(this->angle)*100;
}