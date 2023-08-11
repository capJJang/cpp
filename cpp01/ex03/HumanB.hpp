#pragma once
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon 		*weapon;
	std::string	name;
public:
	HumanB(std::string name_);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon *weapon_);
};
