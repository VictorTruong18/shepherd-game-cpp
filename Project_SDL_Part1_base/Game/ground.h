#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

#include "../Characters/animal.h"
#include "../Characters/playable_character.h"
#include "../Characters/sheep.h"
#include "../Characters/shepherd.h"
#include "../Characters/bearman.h"
#include "../Characters/shepherd_dog.h"
#include "../Characters/wolf.h"
#include "../constants.h"
#include "../GameObjects/moving_object.h"

// The "ground" on which all the animals live (like the std::vector
// in the zoo example).
class ground {
private:
  // Attention, NON-OWNING ptr, again to the screen
  SDL_Surface* window_surface_ptr_;

  // Some attribute to store all the wolves and sheep
  std::vector<std::unique_ptr<MovingObject>> characters;



public:
  ground(SDL_Surface* window_surface_ptr); // todo: Ctor
  ~ground(); // todo: Dtor, again for clean up (if necessary)
  void add_character(std::unique_ptr<MovingObject> character);
  void update(); // todo: "refresh the screen": Move animals and draw them
                 // Possibly other methods, depends on your implementation
  void post_update(); // another update that will do aditional tasks 
                      // erase all the dead animals, add the new offspring
  void event_handler(SDL_Event const& event); // useful to get keyboard entries 
};