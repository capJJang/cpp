#include "Contact.hpp"
#include <iostream>

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

std::string	Contact::getFirstName() { return firstName; }

std::string	Contact::getLastName() { return lastName; }

std::string	Contact::getNickname() { return nickname; }

std::string	Contact::getPhoneNumber() { return phoneNumber; }

std::string	Contact::getDarkestScret() { return darkestSecret; }

void	Contact::printContact()
{
	std::cout << getFirstName() << " | " << getLastName() << " | " << getNickname() << " | " << getPhoneNumber() << " | " << getDarkestScret() << std::endl;
}
