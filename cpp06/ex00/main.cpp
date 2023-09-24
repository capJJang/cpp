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

/*
nan
char: impossible
int: impossible
float: nanf
double: nan

42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

testcases  2147483647 -2147483648
+inff -inff nanf ff

42.2A 42.0ff
*/
