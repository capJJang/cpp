#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  Bureaucrat test1("test1", 1);
  std::cout << "-------------------------------" << std::endl;
  Bureaucrat test2("test2", 149);
  std::cout << "-------------------------------" << std::endl;
  try {
    Bureaucrat test3("test3", 0);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "-------------------------------" << std::endl;
  try {
    Bureaucrat test3("test3", 0);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "-------------------------------" << std::endl;

  try {
    test1.decrementGrade(1);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "-------------------------------" << std::endl;
  try {
    test2.incrementGrade(1);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}