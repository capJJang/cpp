#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs) { (void)rhs; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}

bool ScalarConverter::formatChecker(std::string &userInput) {
  bool period = false;

  if (isPseudoLiteral(userInput) || isPseudoLiteralF(userInput)) return true;
  if (userInput.length() == 1) return true;

  for (size_t i = 0; i < userInput.length(); i++) {
    if (!(isdigit(userInput[i]))) {
      if ((isalpha(userInput[i]) && userInput.length() == 1))
        ;
      else if (userInput[i] == 'f') {
        if (i != userInput.length() - 1 || userInput[i - 1] == '.')
          return false;
      } else if (!period && userInput[i] == '.') {
        if (i == 0 || i == userInput.length() - 1) return false;
        period = true;
      } else if (i == 0 && userInput[i] == '-')
        continue;
      else
        return false;
    }
  }
  return true;
}

bool ScalarConverter::isPseudoLiteral(const std::string &userInput) {
  return (userInput == "inf" || userInput == "+inf" || userInput == "-inf" ||
          userInput == "nan");
}

bool ScalarConverter::isPseudoLiteralF(const std::string &userInput) {
  return (userInput == "inff" || userInput == "+inff" || userInput == "-inff" ||
          userInput == "nanf");
}

std::string ScalarConverter::toChar(std::string &userInput) {
  std::stringstream ss(userInput);
  int tempChar;
  std::string ret;

  ss >> tempChar;

  if (formatChecker(userInput) == false)
    ret = "Impossible";
  else if (ss.fail() || tempChar < 0 || tempChar > 127) {
    if (userInput.length() == 1)
      ret = '\'' + userInput + '\'';
    else {
      ret = "Impossible";
    }
  } else if (userInput.length() >= 2 &&
             (userInput[userInput.length() - 1] < '0' ||
              userInput[userInput.length() - 1] > '9') &&
             (userInput[userInput.length() - 1] != 'f')) {
    ret = "Impossible";
  } else if (tempChar < 32 || tempChar == 127) {
    ret = "Non displayable";
  } else {
    std::string tempRet;
    tempRet = static_cast<char>(tempChar);
    ret = '\'' + tempRet + '\'';
  }
  return ret;
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
  if (formatChecker(userInput) == false)
    ret = "Impossible";
  else if (ss.fail()) {
    if (userInput.length() == 1) {
      tempInt = static_cast<int>(userInput[0]);
      ret = intToString(tempInt);
    } else
      ret = "Impossible";
  } else if (userInput.length() >= 2 &&
             (userInput[userInput.length() - 1] < '0' ||
              userInput[userInput.length() - 1] > '9') &&
             (userInput[userInput.length() - 1] != 'f')) {
    ret = "Impossible";
  } else {
    ret = intToString(tempInt);
  }
  return (ret);
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
  if (formatChecker(userInput) == false)
    ret = "Impossible";
  else if (ss.fail()) {
    if ((userInput[userInput.length() - 1] == 'f' && userInput.length() > 1) &&
        (userInput[userInput.length() - 2] != 'f')) {
      userInput.pop_back();
      ret = toFloat(userInput);
    } else if (userInput.length() == 1) {  // char
      tempFloat = static_cast<float>(userInput[0]);
      ret = floatToString(tempFloat) + ".0f";
    } else if (isPseudoLiteralF(userInput)) {           // inff, -inff, nanf
      if (userInput == "+inff") userInput.erase(0, 1);  // erase "+"
      userInput.pop_back();
      ret = userInput + "f";
    } else
      ret = "Impossible";
  } else {
    ret = floatToString(tempFloat);
    if (detectFraction(tempFloat)) ret += ".0";
    ret += "f";
  }
  return (ret);
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
  if (formatChecker(userInput) == false)
    ret = "Impossible";
  else if (ss.fail()) {
    if (userInput.length() == 1) {
      tempDouble = static_cast<double>(userInput[0]);
      ret = doubleToString(tempDouble) + ".0";
    } else
      ret = "Impossible";
  } else {
    ret = doubleToString(tempDouble);
    if (detectFraction(tempDouble)) ret += ".0";
  }
  return (ret);
}

bool ScalarConverter::detectFraction(double target) {
  return target == static_cast<int>(target);
}

void ScalarConverter::converter(std::string &userInput) {
  // std::cout << formatChecker(userInput) << std::endl;
  std::cout << "char: " << toChar(userInput) << std::endl;
  std::cout << "int: " << toInt(userInput) << std::endl;
  std::cout << "float: " << toFloat(userInput) << std::endl;
  std::cout << "double: " << toDouble(userInput) << std::endl;
}
