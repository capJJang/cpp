#include "Form.hpp"

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

Form::Form(/* args */) {}

Form::~Form() throw() {
  std::cout << "Form " << this->name_ << " Desstructor called" << std::endl;
}

Form::Form(const std::string name, int gradeForSign, int gradeForExecute)
    : name_(name),
      isSigned_(false),
      gradeForSign_(gradeForSign),
      gradeForExecute_(gradeForExecute) {
  std::cout << "Form " << name << " conversion constructor called" << std::endl;
}

Form::Form(const Form &rhs)
    : name_(rhs.getName()),
      isSigned_(false),
      gradeForSign_(rhs.getGradeForSigned()),
      gradeForExecute_(rhs.getGradeForExecute()) {
  std::cout << "Copy constructor called" << std::endl;
  *this = rhs;
}

Form &Form::operator=(const Form &rhs) {
  if (this == &rhs) return *this;

  this->isSigned_ = rhs.isSigned_;
  return *this;
}

std::string Form::getName() const { return this->name_; }

bool Form::getIsSigned() const { return this->isSigned_; }

int Form::getGradeForSigned() const { return this->gradeForSign_; }

int Form::getGradeForExecute() const { return this->gradeForExecute_; }

void Form::beSigned(Bureaucrat &bureaucrat) {
  if (this->getGradeForSigned() < bureaucrat.getGrade())
    throw Bureaucrat::GradeTooLowException();
  this->isSigned_ = true;
}

std::ostream &operator<<(std::ostream &out, const Form &rhs) {
  out << "name: " << rhs.getName() << " is signed: " << rhs.getIsSigned()
      << " grade for sign: " << rhs.getGradeForSigned()
      << " grade for execute:" << rhs.getGradeForExecute() << std::endl;
  return out;
}