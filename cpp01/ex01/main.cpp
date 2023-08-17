#include "Zombie.hpp"

int main(void) {
  Zombie *horde = zombieHorde(10, "test");
  (void)horde;
  delete[] horde;
}
