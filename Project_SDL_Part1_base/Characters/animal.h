#pragma once

#include "../constants.h"
#include "../GameObjects/moving_object.h"
/**
 * Class Animal
 */
class Animal : public MovingObject{
private:
  SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the
                                    // animal to be drawn, also non-owning


  

public:
  /**
   * todo: The constructor has to load the sdl_surface that corresponds to the
   * texture
   */
  Animal(const std::string& file_path, SDL_Surface* window_surface_ptr, double speed, std::set<std::string> properties);
  /**
   * todo: Use the destructor to release memory and "clean up behind you"
   *
   */
  ~Animal();


  void move() override; // todo: Animals move around, but in a different
                       // fashion depending on which type of animal
};