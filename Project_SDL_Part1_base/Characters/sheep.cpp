#include "sheep.h"



Sheep::Sheep(SDL_Surface* window_surface_ptr_)
    : Animal(IMG_SHEEP, window_surface_ptr_,1, std::set<std::string> { "Sheep", "Alive", "Prey", sex[rand() % 2], "Horny"}) {
  if(this->has_attribute("Female") && this->has_attribute("Horny")){
    this->modify_picture(IMG_SHEEP_FEMALE_HORNY);
  }
  if(this->has_attribute("Male")){
    this->modify_picture(IMG_SHEEP_MALE);
  }
  this->timeGrowing = 0;
}

Sheep::~Sheep() {}

void Sheep::interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition, const float& interractingObjectDirectionX, const float& interractingObjectDirectionY){
  //There is a physical collision
  if(collision::isColliding(this->get_position(),interractingObjectPosition)){
    //If the Sheep meets a Predator
    if(interractingObject.has_attribute("Predator") && interractingObject.has_attribute("Alive") && this->has_attribute("Alive")){
      interractingObject.interract(*this, this->get_position(), this->get_direction_x(), this->get_direction_y());
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
  //There is a visual collision
  if(collision::isCollidingWithEyesight(this->get_position(),interractingObjectPosition, EYE_SIGHT_SHEEP)){
    if(interractingObject.has_attribute("Predator") && interractingObject.has_attribute("Alive") && this->has_attribute("Alive")){
      this->veloxity_x = interractingObjectDirectionX;
      this->veloxity_y = interractingObjectDirectionY;
      this->add_attribute("Boost");
      this->timeBoost = 0;
    }
  }
}

void Sheep::update_status(){
 if( this->has_attribute("Alive") && (this->has_attribute("Offspring") || this->has_attribute("Lamb")) ){
   if(this->has_attribute("Offspring") && this->timeGrowing < TIME_TO_GROW_TO_SHEEP/2){
     this->modify_picture(IMG_OFFSPRING);
     this->timeGrowing++;
   } else {
     this->replace_attribute("Offspring", "Lamb");
   }
   if(this->has_attribute("Lamb") && this->timeGrowing < TIME_TO_GROW_TO_SHEEP){
     this->modify_picture(IMG_LAMB);
     this->timeGrowing++;
   } else {
     this->delete_attribute("Lamb");
     

   }
 }  
  if(this->has_attribute("Alive") && this->has_attribute("Female") && this->has_attribute("Horny") && !(this->has_attribute("Offspring") || this->has_attribute("Lamb"))){
    this->modify_picture(IMG_SHEEP_FEMALE_HORNY);
  }
  if(this->has_attribute("Alive") && this->has_attribute("Female") && !!this->has_attribute("Horny") && !(this->has_attribute("Offspring") || this->has_attribute("Lamb"))){
     this->timeCooldownGivingBirth++;
     if(this->timeCooldownGivingBirth < TIME_TO_REPRODUCE_COOLDOWN_SHEEP){
       this->modify_picture(IMG_SHEEP_FEMALE);
     } else {
       this->add_attribute("Horny");
     }
  }
  if(this->has_attribute("Alive") && this->has_attribute("Male") && this->has_attribute("Horny") && !(this->has_attribute("Offspring") || this->has_attribute("Lamb"))){
    this->modify_picture(IMG_SHEEP_MALE);
  }

  if(this->has_attribute("Alive") && this->has_attribute("Boost") && !(this->has_attribute("Offspring") || this->has_attribute("Lamb"))){
      if(this->timeBoost < TIME_BOOST_SHEEP){
        this->timeBoost++;
        this->speed = 5;
        this->modify_picture(IMG_SHEEP_SCARED);
      } else {
        this->delete_attribute("Boost");
        this->speed = 1;
      }
      
  }
}


void Sheep::move() {
  if(this->has_attribute("Alive")){
    int max_height = frame_height - frame_boundary - this->image_ptr_->h;
    int max_width = frame_width - frame_boundary - this->image_ptr_->w;

    if (this->image_position_.x <= frame_boundary) {
      this->veloxity_x = -this->veloxity_x;
      this->image_position_.x = frame_boundary;
    }
    if (this->image_position_.x >= max_width) {
      this->veloxity_x = -this->veloxity_x;
      this->image_position_.x = max_width;
    }
    if (this->image_position_.y <= frame_boundary) {
      this->veloxity_y = -this->veloxity_y;
      this->image_position_.y = frame_boundary;
    }

    if (this->image_position_.y >= max_height) {
      this->veloxity_y = -this->veloxity_y;
      this->image_position_.y = max_height;
    }
    this->image_position_.x += this->veloxity_x * this->speed;
    this->image_position_.y += this->veloxity_y * this->speed;
  }
}