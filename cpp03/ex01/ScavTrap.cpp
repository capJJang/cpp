#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() {
  std::cout << "Scav Trap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name),
      _name(name),
      _hitPoint(100),
      _energyPoint(50),
      _attackDamage(20) {
  std::cout << "Scav Trap Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "Scav Trap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs)
    : ClapTrap(rhs._name),
      _name(rhs._name),
      _hitPoint(rhs._hitPoint),
      _energyPoint(rhs._energyPoint),
      _attackDamage(rhs._attackDamage) {
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
  this->_hitPoint = rhs._hitPoints;
  this->_energyPoint = rhs._energyPoints;
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