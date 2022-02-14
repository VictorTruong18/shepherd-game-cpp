#include "wolf.h"



Wolf::Wolf(SDL_Surface* window_surface_ptr_)
    : Animal("../media/wolf.png", window_surface_ptr_,2.3, std::set<std::string> { "Wolf","Alive", "Predator"}) {
  this->withoutEatingTime = 0;
}

Wolf::~Wolf() {}

void Wolf::interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition, const float& interractingObjectDirectionX, const float& interractingObjectDirectionY){
 if(collision::isColliding(this->get_position(),interractingObjectPosition)){
   if(interractingObject.has_attribute("Prey") && this->has_attribute("Alive") && interractingObject.has_attribute("Alive")){
      this->withoutEatingTime = 0; //Wolf feeds so his without eating time go back to 0
   }
 }
}

void Wolf::update_status(){
  this->withoutEatingTime++;
  if(this->withoutEatingTime > TIME_TO_STARVE_WOLF && this->has_attribute("Alive")){
    this->replace_attribute("Alive", "Dead");
    this->modify_picture(IMG_WOLF_DEAD);
  }
}
