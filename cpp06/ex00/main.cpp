#include <cfloat>
#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Need one argument." << std::endl;
    return (1);
  }

  std::string str_argv(argv[1]);
  std::cout << str_argv << std::endl;
  ScalarConverter::converter(str_argv);
  {
    std::cout << std::endl
              << "-------------------------------------" << std::endl;
    // float test = 1.0 / 0.0;
    // std::cout << test << std::endl;
    // // float test(FLT_MAX);

    // double test2(DBL_MIN);
    // std::cout << test << " " << test2 << std::endl;

    std::stringstream ss("asdf");
    float test;
    ss >> test;
    std::cout << test << std::endl;
  }
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
*/
