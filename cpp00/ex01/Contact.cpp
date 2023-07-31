#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact::setFirstName(std::string firstName_) { firstName = firstName_; }

void	Contact::setLastName(std::string lastName_) { lastName = lastName_; }

void	Contact::setNickname(std::string nickname_) { nickname = nickname_; }

void	Contact::setPhoneNumber(std::string phoneNumber_) { phoneNumber = phoneNumber_; }

void	Contact::setDarkestScret(std::string darkestSecret_) { darkestSecret = darkestSecret_; }

std::string	Contact::getFirstName() { return this->firstName; }

std::string	Contact::getLastName() { return this->lastName; }

std::string	Contact::getNickname() { return this->nickname; }

std::string	Contact::getPhoneNumber() { return this->phoneNumber; }

std::string	Contact::getDarkestSecret() { return this->darkestSecret; }

void	Contact::printContact()
{
	std::cout << std::setw(10) << getFirstName() << "|";
	std::cout << std::setw(10) << getLastName() << "|";
	std::cout << std::setw(10) << getNickname() << "|";
	std::cout << std::setw(10) << getDarkestSecret() << std::endl;
}

void	Contact::printField(std::string s)
{
	std::cout << std::setw(10);
	for (unsigned long i = 0; i < s.length(); i++)
	{
		if (i == 10)
		{
			std::cout << "TEST";
			break;
		}
		else
			std::cout << s[i];
	}
	std::cout << std::endl;
}
