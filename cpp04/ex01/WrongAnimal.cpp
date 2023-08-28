#include "WrongAnimal.hpp"

#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(/* args */) : _type("N/A") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
  std::cout << "WrongAnimal string constructor called" << std::endl;
  this->_type = type;
}

void WrongAnimal::makeSound() const { std::cout << "..." << std::endl; }

std::string WrongAnimal::getType() const { return this->_type; }
