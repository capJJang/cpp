#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 private:
  std::string _name;
  unsigned int _hitPoint;
  unsigned int _energyPoint;
  unsigned int _attackDamage;

 public:
  ScavTrap(/* args */);
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap& rhs);
  ScavTrap& operator=(const ScavTrap& rhs);
  ~ScavTrap();

  void guardGate();
};

// std::ostream& operator<<(std::ostream& out, const ClapTrap& rhs);

#endif