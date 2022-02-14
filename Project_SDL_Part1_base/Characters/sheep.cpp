#include "sheep.h"



Sheep::Sheep(SDL_Surface* window_surface_ptr_)
    : Animal(IMG_SHEEP, window_surface_ptr_,1, std::set<std::string> { "Sheep", "Alive", "Prey", sex[rand() % 2], "Horny"}) {
  if(this->has_attribute("Female") && this->has_attribute("Horny")){
    this->modify_picture(IMG_SHEEP_FEMALE_HORNY);
  }
  if(this->has_attribute("Male")){
    this->modify_picture(IMG_SHEEP_MALE);
  }
}

Sheep::~Sheep() {}

void Sheep::interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition){
  //There is a physical collision
  if(collision::isColliding(this->get_position(),interractingObjectPosition)){
    //If the Sheep meets a Predator
    if(interractingObject.has_attribute("Predator")){
      this->replace_attribute("Alive","Dead");  
    }
    //If the Female Sheep meets a male Sheep
    if(this->has_attribute("Female") &&  this->has_attribute("Horny") && !this->has_attribute("Offspring") &&
      (interractingObject.has_attribute("Male") && interractingObject.has_attribute("Sheep"))){
      this->add_attribute("Pregnant"); 
      this->delete_attribute("Horny");
      this->modify_picture(IMG_SHEEP_FEMALE);
    }
    
  }
}
