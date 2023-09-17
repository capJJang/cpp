#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <ostream>
#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string target_;

 public:
  ShrubberyCreationForm(/* args */);
  virtual ~ShrubberyCreationForm() throw();
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

  void execute(Bureaucrat const &executor) const;
};

#endif