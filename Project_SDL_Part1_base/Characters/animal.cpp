#include "animal.h"



Animal::Animal(const std::string& file_path, SDL_Surface* window_surface_ptr, double speed, std::set<std::string> properties) 
: MovingObject(file_path,window_surface_ptr,speed,properties){

  
}

Animal::~Animal() {
  // Free the surface that has the texture for animals
}


void Animal::move() {
  int max_height = frame_height - frame_boundary - this->image_ptr_->h;
  int max_width = frame_width - frame_boundary - this->image_ptr_->w;

  if (this->image_position_.x <= frame_boundary) {
    this->veloxity_x = -this->veloxity_x;
    this->image_position_.x = frame_boundary;
  }
  if (this->image_position_.x >= max_width) {
    this->veloxity_x = -this->veloxity_x;
    this->image_position_.x = max_width;
  }
  if (this->image_position_.y <= frame_boundary) {
    this->veloxity_y = -this->veloxity_y;
    this->image_position_.y = frame_boundary;
  }

  if (this->image_position_.y >= max_height) {
    this->veloxity_y = -this->veloxity_y;
    this->image_position_.y = max_height;
  }
  this->image_position_.x += this->veloxity_x * this->speed;
  this->image_position_.y += this->veloxity_y * this->speed;
}
