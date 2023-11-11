#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"
class Character : public ICharacter {
 private:
  int idx_;
  AMateria *slot[4];

 public:
  Character(/* args */);
  ~Character();
  Character(const Character &rhs);
  Character(const std::string &rhs);
  Character &operator=(const Character &rhs);

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif