#include "Animal.hpp"

#include <iostream>
#include <string>

Animal::Animal(/* args */) : _type("N/A") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(std::string type) {
  std::cout << "Animal string constructor called" << std::endl;
  this->_type = type;
}

void Animal::makeSound() const { std::cout << "..." << std::endl; }

std::string Animal::getType() const { return _type; }
