#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {
  std::cout << "Frag Trap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "Frag Trap Constructor called" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "Frag Trap Destructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs) {
  std::cout << "Copy constructor called" << std::endl;
}

// operator overloading
FragTrap& FragTrap::operator=(const FragTrap& rhs) {
  if (this == &rhs) return *this;
  this->_name = rhs._name;
  this->_hitPoints = rhs._hitPoints;
  this->_energyPoints = rhs._energyPoints;
  this->_attackDamage = rhs._attackDamage;
  return (*this);
}

// std::ostream& operator<<(std::ostream& out, const FragTrap& rhs) {
//   out << "Name : " << rhs._name << "  Hit Points : " << rhs._hitPoints
//       << "  Energy Points : " << rhs._energyPoints
//       << "  Attack Damage : " << rhs._attackDamage;
//   return out;
// }

void FragTrap::highFiveGuys() {
  std::cout << "FragTrap wants to fighfive." << std::endl;
}

// void FragTrap::attack(const std::string& target) {
//   if (this->_hitPoints <= 0 || this->_energyPoints <= 0) return;
//   std::cout << "FragTrap " << this->_name << " attacks " << target
//             << ", causing " << this->_attackDamage << " points of damage!"
//             << std::endl;
//   this->_energyPoints--;
// }