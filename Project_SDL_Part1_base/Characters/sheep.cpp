#include "sheep.h"

bool isColliding(const SDL_Rect& a, const SDL_Rect& b){
   //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB ) { return false; }
    if( topA >= bottomB ) { return false; }
    if( rightA <= leftB ) { return false; }
    if( leftA >= rightB ) { return false; }

    //If none of the sides from A are outside B
    return true;
}

Sheep::Sheep(SDL_Surface* window_surface_ptr_)
    : Animal("../media/sheep.png", window_surface_ptr_,1, std::set<std::string> { "Sheep", "Alive", "Prey"}) {
  
}

Sheep::~Sheep() {}

void Sheep::interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition){
  //There is a physical collision
  if(isColliding(this->get_position(),interractingObjectPosition)){
    if(interractingObject.has_attribute("Predator")){
      this->replace_attribute("Alive","Dead");  
    }
    
  }
}

