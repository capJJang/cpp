#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  Bureaucrat b1("b1", 1);
  Bureaucrat b150("b150", 150);

  Form f1("f1", 1, 1);
  Form f150("f150", 150, 150);
  std::cout << "-------------------------------" << std::endl;
  try {
    b1.signForm(f1);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "-------------------------------" << std::endl;
  try {
    b150.signForm(f1);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "-------------------------------" << std::endl;
  b150.incrementGrade(149);
  b1.decrementGrade(149);
  try {
    b1.signForm(f1);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "-------------------------------" << std::endl;
  try {
    b150.signForm(f1);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "-------------------------------" << std::endl;
}

// int main() {
//   Bureaucrat test1("test1", 1);
//   std::cout << "-------------------------------" << std::endl;
//   Bureaucrat test2("test2", 150);
//   std::cout << "-------------------------------" << std::endl;
//   try {
//     Bureaucrat test3("test3", 0);
//   } catch (const std::exception& e) {
//     std::cerr << e.what() << '\n';
//   }
//   std::cout << "-------------------------------" << std::endl;
//   try {
//     Bureaucrat test3("test4", 151);
//   } catch (const std::exception& e) {
//     std::cerr << e.what() << '\n';
//   }
//   std::cout << "----------------test1 decrement---------------" << std::endl;
//   try {
//     test1.decrementGrade(1);
//   } catch (const std::exception& e) {
//     std::cerr << e.what() << '\n';
//   }
//   std::cout << test1 << std::endl;
//   std::cout << "----------------test2 increment---------------" << std::endl;
//   try {
//     test2.incrementGrade(1);
//   } catch (const std::exception& e) {
//     std::cerr << e.what() << '\n';
//   }
//   std::cout << test2 << std::endl;
// }