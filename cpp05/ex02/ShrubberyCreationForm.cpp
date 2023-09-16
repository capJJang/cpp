#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(/* args */) {
  std::cout << "Shrubbery creation form constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw() {
  std::cout << "Shrubbery creation form destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shurubbery", 145, 137), target_(target) {
  std::cout << "Shrubbery creation form conversion constructor called"
            << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
    : AForm(rhs.getName(), rhs.getGradeForSigned(), rhs.getGradeForExecute()) {
  // *this = rhs;
  std::cout << "Shrubbery creation form conversion constructor called"
            << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &rhs) {
  if (this == &rhs) return *this;
  this->setIsSigned(rhs.getIsSigned());
  return *this;
}

// 코드 중복 줄이는 방법...?

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (this->getIsSigned() == false) throw AForm::FormNotSigned();
  if (this->getGradeForExecute() < executor.getGrade())
    throw Bureaucrat::GradeTooLowException();

  try {
    std::ofstream file(this->target_ + "_shrubbery");

    if (!file.is_open()) {
      throw std::runtime_error("File open Failed");
    }
    for (int i = 1; i <= 5; i++) {
      for (int j = 0; j < 5 - i; j++) {
        file << " ";
      }
      for (int j = 0; j < 2 * i - 1; j++) {
        file << "*";
      }
      file << std::endl;
    }
    for (int i = 0; i < 5 - 1; i++) {
      for (int j = 0; j < 5 - 1; j++) {
        file << " ";
      }
      file << "|" << std::endl;
    }
    file.close();
    std::cout << "Execution of Shrubbery form success!" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}
