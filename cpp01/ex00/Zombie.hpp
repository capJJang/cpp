#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie(/* args */);
	~Zombie();
	void	announce(std::string name);
	Zombie* newZombie( std::string name);
};
