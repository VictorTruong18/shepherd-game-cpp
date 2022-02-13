#pragma once
#include "animal.h"
#include <cmath>

/**
 * Class Sheep - derived from Animal
 */
class Pet : public Animal {
public:
  /**
   * Method - contructor
   * @param window_surface_ptr_ pointer to SDL_Surface
   */
  Pet(SDL_Surface* window_surface_ptr_, std::string picture_path);
  /**
   * Method - detroyer
   */
  ~Pet();
  // implement functions that are purely virtual in base class
  void move(SDL_Rect shepherdPosition);
private:
  float angle = 0;
};