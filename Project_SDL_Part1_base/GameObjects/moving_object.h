#pragma once
#include "../constants.h"


class MovingObject {
protected:
    float veloxity_x;
    float veloxity_y;
    double speed;

public:
  MovingObject(double speed);
  ~MovingObject();
  virtual void move() = 0;
};