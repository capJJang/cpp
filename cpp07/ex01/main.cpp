#include <string>

#include "iter.hpp"

int main(void) {
  const char *test = "Hello World.";
  iter(test, 12, f<char>);
  std::cout << std::endl;

  int test2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  iter(test2, 10, f<int>);
}