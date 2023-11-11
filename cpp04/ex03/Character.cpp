#include "Character.hpp"

#include "AMateria.hpp"

Character::Character(/* args */) {}

Character::~Character() {}

Character(const std::string& rhs) {}

Character::Character(const Character& rhs) {}

Character& Character::operator=(const Character& rhs) {}

std::string const& Character::getName() const {}

void Character::equip(AMateria* m) {
  if (idx_ > 3 || idx_ < 0) return;
  slot[idx_] = m;
  idx_++;
}

void Character::unequip(int idx) {
  if (idx_ > 3 || idx_ < 0) return;
  for (int i = idx; i < idx_; i++) slot[idx] = slot[++idx];
  idx_--;
}

void Character::use(int idx, ICharacter& target) {
  if (idx_ > 3 || idx_ < 0) return;
  slot[idx_]->use(target);
}
