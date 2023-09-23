#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs) { (void)rhs; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}

bool ScalarConverter::isPseudoLiteral(const std::string &userInput) {
  return (userInput == "nan" || userInput == "nanf"|| userInput == "inf" || userInput == "+inf" ||
          userInput == "+inf" || userInput == "inff" || userInput == "+inff" ||
          userInput == "-inff");
}

std::string ScalarConverter::toChar(std::string &userInput) {
  std::stringstream ss(userInput);
  int tempChar;
  std::string ret;

  ss >> tempChar;
  if (ss.fail()) {
    if (userInput.length() == 1)
      ret = '\'' + userInput + '\'';
    else {
      ret = "Impossible";
    }
  } else if (tempChar < 32 || tempChar == 127) {
    ret = "Non displayable";
  } else {
    std::string tempRet;
    tempRet = static_cast<char>(tempChar);
    ret = '\'' + tempRet + '\'';
  }
  return "char: " + ret;
}

std::string ScalarConverter::intToString(int &tempInt) {
  std::stringstream ss;

  ss << tempInt;
  return (ss.str());
}

std::string ScalarConverter::toInt(std::string &userInput) {
  std::stringstream ss(userInput);
  int tempInt;
  std::string ret;

  ss >> tempInt;
  if (ss.fail()) {
    if (userInput.length() == 1) {
      tempInt = static_cast<int>(userInput[0]);
      ret = intToString(tempInt);
    } else
      ret = "Impossible";
  } else {
    ret = intToString(tempInt);
  }
  return ("int: " + ret);
}

std::string ScalarConverter::floatToString(float &tempfloat) {
  std::stringstream ss;

  ss << tempfloat;
  return (ss.str());
}

std::string ScalarConverter::toFloat(std::string &userInput) {
  std::stringstream ss(userInput);
  std::string ret;
  float tempFloat;

  ss >> tempFloat;
  if (isPseudoLiteral(userInput) == true) {
    ret = userInput;
  } else if (ss.fail()) {
    if (userInput.length() == 1) {
      tempFloat = static_cast<float>(userInput[0]);
      ret = floatToString(tempFloat);
    } else
      ret = "Impossible";
  } else {
    ret = floatToString(tempFloat);
    if (detectFraction(tempFloat)) ret += ".0";
    ret += "f";
  }
  return ("float: " + ret);
}

std::string ScalarConverter::doubleToString(double &tempDouble) {
  std::stringstream ss;

  ss << tempDouble;
  return (ss.str());
}

std::string ScalarConverter::toDouble(std::string &userInput) {
  std::stringstream ss(userInput);
  std::string ret;
  double tempDouble;

  ss >> tempDouble;
  if (ss.fail()) {
    if (userInput.length() == 1) {
      tempDouble = static_cast<double>(userInput[0]);
      ret = doubleToString(tempDouble);
    } else
      ret = "Impossible";
  } else {
    ret = doubleToString(tempDouble);
    if (detectFraction(tempDouble)) ret += ".0";
  }
  return ("double: " + ret);
}

bool ScalarConverter::detectFraction(double target) {
  return target == static_cast<int>(target);
}

void ScalarConverter::converter(std::string &userInput) {
  std::cout << toChar(userInput) << std::endl;
  std::cout << toInt(userInput) << std::endl;
  std::cout << toFloat(userInput) << std::endl;
  std::cout << toDouble(userInput) << std::endl;
}
