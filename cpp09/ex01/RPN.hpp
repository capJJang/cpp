#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

class RPN {
 private:
  std::stack<int> s;
  RPN(/* args */);
  RPN &operator=(const RPN &rhs);
  RPN(const RPN &rhs);

 public:
  ~RPN();
  RPN(std::string &userInput);
  void userInputValidator(const std::string &userInput);
  void start(std::string &userInput);
  size_t calc(char operand);
};

#endif