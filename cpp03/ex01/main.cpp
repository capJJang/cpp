#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
  ScavTrap test("test");
  test.guardGate();
  test.attack("test1");
  test.beRepaired(10);
  test.takeDamage(11);
}