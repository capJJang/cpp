#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name_)
{
	this->name = name_;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void	HumanB::setWeapon(Weapon weapon_)
{
	this->weapon = weapon_;
}
