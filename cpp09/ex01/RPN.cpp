#include "RPN.hpp"

RPN::RPN(/* args */) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
  this->s = rhs.s;
  return *this;
}

RPN::RPN(const RPN &rhs) { this->s = rhs.s; }

RPN::RPN(std::string &userInput) {
  userInputValidator(userInput);
  start(userInput);
}

void RPN::userInputValidator(const std::string &userInput) {
  size_t length = userInput.size();
  for (size_t i = 0; i < length; i++) {
    if (!std::isdigit(userInput[i]) || userInput[i] != ' ' ||
        !std::strchr("+-*/", userInput[i])) {
      std::cerr << "Invalid char" << std::endl;
      exit(1);
    }
    if (std::atoi(userInput.c_str()) < 0 || std::atoi(userInput.c_str()) > 9) {
      std::cerr << "Argument must be less than 10" << std::endl;
      exit(1);
    }
    if (i % 2 == 1 && userInput[i] != ' ') {
      std::cerr << "Not proper Space" << std::endl;
      exit(1);
    }
  }
}

void RPN::start(std::string &userInput) {
  size_t length = userInput.size();
  size_t result = 0;
  for (size_t i = 0; i < length; i++) {
    if (std::isdigit(userInput[i])) s.push(userInput[i]);
    if (userInput[i] == ' ') continue;
    if (std::strchr("+-*/", userInput[i])) {
      int left = s.top();
      s.pop();
      int right = s.top();
      s.pop();
      switch (userInput[i]) {
        case '+':
          result += left + right;
          break;
        case '-':
          result += left - right;
          break;
        case '*':
          result += left * right;
        case '/':
          result += left / right;
        default:
          break;
      }
      s.push(userInput[i]);
    }
  }
  if (s.size() == 0)
    std::cout << result << std::endl;
  else
    std::cout << "Invalid Input" << std::endl;
}