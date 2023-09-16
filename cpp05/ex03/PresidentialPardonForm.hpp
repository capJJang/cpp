#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string target_;

 public:
  PresidentialPardonForm(/* args */);
  virtual ~PresidentialPardonForm() throw();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &rhs);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

  void execute(Bureaucrat const &executor) const;
};

#endif