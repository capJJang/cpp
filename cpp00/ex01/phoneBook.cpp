#include <iostream>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include "Phonebook.hpp"

int Phonebook::i = 0;

Phonebook::Phonebook()
{}

Phonebook::~Phonebook()
{}

void	Phonebook::add()
{
	std::string	input;

	if (i >= 8)	i = 0;
	while(true)
	{
		std::cout << "Enter first name" << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::clearerr(stdin);
			std::cin.clear();
			std::cout << "Every field must be not null" << std::endl;
		}
		else
		{
			contact[i].setFirstName(input);
			break;
		}
	}
	while(true)
	{
		std::cout << "Enter last name" << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::clearerr(stdin);
			std::cin.clear();
			std::cout << "Every field must be not null" << std::endl;
		}
		else
		{
			contact[i].setLastName(input);
			break;
		}
	}
	while(true)
	{
		std::cout << "Enter nickname" << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::clearerr(stdin);
			std::cin.clear();
			std::cout << "Every field must be not null" << std::endl;
		}
		else
		{
			contact[i].setNickname(input);
			break;
		}
	}
	while(true)
	{
		std::cout << "Enter phone number" << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::clearerr(stdin);
			std::cin.clear();
			std::cout << "Every field must be not null" << std::endl;
		}
		else
		{
			contact[i].setPhoneNumber(input);
			break;
		}
	}
	while(true)
	{
		std::cout << "Enter darkest secret" << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::clearerr(stdin);
			std::cin.clear();
			std::cout << "Every field must be not null" << std::endl;
		}
		else
		{
			contact[i].setDarkestScret(input);
			break;
		}
	}
	i++;
}

void	Phonebook::search()
{
	std::string 		input;
	int					idx;

	for (int j = 0; j < 8; j++)
	{
		if (contact[j].getDarkestSecret().empty())
			 break;
		std::cout << std::setw(10) << std::right << j <<  "|";
		contact[j].printContact();
	}
	while (true)
	{
		std::cout << "Enter index(0 ~ 7)" << std::endl;
		std::getline(std::cin, input);
		std::istringstream	iss(input);
		iss >> idx;
		if (input.empty())
		{
			std::clearerr(stdin);
			std::cin.clear();
			return;
		}
		if (idx >= 0 && idx <= 7)
			break;
	}
	if (!contact[idx].getDarkestSecret().empty())
	{
		std::cout << contact[idx].getFirstName() << std::endl;
		std::cout << contact[idx].getLastName() << std::endl;
		std::cout << contact[idx].getNickname() << std::endl;
		std::cout << contact[idx].getPhoneNumber() << std::endl;
		std::cout << contact[idx].getDarkestSecret() << std::endl;
	}
}
