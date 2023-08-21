#include "ClapTrap.hpp"
#include <iostream>

//constructors
ClapTrap::ClapTrap(/* args */)
{
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& rhs)
{

}

ClapTrap& operator=(ClapTrap& rhs)
{
	if (*this == rhs)	return;
	this->hitPoints = rhs.getHitpoints();
}

//methods
std::string ClapTrap::getName()
{
	return (this->_name);
}

int	ClapTrap::getEnergyPoints()
{
	return (this->_energyPoints);
}

int	ClapTrap::getHitPoints()
{
	return (this->_hitPoints);
}

int	ClapTrap::getAttackDamage()
{
	return (_attackDamage);
}

std::string ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}
void	ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}
void	ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}
void	ClapTrap::attack(const std::string& target)
{

}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
		return ;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ClapTrap::takeDamage(unsigned int amout)
{

}

void	ClapTrap::beRepaired(unsigned int amout)
{
	if (this->_energyPoints <= 0)
		return ;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

