#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(/* args */) {
  std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() throw() {
  std::cout << *this << " Desstructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
  try {
    if (grade < 1) throw Bureaucrat::GradeTooLowException();
    if (grade > 150) throw Bureaucrat::GradeTooHighException();
    this->grade_ = grade;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << this->name_ << " Conversion constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) {
  std::cout << "Copy constructor called" << std::endl;
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
  this->grade_ += amount;
  if (this->getGrade() < 1) throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrementGrade(int amout) {
  this->grade_ -= amout;
  if (this->getGrade() < 1) throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
  out << "Name, " << rhs.getName() << "  grade " << rhs.getGrade() << std::endl;
  return out;
}