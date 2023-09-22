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
    // std::cout << std::endl
    //           << "-------------------------------------" << std::endl;
    // int test = 0.0 / 0.0;
    // std::cout << test << std::endl;
    // float test(FLT_MAX);
    // double test2(DBL_MAX);
    // std::cout << test << " " << test2 << std::endl;
  }
  return 0;
}
