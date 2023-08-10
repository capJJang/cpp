#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name_, Weapon &weapon_)
{
	this->name = name_;
	this->weapon = &weapon_;
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
