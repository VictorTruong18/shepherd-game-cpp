#pragma once
#include "animal.h"

/**
 * Class ShepherdDog - derived from Animal
 */
class ShepherdDog : public Animal {
public:
  /**
   * Method - contructor
   * @param window_surface_ptr_ pointer to SDL_Surface
   */
  ShepherdDog(SDL_Surface* window_surface_ptr_);
  /**
   * Method - detroyer
   */
  ~ShepherdDog();
  // implement functions that are purely virtual in base class
  SDL_Rect shepherdPosition;
  float angle;

  void interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition, const float& interractingObjectDirectionX, const float& interractingObjectDirectionY) override;
  void update_status() override;
  void move() override; 
};