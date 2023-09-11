#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat test1("test1", 1);
  AForm *test2 = new ShrubberyCreationForm("Shrubbery");
  
  try
  {
	  test1.signAForm(*test2);    //pointer or reference..?
  }
  catch(const std::exception& e)
  {
	  std::cerr << e.what() << '\n';
  }

  try
  {
    test1.executeAForm(*test2);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
}
