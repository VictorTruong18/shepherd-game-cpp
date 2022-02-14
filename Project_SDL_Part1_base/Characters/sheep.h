#pragma once
#include "../constants.h"
#include "animal.h"

/**
 * Class Sheep - derived from Animal
 */
class Sheep : public Animal {

private:
  int timeGrowing;
  int timeCooldownGivingBirth;
  int timeBoost;

public:
  /**
   * Method - contructor
   * @param window_surface_ptr_ pointer to SDL_Surface
   */

  Sheep(SDL_Surface* window_surface_ptr_);
  /**
   * Method - detroyer
   */
  ~Sheep();
  // implement functions that are purely virtual in base class

  void interract(InterractingObject& interractingObject,
                 const SDL_Rect& interractingObjectPosition,
                 const float& interractingObjectDirectionX,
                 const float& interractingObjectDirectionY) override;
  void move() override; // todo: Animals move around, but in a different
                        // fashion depending on which type of animal
  void update_status() override;
};