#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Phonebook.hpp"

Phonebook::Phonebook()
{}

Phonebook::~Phonebook()
{}

void	Phonebook::add()
{
	std::string	input; std::string firstName; std::string lastName; std::string nickname; std::string phoneNumber; std::string darkestScret;

	std::cout << "Enter the sentence in the following format. firstName lastName nickname phoneNumber darkestScret" << std::endl;
	std::getline(std::cin, input);
	std::istringstream iss(input);
	if (!(iss >> firstName >> lastName >> nickname >> phoneNumber >> darkestScret))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	if (i >= 8)	i = 0;
	contact[i].setFirstName(firstName);
	contact[i].setFirstName(lastName);
	contact[i].setFirstName(nickname);
	contact[i].setFirstName(phoneNumber);
	contact[i].setFirstName(darkestScret);
	i++;
}



void	Phonebook::search()
{
	for (size_t j = 0; j < 8; j++)
		Phonebook::contact[j].printContact();
}

void	Phonebook::exit(void)
{
	std::exit(0);
}

