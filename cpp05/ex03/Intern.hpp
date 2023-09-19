#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 private:
  class InvalidFormNameException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  AForm *makeShrubberyCreationForm(std::string target);
  AForm *makeRobotomyRuquestForm(std::string target);
  AForm *makePresidentialPardonForm(std::string target);

 public:
  Intern(/* args */);
  virtual ~Intern() throw();
  Intern(const Intern &rhs);
  Intern &operator=(const Intern &rhs);

  AForm *makeForm(std::string name, std::string target);
};
