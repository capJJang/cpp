#pragma once

#include <iostream>

class Fixed
{
private:
	int					numberValue;
	static const int	fractionalBits = 8;
public:
	Fixed(/* args */);
	~Fixed();
	Fixed(const Fixed& rhs);
	Fixed(const int numberValue_);
	Fixed(const float numberValue);
	Fixed &operator=(const Fixed &rhs);
	bool	operator>(Fixed const &rhs) const;
	bool	operator<(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator==(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;
	int		getRawBits() const;
	void	setRawBits(int const numberValue_);
	int		toInt(void) const;
	float	toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);