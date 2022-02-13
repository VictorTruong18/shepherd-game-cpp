#include "moving_object.h"

MovingObject::MovingObject(double speed){
    this->veloxity_x = arr[rand() % 2];
    this->veloxity_y = arr[rand() % 2];
    this->speed = speed;
}

MovingObject::~MovingObject(){}