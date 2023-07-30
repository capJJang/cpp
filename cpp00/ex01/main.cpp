/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:08:16 by segan             #+#    #+#             */
/*   Updated: 2023/07/30 19:00:01 by segan            ###   ########.fr       */
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
		//std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "-----Enter commnad-----" <<  std::endl;
		std::cin >> cmd;
		if (std::cin.eof())
			break;
		else if (cmd.compare("ADD") == 0)		phonebook.add();
		else if (cmd.compare("SEARCH") == 0)	phonebook.search();
		else if (cmd.compare("EXIT") == 0)		break;
		else									std::cout << "Invalid command" << std::endl;
	}
}
