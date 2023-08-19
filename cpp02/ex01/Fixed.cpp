#include <iostream>
#include <cmath>
#include "Fixed.hpp"

//constructors
Fixed::Fixed(/* args */)
{
	std::cout << "Default constructor called" << std::endl;
	this->numberValue = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::Fixed(const int numberValue_)
{
	std::cout << "Int constructor called" << std::endl;
	this->numberValue = numberValue_ << this->fractionalBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->numberValue = roundf(num * (1 << this->fractionalBits));
}

//operator overloading
Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)	
		this-> numberValue = rhs.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

//methods
int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->numberValue);
}

void Fixed::setRawBits(int const numberValue_)
{
	this->numberValue = numberValue_;
}

int	Fixed::toInt(void) const
{
	return (this->numberValue >> this->fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->numberValue / (1 << this->fractionalBits)); 
}