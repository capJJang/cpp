#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact(/* args */);
		~Contact();
		void	setFirstName(std::string firstName);
		void	setLastName(std::string lasttName);
		void	setNickname(std::string nickname);
		void	setPhoneNumber(std::string phoneNumber);
		void	setDarkestScret(std::string darkestSecret);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestScret();
		void	printContact();
};

#endif
