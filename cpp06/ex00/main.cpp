#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Need one argument." << std::endl;
    return (1);
  }

  std::string str_argv(argv[1]);
  ScalarConverter::converter(str_argv);
  return 0;
}
