#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria {
 private:
  /* data */
 public:
  Cure(/* args */);
  ~Cure();
  Cure(const Cure &rhs);
  Cure &operator=(const Cure &rhs);
  AMateria *clone() const;
  void use(ICharacter &character);
};

#endif