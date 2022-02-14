#pragma once
#include "playable_character.h"
#include "../constants.h"


class Bearman : public PlayableCharacter {
public:
  Bearman(SDL_Surface* window_surface_ptr);
  ~Bearman();
    
    void interract(InterractingObject& interractingObject,
                    const SDL_Rect&  interractingObjectPosition, 
                    const float& interractingObjectDirectionX, 
                    const float& interractingObjectDirectionY) override;
    void handle_events(SDL_Event const& event) override;
};