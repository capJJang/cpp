#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name_)
{
	name = name_;
}

Zombie::~Zombie()
{
	std::cout << name << "is dead.." << std::endl;
}

void	Zombie::announce(std::string name)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie* Zombie::newZombie( std::string name)
{
	Zombie *ret = new Zombie(name);
}
