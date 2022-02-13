#pragma once
#include "../constants.h"


class InterractingObject {
private:
    std::set<std::string> properties;


public:
  InterractingObject(std::set<std::string> properties);
  ~InterractingObject();
  virtual void interract() = 0;
  bool hast_attribute(std::string attribute);
  void replace_attribute(std::string attribute_replace, std::string attribute_replace_by);
};