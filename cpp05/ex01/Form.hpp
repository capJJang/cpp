#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

#include "Bureaucrat.hpp"

class Form : public std::exception {
 private:
  const std::string name_;
  bool isSigned_;
  int gradeForSign_;
  int gradeForExecute_;

 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Grade is too high"; }
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Grade is too low"; }
  };

  Form(/* args */);
  Form(const std::string name, int gradeForSign, int gradeForExecute);
  Form(const Form &rhs);
  virtual ~Form() throw();
  Form &operator=(const Form &rhs);

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeForSigned() const;
  int getGradeForExecute() const;

  void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif