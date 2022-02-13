#pragma once
#include "pet.h"

/**
 * Class ShepherdDog - derived from Animal
 */
class ShepherdDog : public Pet {
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
};