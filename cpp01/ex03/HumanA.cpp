#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name_, Weapon &weapon_) : weapon(weapon_), name(name_)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
