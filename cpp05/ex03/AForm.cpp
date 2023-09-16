#include "AForm.hpp"

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

AForm::AForm(/* args */) {}

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

AForm::AForm(const AForm &rhs) {
  std::cout << "Copy constructor called" << std::endl;
  *this = rhs;
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

void AForm::setGradeForSigned(int gradeForSign) {
  this->gradeForSign_ = gradeForSign;
}

void AForm::setGradeForExecute(int gradeForExecute) {
  this->gradeForExecute_ = gradeForExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (this->getGradeForSigned() < bureaucrat.getGrade())
    throw Bureaucrat::GradeTooLowException();
  this->isSigned_ = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs) {
  out << "name: " << rhs.getName() << " is signed: " << rhs.getIsSigned()
      << " grade for sign: " << rhs.getGradeForSigned()
      << " grade for execute:" << rhs.getGradeForExecute() << std::endl;
  return out;
}