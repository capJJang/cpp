#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <iostream>
#include <stack>
#include <string>

class RPN {
 private:
  std::stack<char> s;
  RPN(/* args */);
  RPN &operator=(const RPN &rhs);
  RPN(const RPN &rhs);

 public:
  ~RPN();
  RPN(std::string &userInput);
  void userInputValidator(const std::string &userInput);
  void start(std::string &userInput);
};

#endif