#pragma once

#include <iostream>

class Fixed {
 private:
  int numberValue;
  static const int fractionalBits = 8;

 public:
  Fixed(/* args */);
  ~Fixed();
  Fixed(const Fixed &rhs);
  Fixed(const int numberValue_);
  Fixed(const float numberValue);
  Fixed &operator=(const Fixed &rhs);
  bool operator>(const Fixed &rhs) const;
  bool operator<(const Fixed &rhs) const;
  bool operator>=(const Fixed &rhs) const;
  bool operator<=(const Fixed &rhs) const;
  bool operator==(const Fixed &rhs) const;
  bool operator!=(const Fixed &rhs) const;
  Fixed operator+(const Fixed &rhs) const;
  Fixed operator-(const Fixed &rhs) const;
  Fixed operator*(const Fixed &rhs) const;
  Fixed operator/(const Fixed &rhs) const;
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);
  int getRawBits() const;
  void setRawBits(int const numberValue_);
  int toInt(void) const;
  float toFloat(void) const;
  static Fixed &min(Fixed &param1, Fixed &param2);
  static Fixed &max(Fixed &param1, Fixed &param2);
  static const Fixed &min(const Fixed &param1, const Fixed &param2);
  static const Fixed &max(const Fixed &param1, const Fixed &param2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);
