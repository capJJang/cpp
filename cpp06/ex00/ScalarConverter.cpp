#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */) {}

ScalarConverter::~ScalarConverter() {}

const char *ScalarConverter::OverFlowException::what() const throw() {
  return ("Impossible");
}

std::string ScalarConverter::toChar(std::string &userInput) {
  std::istringstream iss(userInput);
  long long n;

  n = static_cast<long long>
  std::cout << "n : " << n << std::endl;
  //   if (userInput.length() > 1)
  return "test";
}

// std::string ScalarConverter::toInt(std::string &userInput) {}

// std::string ScalarConverter::toFloat(std::string &userInput) {}

// std::string ScalarConverter::toDouble(std::string &userInput) {}

void ScalarConverter::converter(std::string &userInput) {
  toChar(userInput);
  //   toInt(userInput);
  //   toFloat(userInput);
  //   toDouble(userInput);
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
float: 42.0f double: 42.0

0
char: Non displayable
int: 0
float: 0.0f double: 0.0

*/
