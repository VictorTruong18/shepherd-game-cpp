#include "ground.h"

ground::ground(SDL_Surface* window_surface_ptr) {

  // InitialiZe the window_surface_ptr_ in the class
  this->window_surface_ptr_ = window_surface_ptr;
}

ground::~ground() {
  // Free the dynamic table array
  this->animals.clear();
  // delete &animals;
}

void ground::add_animal(std::unique_ptr<Animal> animal) {
  // Add the type animal to the dynamic array
  this->animals.push_back(std::move(animal));
}



void ground::update() {
  // The ground gets repainted
  SDL_FillRect(this->window_surface_ptr_, NULL,
               SDL_MapRGB(this->window_surface_ptr_->format, 153, 255, 51));

  for (auto& a : this->animals) {
    a->draw();
    a->move();
    for (auto& b : this->animals) {

      if (a.get() == b.get())
        continue;
        
      a->interract(*b,b->get_position());
    }
  }

  this->post_update();
}

void ground::post_update(){

  std::vector<std::unique_ptr<Animal>> newBorns;
  //Add all new animals
  for (auto& a : this->animals) {
    if(a->has_attribute("Pregnant")){
        if(a->has_attribute("Sheep")){
         std::unique_ptr<Animal> sheep = std::make_unique<Sheep>(this->window_surface_ptr_);
         sheep.get()->add_attribute("Offspring");
         sheep.get()->set_position(a->get_position());
         a->delete_attribute("Pregnant");
         newBorns.push_back(std::move(sheep));
        }
    }
  }

  //Put all the new born
  for(auto& a : newBorns){
    this->add_animal(std::move(a));
  }
}