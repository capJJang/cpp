/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:08:16 by segan             #+#    #+#             */
/*   Updated: 2023/08/01 17:20:26 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string cmd;
	Phonebook	phonebook;

	while (true)
	{
		std::cout << "-----Enter commnad-----" <<  std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break;
		else if (cmd.compare("ADD") == 0)		phonebook.add();
		else if (cmd.compare("SEARCH") == 0)	phonebook.search();
		else if (cmd.compare("EXIT") == 0)		break;
		else									std::cout << "Invalid command" << std::endl;
	}
}


