#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of str : " << &str << std::endl;
	std::cout << "The memory address held by stringPTR : " << &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF : " << &stringREF << std::endl << std::endl;

	std::cout << "The value of the string variable : " << str << std::endl;
	std::cout << "The value pointed to by stringPTR. : " << stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF. : " << stringREF << std::endl;
}
