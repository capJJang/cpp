#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook{
	private :
		Contact contact[8];
		static int	i;
	public :
		Phonebook();
		~Phonebook();
		void	add();
		void	search();
		void	printPhoneBook();
};

#endif
