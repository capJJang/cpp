#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  Bureaucrat test1("test1", 1);

  std::cout << "-------------------------------" << std::endl;
  Bureaucrat test2("test2", 150);

  std::cout << "-------------------------------" << std::endl;
  { Bureaucrat test3("test3", 0); }

  std::cout << "-------------------------------" << std::endl;
  { Bureaucrat test3("test4", 151); }

  std::cout << "----------------test1 increment---------------" << std::endl;
  try {
    test1.incrementGrade(1);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << test1 << std::endl;
  std::cout << "----------------test2 decrement---------------" << std::endl;
  try {
    test2.decrementGrade(1);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << test2 << std::endl;
}