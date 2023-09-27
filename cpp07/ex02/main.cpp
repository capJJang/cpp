#include <iostream>

#include "Array.hpp"

int main(void) {
  Array<int> test;
  std::cout << test.size() << std::endl;

  Array<int> test2(10);
  std::cout << test2.size() << std::endl;

  std::cout << "---------------------" << std::endl;
  try {
    test2[10];
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    test2[-1];
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "---------------------" << std::endl;
  Array<int> test3(test2);
  test3[0] = 1;

  std::cout << test3[0] << std::endl;
  std::cout << test2[0] << std::endl;

  std::cout << "---------------------" << std::endl;
  test2 = test3;
  std::cout << test2[0] << std::endl;
  std::cout << test2.size() << std::endl;

  Array<char> test4(1);
  test4[0] = 'a';
  std::cout << test4[0] << std::endl;
}