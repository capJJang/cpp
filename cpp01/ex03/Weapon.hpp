#pragma once

#include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(/* args */);
	Weapon(std::string type_);
	~Weapon();
	std::string	getType();
	void		setType(std::string newType);
};
