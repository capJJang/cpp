#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat test1("test1", 1);
  AForm* test2 = new ShrubberyCreationForm("test2");

  try {
    test1.signAForm(*test2);  // pointer or reference..?
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    test1.executeAForm(*test2);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    test1.executeAForm(*test2);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  delete test2;
  test2 = NULL;

  AForm* test3 = new RobotomyRequestForm("test3");

  try {
    test1.signAForm(*test3);  // pointer or reference..?
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    test1.executeAForm(*test3);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  delete test2;
  test2 = NULL;
}
