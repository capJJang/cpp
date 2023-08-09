#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie(/* args */);
	Zombie(std::string name_);
	~Zombie();
	void	announce(std::string name);
	Zombie* newZombie( std::string name);
};
