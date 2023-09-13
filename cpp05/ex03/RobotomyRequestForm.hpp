#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  class RobotomizedFailedException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Robotomized failed"; }
  };
  std::string target_;

 public:
  RobotomyRequestForm(/* args */);
  virtual ~RobotomyRequestForm() throw();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &rhs);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

  void execute(Bureaucrat const &executor) const;
};

#endif