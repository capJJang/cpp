#include "Brain.hpp"

#include <iostream>

Brain::Brain(/* args */) {
  std::cout << "Brain constructor called" << std::endl;
  for (size_t i = 0; i < 100; i++) {
    // ideas[i] = std::to_string(i);
    ideas[i] = "test";
  }
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain::Brain(const Brain &rhs) {
  std::cout << "Brain copy constructor called" << std::endl;
  for (size_t i = 0; i < 100; i++) {
    this->ideas[i] = rhs.ideas[i];
  }
}

Brain &Brain::operator=(const Brain &rhs) {
  if (this == &rhs) return *this;
  for (size_t i = 0; i < 100; i++) {
    this->ideas[i] = rhs.ideas[i];
  }
  return *this;
}

// std::string Brain::getIdea(int i) { return this->ideas[i]; }

// void Brain::setIdea(std::string idea_, int i) { this->ideas[i] = idea_; }
