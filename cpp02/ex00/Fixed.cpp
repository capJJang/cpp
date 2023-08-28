
#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed(/* args */) {
  std::cout << "Default constructor called" << std::endl;
  this->numberValue = 0;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed& rhs) {
  std::cout << "Copy constructor called" << std::endl;
  this->numberValue = rhs.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this == &rhs) return *this;
  this->numberValue = rhs.getRawBits();
  return *this;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->numberValue);
}

void Fixed::setRawBits(int const numberValue_) {
  this->numberValue = numberValue_;
}
