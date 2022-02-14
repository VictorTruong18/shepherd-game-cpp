#pragma once
#include "../constants.h"

class InterractingObject {
private:
  std::set<std::string> properties;

public:
  InterractingObject(std::set<std::string> properties);
  ~InterractingObject();
  virtual void interract(InterractingObject& interractingObject,
                         const SDL_Rect& interractingObjectPosition,
                         const float& interractingObjectDirectionX,
                         const float& interractingObjectDirectionY) = 0;
  bool has_attribute(std::string attribute);
  void replace_attribute(std::string attribute_replace,
                         std::string attribute_replace_by);
  void add_attribute(std::string attribute);
  void delete_attribute(std::string attribute);
};