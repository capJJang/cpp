#include <ostream>
#include <string>

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;

 public:
  Bureaucrat(/* args */);
  Bureaucrat(std::string name);
  virtual ~Bureaucrat();
  Bureaucrat(const Bureaucrat &rhs);
  Bureaucrat &operator=(const Bureaucrat &rhs);

  std::string getName() const;
  int getGrade() const;

  void incrementGrade(int amount);
  void decrementGrade(int amount);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);