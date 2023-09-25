#include "RobotomyRequestForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(/* args */) {
  std::cout << "Robotomy Request form constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() throw() {
  std::cout << "Robotomy Request form destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request", 72, 45), target_(target) {
  std::cout << "Robotomy Request form conversion constructor called"
            << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
    : AForm(rhs.getName(), rhs.getGradeForSigned(), rhs.getGradeForExecute()) {
  std::cout << "Robotomy Request form conversion constructor called"
            << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &rhs) {
  if (this == &rhs) return *this;
  this->setIsSigned(rhs.getIsSigned());
  return *this;
}

// 코드 중복 줄이는 방법...?

const char *RobotomyRequestForm::RobotomizedFailedException::what() const
    throw() {
  return "Robotomized failed";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (this->getIsSigned() == false) throw AForm::FormNotSignedException();
  if (this->getGradeForExecute() < executor.getGrade())
    throw Bureaucrat::GradeTooLowException();

  int test = 1;
  if (reinterpret_cast<unsigned long>(&test) / 10 % 2 == 0)
    std::cout << this->target_ << " Robomomized failed.." << std::endl;
  else
    std::cout << this->target_ << " Robomomized success" << std::endl;
  // std::cout << "n : " << n << std::endl;
}
