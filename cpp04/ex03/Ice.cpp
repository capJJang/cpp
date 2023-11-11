#include "Ice.hpp"

#include "ICharacter.hpp"

Ice::Ice(/* args */) : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &rhs) { *this = rhs; }

Ice &Ice::operator=(const Ice &rhs) {
  this->_type = rhs.getType();
  return *this;
}

AMateria *Ice::clone() const {
  AMateria *ret = new Ice();
  return ret;
}

void Ice::use(ICharacter &character) {
  std::cout << "* shoots an ice bolt at" << character.getName() << " *"
            << std::endl;
}