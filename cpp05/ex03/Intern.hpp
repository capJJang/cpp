#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern : public std::exception {
 private:
  class InvalidFormNameException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Invalid form name"; }
  } public : Intern(/* args */);
  virtual ~Intern() throw();
  Intern(const Intern &rhs);
  Intern &operator=(const Intern &rhs);

  AForm *makeForm(std::string name, std::name target);
};