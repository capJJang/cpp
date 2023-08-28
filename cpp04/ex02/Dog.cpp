#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete brain;
}

Dog::Dog(const Dog& rhs) : Animal(rhs.getType()), brain(new Brain()) {
  std::cout << "Dog copy constructor called" << std::endl;
  *(this->brain) = *(rhs.brain);
}

Dog& Dog::operator=(const Dog& rhs) {
  if (this == &rhs) return *this;
  this->_type = rhs.getType();
  *(this->brain) = *(rhs.brain);
  return *this;
}

void Dog::makeSound() const { std::cout << "Bark!" << std::endl; }

std::string Dog::getType() const { return this->_type; }
