#include "Weapon.hpp"

Weapon::Weapon(/* args */)
{
}

Weapon::Weapon(std::string type_)
{
	this->type = type_;
}

Weapon::~Weapon()
{
}

std::string	Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}
