#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *ret = new Zombie[N];

	(void)name;
	for (int i = 0; i < N; i++)
	{
		ret[i] = setZombieName(name + std::to_string(i + 1));
		//ret[i] = Zombie(name + std::to_string(i + 1));
		ret[i].announce();
	}
	return (ret);
}

//scope를 벗어나면 소멸자 호출,,,
