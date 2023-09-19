#include "Bureaucrat.hpp"

#include <iostream>

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

  std::cout << "Bureaucrat " << this->name_ << " Conversion constructor called"
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

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::string Bureaucrat::getName() const { return (this->name_); }

int Bureaucrat::getGrade() const { return (this->grade_); }

void Bureaucrat::incrementGrade(long amount) {
  if (this->getGrade() - amount < 1) throw Bureaucrat::GradeTooHighException();
  if (this->getGrade() - amount > 150) throw Bureaucrat::GradeTooLowException();
  this->grade_ -= amount;
}

void Bureaucrat::decrementGrade(long amount) {
  if (this->getGrade() + amount > 150) throw Bureaucrat::GradeTooLowException();
  if (this->getGrade() + amount < 1) throw Bureaucrat::GradeTooHighException();
  this->grade_ += amount;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
  out << "Name, " << rhs.getName() << "  grade " << rhs.getGrade();
  return out;
}