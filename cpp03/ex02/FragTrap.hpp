#ifndef FragTrap_HPP
#define FragTrap_HPP

#include <string>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  FragTrap(/* args */);
  FragTrap(std::string name);
  FragTrap(const FragTrap& rhs);
  FragTrap& operator=(const FragTrap& rhs);
  ~FragTrap();

  void highFiveGuys();
};

// std::ostream& operator<<(std::ostream& out, const ClapTrap& rhs);

#endif