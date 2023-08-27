#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog& rhs) : Animal(rhs.getType()) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
  if (this == &rhs) return *this;
  this->_type = rhs.getType();
  return *this;
}

void Dog::makeSound() const { std::cout << "Bark!" << std::endl; }

std::string Dog::getType() const { return this->_type; }
