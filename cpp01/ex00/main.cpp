#include "Zombie.hpp"

int main(void) {
  Zombie *test = newZombie("test1");
  test->announce();
  delete (test);
  randomChump("test2");
}
