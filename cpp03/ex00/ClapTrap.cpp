#include "ClapTrap.hpp"

#include <iostream>

// constructors
ClapTrap::ClapTrap(/* args */) {}

ClapTrap::~ClapTrap() {
  std::cout << "Clap Trap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "Clap Trap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& rhs) {
  std::cout << "Clap Trap copy constructor called" << std::endl;
  *this = rhs;
}

// operator overloading
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
  if (this == &rhs) return *this;
  this->setName(rhs.getName());
  this->setHitPoints(rhs.getHitPoints());
  this->setEnergyPoints(rhs.getEnergyPoints());
  this->setAttackDamage(rhs.getAttackDamage());
  return (*this);
}

std::ostream& operator<<(std::ostream& out, const ClapTrap& rhs) {
  out << "Name : " << rhs.getName() << "  Hit Points : " << rhs.getHitPoints()
      << "  Energy Points : " << rhs.getEnergyPoints()
      << "  Attack Damage : " << rhs.getAttackDamage();
  return out;
}

// methods
std::string ClapTrap::getName() const { return (this->_name); }

unsigned int ClapTrap::getEnergyPoints() const { return (this->_energyPoints); }

unsigned int ClapTrap::getHitPoints() const { return (this->_hitPoints); }

unsigned int ClapTrap::getAttackDamage() const { return (_attackDamage); }

void ClapTrap::setName(std::string name) { this->_name = name; }

void ClapTrap::setHitPoints(unsigned int hitPoints) {
  this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
  this->_energyPoints = energyPoints;
}
void ClapTrap::setAttackDamage(unsigned int attackDamage) {
  this->_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string& target) {
  if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0) return;
  std::cout << "ClapTrap " << this->_name << " attacks " << target
            << ", causing " << this->getAttackDamage() << " points of damage!"
            << std::endl;
  this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap " << this->getName() << " takes " << amount
            << " damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0) return;
  if (this->_energyPoints <= 0) return;
  std::cout << "ClapTrap " << this->_name << " repairing itself." << std::endl;
  this->setHitPoints(this->getHitPoints() + amount);
  this->setEnergyPoints(this->getEnergyPoints() - 1);
}
