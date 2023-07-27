/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:08:16 by segan             #+#    #+#             */
/*   Updated: 2023/07/27 15:11:15 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "Phonebook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string cmd;
	Phonebook	phonebook;

	while (true)
	{
		std::cout << "-----Enter commnad-----" <<  std::endl;
		std::cin >> cmd;
		if (std::cin.eof()) {
			clearerr(stdin);
			std::cin.clear();
		}
		else if (cmd.compare("ADD") == 0)
			phonebook.add();
		else if (cmd.compare("SEARCH") == 0)
			phonebook.search();
		else if (cmd.compare("EXIT") == 0)
			phonebook.exit();
		else
			std::cout << "Invalid command" << std::endl;
	}

}
