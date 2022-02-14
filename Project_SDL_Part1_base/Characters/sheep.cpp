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
    if(interractingObject.has_attribute("Predator") && interractingObject.has_attribute("Alive") && this->has_attribute("Alive")){
      interractingObject.interract(*this, this->get_position());
      this->replace_attribute("Alive","Dead");
      this->modify_picture(IMG_SHEEP_DEAD);
    }
    //If the Female Sheep meets a male Sheep
    if(this->has_attribute("Female") &&  this->has_attribute("Horny") && !this->has_attribute("Offspring") && this->has_attribute("Alive") &&
      (interractingObject.has_attribute("Male") && interractingObject.has_attribute("Sheep") && interractingObject.has_attribute("Alive"))){
      this->add_attribute("Pregnant"); 
      this->delete_attribute("Horny");
      this->modify_picture(IMG_SHEEP_FEMALE);
    }
    
  }
}

void Sheep::update_status(){
  this->image_ptr_->clip_rect.x = 10 ;
  this->image_ptr_->clip_rect.y = 10 ;
  this->image_ptr_->clip_rect.w = 10 ;
  this->image_ptr_->clip_rect.h = 10 ;
}
