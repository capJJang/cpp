#include <exception>
#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter(/* args */);
  ~ScalarConverter();
  class OverFlowException : std::exception {
   public:
    const char *what() const throw();
  };

  static std::string toChar(std::string &userInput);
  //   static std::string toInt(std::string &userInput);
  //   static std::string toFloat(std::string &userInput);
  //   static std::string toDouble(std::string &userInput);

 public:
  static void converter(std::string &userInput);
};
