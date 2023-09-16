#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  class RobotomizedFailedException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Robotomized failed"; }
  };
  std::string target_;

 public:
  PresidentialPardonForm(/* args */);
  virtual ~PresidentialPardonForm() throw();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &rhs);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

  void execute(Bureaucrat const &executor) const;
};

#endif