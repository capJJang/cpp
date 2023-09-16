#include "Intern.hpp"

Intern::Intern(/* args */) {
  std::cout << "Intern default Constructor called" << std::endl;
}

Intern::~Intern() throw() {
  std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& rhs) {
  (void)rhs;
  std::cout << "Intern conversion Constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs) {
  (void)rhs;
  return *this;
}

AForm *Intern::makeShrubberyCreationForm(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRuquestForm(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) {
  int i = 0;
  std::string candidateForm[3] = {"shrubbery creation", "robotomy request",
                                  "presidential pardon"};
AForm *(Intern::*candidateMethod[3])(std::string) = {
    &Intern::makeShrubberyCreationForm,
    &Intern::makeRobotomyRuquestForm,
    &Intern::makePresidentialPardonForm,
};

  while (i < 4) {
    if (name == candidateForm[i]) break;
    i++;
  }
  if (i == 4) throw InvalidFormNameException();
  std::cout << "Intern create " << name << std::endl;
  return (this->*candidateMethod[i])(target);
}
