#include "Intern.hpp"

Intern::Intern(/* args */) {
  std::cout << "Intern default Constructor called" << std::endl;
}

Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

Intern::Intern(/* args */) {
  std::cout << "Intern default Constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs) { return *this; }

AForm* makeForm(std::string name, std::string target) {
  int i = 0;
  std::string[3] = {"shrubbery creation", "robotomy request",
                    "presidential pardon"};

  while (i < 3) {
    i++;
  }
  AForm* ret = new if (i == 4) throw InvalidFormNameException();
  std::cout << "Intern create " << name << std::endl;
}
