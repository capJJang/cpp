#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>

// #include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 private:
  const std::string name_;
  bool isSigned_;
  const int gradeForSign_;
  const int gradeForExecute_;

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

 protected:
  class FormNotSignedException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

 public:
  AForm(/* args */);
  AForm(const std::string name, int gradeForSign, int gradeForExecute);
  AForm(const std::string name);
  AForm(const AForm &rhs);
  virtual ~AForm() throw();
  AForm &operator=(const AForm &rhs);

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeForSigned() const;
  int getGradeForExecute() const;

  void setIsSigned(bool isSigned);

  void beSigned(Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &rhs);

#endif