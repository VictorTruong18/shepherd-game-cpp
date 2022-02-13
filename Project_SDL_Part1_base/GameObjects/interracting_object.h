#pragma once
#include "../constants.h"


class InterractingObject {
private:
    std::set<std::string> properties;


public:
  InterractingObject(std::set<std::string> properties);
  ~InterractingObject();
  void interract();
  bool hast_attribute(std::string attribute);
  void replace_attribute(std::string attribute_replace, std::string attribute_replace_by);
};