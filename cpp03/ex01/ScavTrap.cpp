#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() {
  std::cout << "Scav Trap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
  std::cout << "Scav Trap Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "Scav Trap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs)
    : ClapTrap(rhs), _hitPoints(rhs._hitPoints), _energyPoints(rhs._energyPoints), _attackDamage(rhs._attackDamage) {
  std::cout << "Copy constructor called" << std::endl;
}

// ScavTrap::ScavTrap(const ScavTrap& rhs) {
//   std::cout << "Copy constructor called" << std::endl;
//   *this = rhs;
// }

// operator overloading
ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
  if (this == &rhs) return *this;
  this->_name = rhs._name;
  this->_hitPoints = rhs._hitPoints;
  this->_energyPoints = rhs._energyPoints;
  this->_attackDamage = rhs._attackDamage;
  return (*this);
}

// std::ostream& operator<<(std::ostream& out, const ScavTrap& rhs) {
//   out << "Name : " << rhs._name << "  Hit Points : " << rhs._hitPoints
//       << "  Energy Points : " << rhs._energyPoints
//       << "  Attack Damage : " << rhs._attackDamage;
//   return out;
// }

void ScavTrap::guardGate() {
  std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (this->_hitPoints <= 0 || this->_energyPoints <= 0) return;
  std::cout << "ScavTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attackDamage << " points of damage!"
            << std::endl;
  this->_energyPoints--;
}