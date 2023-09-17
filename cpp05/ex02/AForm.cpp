#include "AForm.hpp"

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

AForm::AForm(/* args */) : gradeForSign_(0), gradeForExecute_(0) {}

AForm::~AForm() throw() {
  std::cout << "AForm " << this->name_ << " Desstructor called" << std::endl;
}

AForm::AForm(const std::string name, int gradeForSign, int gradeForExecute)
    : name_(name),
      isSigned_(false),
      gradeForSign_(gradeForSign),
      gradeForExecute_(gradeForExecute) {
  std::cout << "AForm " << name << " conversion constructor called"
            << std::endl;
}

AForm::AForm(const AForm &rhs)
    : name_(rhs.getName()),
      isSigned_(rhs.getIsSigned()),
      gradeForSign_(rhs.getGradeForSigned()),
      gradeForExecute_(rhs.getGradeForExecute()) {
  std::cout << "Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs) {
  if (this == &rhs) return *this;
  this->isSigned_ = rhs.isSigned_;
  return *this;
}

std::string AForm::getName() const { return this->name_; }

bool AForm::getIsSigned() const { return this->isSigned_; }

int AForm::getGradeForSigned() const { return this->gradeForSign_; }

int AForm::getGradeForExecute() const { return this->gradeForExecute_; }

void AForm::setIsSigned(bool isSigned) { this->isSigned_ = isSigned; }

void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (this->getGradeForSigned() < bureaucrat.getGrade())
    throw Bureaucrat::GradeTooLowException();
  this->isSigned_ = true;
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs) {
  out << "name: " << rhs.getName() << " is signed: " << rhs.getIsSigned()
      << " grade for sign: " << rhs.getGradeForSigned()
      << " grade for execute:" << rhs.getGradeForExecute() << std::endl;
  return out;
}