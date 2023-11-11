#include "Character.hpp"

#include "AMateria.hpp"

Character::Character(/* args */) {}

Character::~Character() { delete[] slot; }

Character::Character(const std::string& rhs) {
  this->last = 0;
  this->name_ = rhs;
}

Character::Character(const Character& rhs) { *this = rhs; }

Character& Character::operator=(const Character& rhs) {
  for (int i = 0; i <= rhs.last; i++) {
    /* code */
  }

  return *this;
}

std::string const& Character::getName() const { return name_; }

void Character::equip(AMateria* m) {
  if (last > 3 || last < 0) return;
  slot[last] = m;
  last++;
}

void Character::unequip(int idx) {
  if (last > 3 || last < 0 || idx < 0 || idx > 3) return;
  while (idx < last) {
    slot[idx] = slot[idx + 1];
    idx++;
  }
  last--;
}

void Character::use(int idx, ICharacter& target) {
  if (last > 3 || last < 0 || idx < 0 || idx > 3) return;
  slot[last]->use(target);
}
