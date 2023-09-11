#include <exception>
#include <ostream>
#include <string>

class Bureaucrat : public std::exception {
 private:
  const std::string name_;
  int grade_;

 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Grade is too high"; }
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Grade is too low"; }
  };

  Bureaucrat(/* args */);
  Bureaucrat(std::string name, int grade);
  virtual ~Bureaucrat() throw();
  Bureaucrat(const Bureaucrat &rhs);
  Bureaucrat &operator=(const Bureaucrat &rhs);

  std::string getName() const;
  int getGrade() const;

  void incrementGrade(int amount);
  void decrementGrade(int amount);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);