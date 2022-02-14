#include "ground.h"

ground::ground(SDL_Surface* window_surface_ptr) {

  // InitialiZe the window_surface_ptr_ in the class
  this->window_surface_ptr_ = window_surface_ptr;
}

ground::~ground() {
  // Free the dynamic table array
  this->characters.clear();
  // delete &animals;
  SDL_FreeSurface(this->window_surface_ptr_);
}

void ground::update() {
  // The ground gets repainted
  SDL_FillRect(this->window_surface_ptr_, NULL,
               SDL_MapRGB(this->window_surface_ptr_->format, 153, 255, 51));

  // Draw the tombstones of the dead
  for (auto& a : this->characters) {
    if (a->has_attribute("Dead")) {
      a->draw();
    }
    // We still leave interactions possible with dead and alive for revival
    for (auto& b : this->characters) {
      if (a.get() == b.get())
        continue;
      a->interract(*b, b->get_position(), b->get_direction_x(),
                   b->get_direction_y());
    }
  }

  // Draw and handle interractions of all living characters
  for (auto& a : this->characters) {
    if (a->has_attribute("Alive")) {
      for (auto& b : this->characters) {

        if (a.get() == b.get())
          continue;

        a->interract(*b, b->get_position(), b->get_direction_x(),
                     b->get_direction_y());
      }
      a->draw();
      a->move();
      a->update_status();
    }
  }

  this->post_update();
}

void ground::post_update() {

  std::vector<std::unique_ptr<Animal>> newBorns;
  // Add all new animals
  for (auto& a : this->characters) {
    if (a->has_attribute("Pregnant")) {
      if (a->has_attribute("Sheep")) {
        std::unique_ptr<Animal> sheep =
            std::make_unique<Sheep>(this->window_surface_ptr_);
        sheep.get()->add_attribute("Offspring");
        sheep.get()->set_position(a->get_position());
        a->delete_attribute("Pregnant");
        newBorns.push_back(std::move(sheep));
      }
    }
  }
  // Put all the new born
  for (auto& a : newBorns) {
    this->add_character(std::move(a));
  }
}

void ground::event_handler(SDL_Event const& event) {
  for (auto& a : this->characters) {
    if (a->has_attribute("Playable")) {
      a->handle_events(event);
    }
  }
}

void ground::add_character(std::unique_ptr<MovingObject> character) {
  this->characters.push_back(std::move(character));
}
