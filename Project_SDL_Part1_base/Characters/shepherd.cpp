#include "shepherd.h"

Shepherd::Shepherd(SDL_Surface* window_surface_ptr_)
    : PlayableCharacter("../media/shepherd.png", window_surface_ptr_,5,std::set<std::string> { "Shepherd", "Alive"}) {}


Shepherd::~Shepherd() {}

void Shepherd::interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition, const float& interractingObjectDirectionX, const float& interractingObjectDirectionY){}

void Shepherd::update_status() {
    
}

void Shepherd::move() {
  int max_height = frame_height - frame_boundary - this->image_ptr_->h;
  int max_width = frame_width - frame_boundary - this->image_ptr_->w;
  switch (image_direction) {
  case Direction::NONE:
    this->veloxity_x += 0.0;
    this->veloxity_y += 0.0;
    break;
  case Direction::UP:
    if (this->image_position_.y >= frame_boundary) {
      this->veloxity_y -= 1;
    } else {
      this->veloxity_x += 0.0;
      this->veloxity_y += 0.0;
    }
    break;
  case Direction::DOWN:
    if (this->image_position_.y <= max_height) {
      this->veloxity_y += 1;
    } else {
      this->veloxity_x += 0.0;
      this->veloxity_y += 0.0;
    }
    break;
  case Direction::LEFT:
    if (this->image_position_.x >= frame_boundary) {
      this->veloxity_x -= 1;
    } else {
      this->veloxity_x += 0.0;
      this->veloxity_y += 0.0;
    }
    break;
  case Direction::RIGHT:
    if (this->image_position_.x <= max_width) {
      this->veloxity_x += 1;
    } else {
      this->veloxity_x += 0.0;
      this->veloxity_y += 0.0;
    }
    break;
  }

  this->image_position_.x = this->veloxity_x * this->speed;
  this->image_position_.y = this->veloxity_y * this->speed;
}

void Shepherd::handle_events(SDL_Event const& event) {

  switch (event.type) {
  case SDL_KEYDOWN:
    Uint8 const* keys = SDL_GetKeyboardState(nullptr);

    if (keys[SDL_SCANCODE_W] == 1) {

      image_direction = Direction::UP;
    } else if (keys[SDL_SCANCODE_S] == 1) {
 
      image_direction = Direction::DOWN;
    } else if (keys[SDL_SCANCODE_A] == 1) {
      image_direction = Direction::LEFT;
    } else if (keys[SDL_SCANCODE_D] == 1) {
      image_direction = Direction::RIGHT;
    } else {
      image_direction = Direction::NONE;
    }
    break;
  }
}