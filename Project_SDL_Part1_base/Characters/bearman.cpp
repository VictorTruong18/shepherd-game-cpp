#include "bearman.h"

Bearman::Bearman(SDL_Surface* window_surface_ptr_)
    : PlayableCharacter(IMG_BEARMAN, window_surface_ptr_,AVERAGE_SPEED_PLAYABLE,std::set<std::string> { "Bearman", "Alive", "Playable", "Predator"}) {}


Bearman::~Bearman() {}

void Bearman::interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition, const float& interractingObjectDirectionX, const float& interractingObjectDirectionY){}

void Bearman::handle_events(SDL_Event const& event) {

  switch (event.type) {
  case SDL_KEYDOWN:
    Uint8 const* keys = SDL_GetKeyboardState(nullptr);

    if (keys[SDL_SCANCODE_UP] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::UP;
    } else if (keys[SDL_SCANCODE_DOWN] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::DOWN;
    } else if (keys[SDL_SCANCODE_LEFT] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::LEFT;
    } else if (keys[SDL_SCANCODE_RIGHT] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::RIGHT;
    } else {
      image_direction = Direction::NONE;
    }
    break;
  }
}