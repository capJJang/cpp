#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete brain;
}

Cat::Cat(const Cat& rhs) {
  std::cout << "Cat copy constructor called" << std::endl;
  this->_type = rhs.getType();
  *(this->brain) = *(rhs.brain);
}

Cat& Cat::operator=(const Cat& rhs) {
  if (this == &rhs) return *this;
  this->_type = rhs.getType();
  *(this->brain) = *(rhs.brain);
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

std::string Cat::getType() const { return this->_type; }
