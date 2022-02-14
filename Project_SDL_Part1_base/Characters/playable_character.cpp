#include "playable_character.h"

PlayableCharacter::~PlayableCharacter() {}

PlayableCharacter::PlayableCharacter(const std::string& file_path,
                                     SDL_Surface* window_surface_ptr,
                                     double speed,
                                     std::set<std::string> properties)
    : MovingObject(file_path, window_surface_ptr, 5, properties) {
  this->timeWalking = 0;
}

void PlayableCharacter::stop() { image_direction = Direction::NONE; }

void PlayableCharacter::move() {
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

void PlayableCharacter::update_status() {

  if (this->timeWalking > TIME_MOVEMENT_SHEPHERD) {
    this->stop();
  } else {
    this->timeWalking++;
  }
}