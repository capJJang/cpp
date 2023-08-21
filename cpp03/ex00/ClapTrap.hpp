#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string _name;
	int	_hitPoints;
	int	_energyPoints;
	int _attackDamage;
public:
	ClapTrap(/* args */);
	~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap& rhs);
	ClapTrap& operator=(const ClapTrap& rhs);

	std::string getName();
	int	getHitPoints();
	int	getEnergyPoints();
	int	getAttackDamage();
	std::string setName(std::string name);

	void	setHitPoints(int hitPoints);
	void	setEnergyPoints(int energyPoints);
	void	setAttackDamage(int attackDamage);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amout);
	void	beRepaired(unsigned int amout);
};

#endif