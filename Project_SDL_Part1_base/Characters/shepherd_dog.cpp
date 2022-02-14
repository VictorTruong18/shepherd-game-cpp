#include "shepherd_dog.h"

ShepherdDog::ShepherdDog(SDL_Surface* window_surface_ptr_)
    : Animal("../media/doggo.png", window_surface_ptr_,1,  std::set<std::string> { "Dog", "Alive", "Guard"}) {
} 

ShepherdDog::~ShepherdDog() {}

void ShepherdDog::interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition, const float& interractingObjectDirectionX, const float& interractingObjectDirectionY){
  if(interractingObject.has_attribute("Shepherd")){
    this->shepherdPosition = interractingObjectPosition;
  }
}

void ShepherdDog::update_status(){
  
}

void ShepherdDog::move(){
  if(this->angle < 360.00){
    this->angle += 0.05;
  } else {
    this->angle = 0;
  }
  this->image_position_.x = shepherdPosition.x + cos(this->angle)*100;
  this->image_position_.y = shepherdPosition.y + sin(this->angle)*100;
}