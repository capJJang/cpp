#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap(/* args */);
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap& rhs);
  ScavTrap& operator=(const ScavTrap& rhs);
  ~ScavTrap();

  void guardGate();
  void attack(std::string const& target);
};

// std::ostream& operator<<(std::ostream& out, const ClapTrap& rhs);

#endif