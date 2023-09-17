#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

// #include "AForm.hpp"
class AForm;

class Bureaucrat {
 private:
  const std::string name_;
  int grade_;

 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  Bureaucrat(/* args */);
  Bureaucrat(std::string name, int grade);
  virtual ~Bureaucrat() throw();
  Bureaucrat(const Bureaucrat &rhs);
  Bureaucrat &operator=(const Bureaucrat &rhs);

  std::string getName() const;
  int getGrade() const;

  void incrementGrade(int amount);
  void decrementGrade(int amount);
  void signAForm(AForm &AForm);  // pointer or reference..?
  void executeAForm(AForm const &aForm);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif