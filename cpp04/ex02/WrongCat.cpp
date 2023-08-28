#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs.getType()) {
  std::cout << "WrongCat copy constructor called" << std::endl;
  *(this->brain) = *(rhs.brain);
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
  if (this == &rhs) return *this;
  this->_type = rhs.getType();
  *(this->brain) = *(rhs.brain);
  return *this;
}

void WrongCat::makeSound() const { std::cout << "Meow!" << std::endl; }

std::string WrongCat::getType() const { return this->_type; }
