#include "Cure.hpp"

#include "ICharacter.hpp"

Cure::Cure(/* args */) : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &rhs) { *this = rhs; }

Cure &Cure::operator=(const Cure &rhs) {
  this->_type = rhs.getType();
  return *this;
}

AMateria *Cure::clone() const {
  AMateria *ret = new Cure();
  return ret;
}

void Cure::use(ICharacter &character) {
  std::cout << "* heals " << character.getName() << "’s wounds *"
            << " *" << std::endl;
}