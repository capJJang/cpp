#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
}

void	Zombie::announce(std::string name)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
}
