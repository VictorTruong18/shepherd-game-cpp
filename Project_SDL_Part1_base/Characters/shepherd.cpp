#include "shepherd.h"

Shepherd::Shepherd(SDL_Surface* window_surface_ptr_)
    : PlayableCharacter(
          IMG_SHEPHERD, window_surface_ptr_, AVERAGE_SPEED_PLAYABLE,
          std::set<std::string>{"Shepherd", "Alive", "Playable"}) {}

Shepherd::~Shepherd() {}

void Shepherd::interract(InterractingObject& interractingObject,
                         const SDL_Rect& interractingObjectPosition,
                         const float& interractingObjectDirectionX,
                         const float& interractingObjectDirectionY) {}

void Shepherd::handle_events(SDL_Event const& event) {

  switch (event.type) {
  case SDL_KEYDOWN:
    Uint8 const* keys = SDL_GetKeyboardState(nullptr);

    if (keys[SDL_SCANCODE_Z] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::UP;
    } else if (keys[SDL_SCANCODE_S] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::DOWN;
    } else if (keys[SDL_SCANCODE_Q] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::LEFT;
    } else if (keys[SDL_SCANCODE_D] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::RIGHT;
    } else {
      image_direction = Direction::NONE;
    }
    break;
  }
}