#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& rhs) { *this = rhs; }

AMateria& AMateria::operator=(const AMateria& rhs) {
  // this->_type = rhs.getType();
  (void)rhs;
  return *this;
}