#include <iostream>
#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}


void	Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout	<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout	<< "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout	<< "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout	<< "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::complain(std::string complain)
{
	int	i = 0;
	std::string funcs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*fPointer[4])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	while (i < 4)
	{
		if (funcs[i] == complain)
			break ;
		i++;
	}
	(this->*fPointer[i])();
}