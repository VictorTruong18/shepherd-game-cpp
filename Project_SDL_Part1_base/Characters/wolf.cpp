#include "wolf.h"

Wolf::Wolf(SDL_Surface* window_surface_ptr_)
    : Animal(IMG_WOLF, window_surface_ptr_, 2.3,
             std::set<std::string>{"Wolf", "Alive", "Predator"}) {
  this->withoutEatingTime = 0;
}

Wolf::~Wolf() {}

void Wolf::interract(InterractingObject& interractingObject,
                     const SDL_Rect& interractingObjectPosition,
                     const float& interractingObjectDirectionX,
                     const float& interractingObjectDirectionY) {
  if (collision::isColliding(this->get_position(),
                             interractingObjectPosition)) {
    if (interractingObject.has_attribute("Prey") &&
        this->has_attribute("Alive") &&
        interractingObject.has_attribute("Alive")) {
      this->withoutEatingTime =
          0; // Wolf feeds so his without eating time go back to 0
      this->modify_picture(IMG_WOLF);
    }

    if (interractingObject.has_attribute("Bearman") &&
        this->has_attribute("Dead") &&
        interractingObject.has_attribute("Alive")) {
      this->withoutEatingTime =
          0; // Wolf feeds so his without eating time go back to 0
      this->modify_picture(IMG_WOLF);
      this->replace_attribute("Dead", "Alive");
    }
  }
  // Clostest prey for the wolf reach
  if (collision::isCollidingWithEyesight(
          this->get_position(), interractingObjectPosition, EYE_SIGHT_WOLF)) {
    if (interractingObject.has_attribute("Prey") &&
        this->has_attribute("Alive") &&
        interractingObject.has_attribute("Alive")) {
      if (this->image_position_.x < interractingObjectPosition.x) {
        this->image_position_.x += 1;
      } else {
        this->image_position_.x -= 1;
      }
      if (this->image_position_.y < interractingObjectPosition.y) {
        this->image_position_.y += 1;
      } else {
        this->image_position_.y -= 1;
      }
    }
    // Guard animal on sight
    if (interractingObject.has_attribute("Guard") &&
        this->has_attribute("Alive") &&
        interractingObject.has_attribute("Alive")) {
      if (this->image_position_.x < interractingObjectPosition.x) {
        this->image_position_.x -= 20;
      } else {
        this->image_position_.x += 20;
      }
      if (this->image_position_.y < interractingObjectPosition.y) {
        this->image_position_.y -= 20;
      } else {
        this->image_position_.y += 20;
      }
    }
  }
}

void Wolf::update_status() {
  this->withoutEatingTime++;
  if (this->withoutEatingTime > TIME_TO_STARVE_WOLF &&
      this->has_attribute("Alive")) {
    this->replace_attribute("Alive", "Dead");
    this->modify_picture(IMG_WOLF_DEAD);
  }
  if (this->withoutEatingTime > TIME_TO_STARVE_WOLF * 0.8 &&
      this->has_attribute("Alive")) {
    if (this->withoutEatingTime % 3 == 0) {
      this->modify_picture(IMG_WOLF_STARVING);
    } else {
      this->modify_picture(IMG_WOLF);
    }
  }
}

void Wolf::move() {
  if (this->has_attribute("Alive")) {
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
}