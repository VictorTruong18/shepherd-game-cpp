#pragma once
#include "../constants.h"
#include "../GameObjects/moving_object.h"

class PlayableCharacter : public MovingObject {
public:
  enum class Direction { NONE, UP, DOWN, LEFT, RIGHT };

  PlayableCharacter(const std::string& file_path,
                    SDL_Surface* window_surface_ptr,double speed, std::set<std::string> properties);
  ~PlayableCharacter();

  void update_status() override;

  void stop();
  
  

protected:
  Direction image_direction;
  int timeWalking;

};