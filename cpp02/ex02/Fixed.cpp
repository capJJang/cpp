#include "Fixed.hpp"

#include <cmath>
#include <iostream>

// constructors
Fixed::Fixed(/* args */) { this->numberValue = 0; }

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& rhs) { *this = rhs; }

Fixed::Fixed(const int numberValue_) {
  this->numberValue = numberValue_ << this->fractionalBits;
}

Fixed::Fixed(const float num) {
  this->numberValue = roundf(num * (1 << this->fractionalBits));
}

// operator overloading
Fixed& Fixed::operator=(const Fixed& rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs) this->numberValue = rhs.numberValue;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs) {
  out << rhs.toFloat();
  return (out);
}

bool Fixed::operator>(Fixed const& rhs) const {
  return (this->numberValue > rhs.numberValue);
}

bool Fixed::operator<(Fixed const& rhs) const {
  return (this->numberValue < rhs.numberValue);
}

bool Fixed::operator>=(Fixed const& rhs) const {
  return (this->numberValue >= rhs.numberValue);
}

bool Fixed::operator<=(Fixed const& rhs) const {
  return (this->numberValue <= rhs.numberValue);
}

bool Fixed::operator==(Fixed const& rhs) const {
  return (this->numberValue == rhs.numberValue);
}

bool Fixed::operator!=(Fixed const& rhs) const {
  return (this->numberValue != rhs.numberValue);
}

Fixed Fixed::operator+(const Fixed& rhs) const {
  return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed& rhs) const {
  return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed& rhs) const {
  return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed& rhs) const {
  return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++() {
  this->numberValue++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(this->numberValue);
  this->numberValue++;
  return (temp);
}

Fixed& Fixed::operator--() {
  this->numberValue--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(this->numberValue);
  this->numberValue--;
  return (temp);
}

// methods
int Fixed::getRawBits() const {
  // std::cout << "getRawBits member function called" << std::endl;
  return (this->numberValue);
}

void Fixed::setRawBits(int const numberValue_) {
  this->numberValue = numberValue_;
}

int Fixed::toInt(void) const {
  return (this->numberValue >> this->fractionalBits);
}

float Fixed::toFloat(void) const {
  return ((float)this->numberValue / (1 << this->fractionalBits));
}

Fixed& Fixed::min(Fixed& param1, Fixed& param2) {
  if (param1.numberValue < param2.numberValue)
    return param1;
  else
    return param2;
}

Fixed& Fixed::max(Fixed& param1, Fixed& param2) {
  if (param1.numberValue < param2.numberValue)
    return param2;
  else
    return param1;
}

const Fixed& Fixed::min(Fixed const& param1, Fixed const& param2) {
  if (param1.numberValue < param2.numberValue)
    return param1;
  else
    return param2;
}

const Fixed& Fixed::max(Fixed const& param1, Fixed const& param2) {
  if (param1.numberValue < param2.numberValue)
    return param2;
  else
    return param1;
}
