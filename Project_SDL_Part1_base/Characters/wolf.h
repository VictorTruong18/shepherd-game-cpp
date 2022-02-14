#pragma once
#include "animal.h"

/**
 * class Wolf
 * method - constructor
 */
class Wolf : public Animal {
private:
  int withoutEatingTime;

public:
  // Ctor
  Wolf(SDL_Surface* window_surface_ptr_);
  // Dtor
  ~Wolf();
  void interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition, const float& interractingObjectDirectionX, const float& interractingObjectDirectionY) override;
  void update_status() override;
};