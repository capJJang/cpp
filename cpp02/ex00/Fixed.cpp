#pragma once

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(/* args */)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this-> = f.getRawBits();
	return *this;
}

int	Fixed::getRawBits()
{
	return (this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}