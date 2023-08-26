#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap test1("test");

  std::cout << test1 << std::endl;
  test1.attack("test2");
  std::cout << test1 << std::endl;
  test1.beRepaired(1);
  std::cout << test1 << std::endl;
  test1.takeDamage(1);
  std::cout << test1 << std::endl;
  // std::cout << test1 << std::endl;
  // ClapTrap test2(test1);
  // ClapTrap test3(test2);
  // std::cout << test2 << std::endl << test3 << std::endl;
  // test2.attack("test3");
  // std::cout << test2 << std::endl << test3 << std::endl;
}
