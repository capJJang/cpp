#include "Bureaucrat.hpp"

#include <iostream>

#include "AForm.hpp"

Bureaucrat::Bureaucrat(/* args */) {
  std::cout << "Bureaucrat " << this->getName() << " constructor called"
            << std::endl;
}

Bureaucrat::~Bureaucrat() throw() {
  std::cout << "Bureaucrat " << this->name_ << " Desstructor called"
            << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
  try {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
    this->grade_ = grade;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "Bureaucra t" << this->name_ << " Conversion constructor called"
            << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) {
  std::cout << "Bureaucrat Copy constructor called" << std::endl;
  *this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this == &rhs) return *this;
  this->grade_ = rhs.grade_;
  return *this;
}

std::string Bureaucrat::getName() const { return (this->name_); }

int Bureaucrat::getGrade() const { return (this->grade_); }

void Bureaucrat::incrementGrade(int amount) {
  if (this->getGrade() - amount > 150)
    throw Bureaucrat::GradeTooLowException();
  this->grade_ -= amount;
}

void Bureaucrat::decrementGrade(int amount) {
  if (this->getGrade() + amount < 1) throw Bureaucrat::GradeTooHighException();
  this->grade_ += amount;
}

void Bureaucrat::signAForm(AForm &AForm) {
  try {
    AForm.beSigned(*this);
    std::cout << this->name_ << " signs " << AForm.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

void Bureaucrat::executeAForm(AForm const &aForm) {
  try {
    aForm.execute(*this);
    std::cout << this->name_ << " executes " << aForm.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
  out << "Name, " << rhs.getName() << "  grade " << rhs.getGrade();
  return out;
}