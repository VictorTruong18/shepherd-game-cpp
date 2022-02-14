#include "constants.h"
namespace collision {
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

bool isCollidingWithEyesight(const SDL_Rect& a, const SDL_Rect& b, int eyeSightRange){
   //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x - eyeSightRange;
    rightA = a.x + a.w + eyeSightRange;
    topA = a.y - eyeSightRange;
    bottomA = a.y + a.h + eyeSightRange;

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
}

namespace mathOperation {
int round(int n)
{
    // Smaller multiple
    int a = (n / 10) * 10;
     
    // Larger multiple
    int b = a + 10;
 
    // Return of closest of two
    return (n - a > b - n)? b : a;
}
}