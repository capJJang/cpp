#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
  // ClapTrap test1("test");

  // std::cout << test1 << std::endl;
  // test1.attack("babo");
  // std::cout << test1 << std::endl;
  // ClapTrap test2(test1);
  // ClapTrap test3(test2);
  // std::cout << test2 << std::endl << test3 << std::endl;
  // test2.attack("test3");
  // std::cout << test2 << std::endl << test3 << std::endl;
  FragTrap test("test");
  std::cout << test << std::endl;
  // test.guardGate();
  // test.attack("test1");
  // test.attack("asdf");
  test.highFiveGuys();
  std::cout << test << std::endl;
}