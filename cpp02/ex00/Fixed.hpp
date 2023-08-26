#pragma once

class Fixed {
 private:
  int numberValue;
  static const int fractionalBits = 8;

 public:
  Fixed(/* args */);
  ~Fixed();
  Fixed(const Fixed &rhs);
  Fixed &operator=(const Fixed &rhs);
  int getRawBits() const;
  void setRawBits(int const numberValue_);
};
