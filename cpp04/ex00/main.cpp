#include <cstdlib>
#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  const WrongAnimal* k = new WrongCat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << k->getType() << " " << std::endl;

  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  std::cout << "----Virtual funcion test-----" << std::endl;
  k->makeSound();

  delete meta;
  meta = NULL;
  delete j;
  j = NULL;
  delete i;
  i = NULL;
  delete k;
  k = NULL;
  return 0;
  // system("valgrind --leak-check=full ./a.out");
  // while (true) {
  //   /* code */
  // }
}
