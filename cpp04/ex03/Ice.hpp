#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {
 private:
  /* data */
 public:
  Ice(/* args */);
  ~Ice();
  Ice(const Ice &rhs);
  Ice &operator=(const Ice &rhs);
  AMateria *clone() const;
  void use(ICharacter &character);
};

#endif