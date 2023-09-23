#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter(/* args */);
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &rhs);
  ScalarConverter &operator=(const ScalarConverter &rhs);

  static std::string toChar(std::string &userInput);
  static std::string toInt(std::string &userInput);
  static std::string intToString(int &tempInt);
  static std::string toFloat(std::string &userInput);
  static std::string floatToString(float &tempFloat);
  static std::string toDouble(std::string &userInput);
  static std::string doubleToString(double &tempDouble);
  static bool detectFraction(double target);
  static bool isPseudoLiteral(const std::string &userInput);

 public:
  static void converter(std::string &userInput);
};
