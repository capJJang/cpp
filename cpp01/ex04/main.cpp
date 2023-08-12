#include <fstream>
#include <iostream>

int	main(int argc, const char *argv[])
{
	std::fstream	oldFile;
	std::fstream	replacedFile;
	std::string		readBuffer;

	if (argc != 4)
	{
		std::cout << "3 Arguments required" << std::endl;
		return (0);
	}
	std::string	replacedFileName = std::string(argv[1]) + ".replace";
	oldFile.open(argv[1], std::ios::in);
	replacedFile.open(replacedFileName, std::ios::out);
	if (!oldFile.is_open() || !replacedFile.is_open())
	{
		std::cout << "Invalid file name" << std::endl;
		return (0);
	}
	while (getline(oldFile, readBuffer))
	{
		if (readBuffer.compare(argv[2]) == 0)
			readBuffer = argv[3];
		replacedFile << readBuffer << std::endl;
	}
	std::cout << "finished" << std::endl;
}