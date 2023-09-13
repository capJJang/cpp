#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat bureaucrat("bureaucrat", 1);
  AForm* shrubbery = new ShrubberyCreationForm("shrubbery");

  std::cout << "---------------Shrubbery-------------" << std::endl;
  try {
    bureaucrat.signAForm(*shrubbery);  // pointer or reference..?
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    bureaucrat.executeAForm(*shrubbery);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    bureaucrat.executeAForm(*shrubbery);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  delete shrubbery;
  shrubbery = NULL;

  std::cout << "---------------Robotomy-------------" << std::endl;
  AForm* robotomy = new RobotomyRequestForm("robotomy");

  try {
    bureaucrat.signAForm(*robotomy);  // pointer or reference..?
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    bureaucrat.executeAForm(*robotomy);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  delete robotomy;
  robotomy = NULL;

  std::cout << "---------------Presidential-------------" << std::endl;
  AForm* presidential = new PresidentialPardonForm("presidential");

  try {
    bureaucrat.signAForm(*presidential);  // pointer or reference..?
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    bureaucrat.executeAForm(*presidential);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  delete presidential;
  presidential = NULL;
  std::cout << "----------------------------" << std::endl;
}
