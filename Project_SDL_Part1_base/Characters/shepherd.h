#pragma once
#include "../constants.h"
#include "playable_character.h"

class Shepherd : public PlayableCharacter {
public:
  Shepherd(SDL_Surface* window_surface_ptr);
  ~Shepherd();

  void interract(InterractingObject& interractingObject,
                 const SDL_Rect& interractingObjectPosition,
                 const float& interractingObjectDirectionX,
                 const float& interractingObjectDirectionY) override;

  void handle_events(SDL_Event const& event) override;
};