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

protected:
  SDL_Surface* image_ptr_; // The texture of the sheep (the loaded image), use
                           // load_surface_for
  // todo: Attribute(s) to define its position
  SDL_Rect image_position;

  

public:
  /**
   * todo: The constructor has to load the sdl_surface that corresponds to the
   * texture
   */
  Animal(const std::string& file_path, SDL_Surface* window_surface_ptr, double speed);
  /**
   * todo: Use the destructor to release memory and "clean up behind you"
   *
   */
  ~Animal();
  void draw(); // todo: Draw the animal on the screen <-> window_surface_ptr.
               // Note that this function is not virtual, it does not depend
               // on the static type of the instance

  void move() override; // todo: Animals move around, but in a different
                       // fashion depending on which type of animal
};