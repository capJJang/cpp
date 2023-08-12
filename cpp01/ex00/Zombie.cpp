#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string name_) { name = name_; }

Zombie::~Zombie() { std::cout << name << " is dead.." << std::endl; }

void Zombie::announce() {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ" << std::endl;
}
