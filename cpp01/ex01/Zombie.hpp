#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie(/* args */);
	Zombie(std::string name_);
	~Zombie();
	void	announce();
	void	setZombieName(std::string name_);
};

Zombie* zombieHorde(int N, std::string name);

#endif
