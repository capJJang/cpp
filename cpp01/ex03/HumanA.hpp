#pragma once
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon 		&weapon;
	std::string	name;
public:
	HumanA(std::string name_, Weapon &weapon_);
	~HumanA();
	void	attack();
};
