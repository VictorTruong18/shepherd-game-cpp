#include "interracting_object.h"

InterractingObject::InterractingObject(std::set<std::string> properties) {
  this->properties = properties;
}

InterractingObject::~InterractingObject() {}

void InterractingObject::add_attribute(std::string attribute) {
  if (!this->has_attribute(attribute)) {
    this->properties.insert(attribute);
  }
}

void InterractingObject::replace_attribute(std::string attribute_replace,
                                           std::string attribute_replace_by) {
  if (attribute_replace != attribute_replace_by) {
    this->add_attribute(attribute_replace_by);
    this->delete_attribute(attribute_replace);
  }
}

void InterractingObject::delete_attribute(std::string attribute) {
  if (this->has_attribute(attribute)) {
    this->properties.erase(attribute);
  }
}

bool InterractingObject::has_attribute(std::string attribute) {
  return this->properties.find(attribute) != this->properties.end();
  // if we had C++20 this->properties.contains(attribute)
}