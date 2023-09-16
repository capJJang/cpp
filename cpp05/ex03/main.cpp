#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat bureaucrat("bureaucrat", 1);
  Intern intern;

  AForm *test1 = intern.makeForm("shrubbery creation", "test1");
  std::cout << "----------------------------" << std::endl;
  bureaucrat.signAForm(*test1);
  bureaucrat.executeAForm(*test1);
  std::cout << "----------------------------" << std::endl;
  delete test1;
  test1 = NULL;

  std::cout << "----------------------------" << std::endl;

  try {
    AForm *test2 = intern.makeForm("asdf", "test2");
    bureaucrat.signAForm(*test2);
    bureaucrat.executeAForm(*test2);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "----------------------------" << std::endl;
}
