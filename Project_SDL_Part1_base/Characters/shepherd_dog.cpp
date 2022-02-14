#include "shepherd_dog.h"

ShepherdDog::ShepherdDog(SDL_Surface* window_surface_ptr_)
    : Animal("../media/doggo.png", window_surface_ptr_, 1,
             std::set<std::string>{"Dog", "Alive", "Guard", "Playable"}) {
  this->waiting_time = 0;
}

ShepherdDog::~ShepherdDog() {}

void ShepherdDog::interract(InterractingObject& interractingObject,
                            const SDL_Rect& interractingObjectPosition,
                            const float& interractingObjectDirectionX,
                            const float& interractingObjectDirectionY) {
  if (interractingObject.has_attribute("Shepherd")) {
    this->shepherdPosition = interractingObjectPosition;
  }
}

void ShepherdDog::update_status() {}

void ShepherdDog::move() {
  if (!this->has_attribute("Fetch") && !this->has_attribute("Recall")) {
    if (this->angle < 360.00) {
      this->angle += 0.05;
    } else {
      this->angle = 0;
    }
    this->image_position_.x = shepherdPosition.x + cos(this->angle) * 100;
    this->image_position_.y = shepherdPosition.y + sin(this->angle) * 100;
  }

  if (this->has_attribute("Fetch")) {
    this->image_position_.x = mathOperation::round(this->image_position_.x);
    this->image_position_.y = mathOperation::round(this->image_position_.y);
    if (this->image_position_.x < mathOperation::round(this->x)) {
      this->image_position_.x += 10;
    } else if (this->image_position_.x > mathOperation::round(this->x)) {
      this->image_position_.x -= 10;
    }
    if (this->image_position_.y < mathOperation::round(this->y)) {
      this->image_position_.y += 10;
    } else if (this->image_position_.y > mathOperation::round(this->y)) {
      this->image_position_.y -= 10;
    }
    if (this->image_position_.x == mathOperation::round(this->x) &&
        this->image_position_.y == mathOperation::round(this->y)) {

      if (this->waiting_time < DOG_WAITING_TIME) {
        this->waiting_time++;
      } else {
        this->delete_attribute("Fetch");
        this->add_attribute("Recall");
        this->waiting_time = 0;
      }
    }
  }

  if (this->has_attribute("Recall")) {
    this->image_position_.x = mathOperation::round(this->image_position_.x);
    this->image_position_.y = mathOperation::round(this->image_position_.y);
    if (this->image_position_.x <
        mathOperation::round(this->shepherdPosition.x)) {
      this->image_position_.x += 10;
    } else if (this->image_position_.x >
               mathOperation::round(this->shepherdPosition.x)) {
      this->image_position_.x -= 10;
    }
    if (this->image_position_.y <
        mathOperation::round(this->shepherdPosition.y)) {
      this->image_position_.y += 10;
    } else if (this->image_position_.y >
               mathOperation::round(this->shepherdPosition.y)) {
      this->image_position_.y -= 10;
    }

    if (this->image_position_.y ==
            mathOperation::round(this->shepherdPosition.y) &&
        this->image_position_.x ==
            mathOperation::round(this->shepherdPosition.x)) {
      this->delete_attribute("Recall");
    }
  }
}

void ShepherdDog::handle_events(SDL_Event const& event) {
  switch (event.button.button) {

  case SDL_BUTTON_LEFT:
    int x, y;
    SDL_GetMouseState(&x, &y);
    this->x = x;
    this->y = y;
    this->add_attribute("Fetch");
    this->delete_attribute("Recall");
    break;
  case SDL_BUTTON_RIGHT:
    this->x = x;
    this->y = y;
    this->add_attribute("Recall");
    this->delete_attribute("Fetch");
    break;
  }
}
