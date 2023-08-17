#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name_) { this->name = name_; }

Zombie::~Zombie() { std::cout << this->name << " is dead.." << std::endl; }

void Zombie::setZombieName(std::string name_) { this->name = name_; }

void Zombie::announce() {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ" << std::endl;
}
