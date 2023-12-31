#include "PresidentialPardonForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(/* args */) {
  std::cout << "Presidential pardon form constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() throw() {
  std::cout << "Presidential pardon form destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon", 25, 5), target_(target) {
  std::cout << "Presidential pardon form conversion constructor called"
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &rhs)
    : AForm(rhs.getName(), rhs.getGradeForSigned(), rhs.getGradeForExecute()) {
  std::cout << "Presidential pardon form conversion constructor called"
            << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &rhs) {
  if (this == &rhs) return *this;
  this->setIsSigned(rhs.getIsSigned());
  return *this;
}

// 코드 중복 줄이는 방법...?

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (this->getIsSigned() == false) throw AForm::FormNotSignedException();
  if (this->getGradeForExecute() < executor.getGrade())
    throw Bureaucrat::GradeTooLowException();

  std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
