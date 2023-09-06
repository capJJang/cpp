#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(/* args */) {
  std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() { std::cout << "Desstructor called" << std::endl; }

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

void Bureaucrat::incrementGrade(int amount) { this->grade_ += amount; }

void Bureaucrat::decrementGrade(int amout) { this->grade_ -= amout; }

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
  out << "Name, " << rhs.getName() << "  grade " << rhs.getGrade() << std::endl;
  return out;
}