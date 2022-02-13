#pragma once
#include "../constants.h"
#include "pet.h"
#include "../GameObjects/moving_object.h"

class PlayableCharacter : public MovingObject {
public:
  enum class Direction { NONE, UP, DOWN, LEFT, RIGHT };

  PlayableCharacter(const std::string& file_path,
                    SDL_Surface* window_surface_ptr,double speed, std::set<std::string> properties);
  ~PlayableCharacter();

  void handle_events(SDL_Event const& event);
  void move() override;
  void stop();
  void petUpdate();
  void addPet(std::unique_ptr<Pet> pet);

private:
  Direction image_direction;

  double speed = 5;
  std::unique_ptr<Pet> pet;
};