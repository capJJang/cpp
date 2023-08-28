#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* animal = new Animal();
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << dog->getType() << " " << std::endl;
  std::cout << cat->getType() << " " << std::endl;
  std::cout << wrongCat->getType() << " " << std::endl;

  cat->makeSound();  // will output the cat sound!
  dog->makeSound();
  animal->makeSound();
  std::cout << "----Virtual funcion test-----" << std::endl;
  wrongCat->makeSound();

  delete animal;
  animal = NULL;
  delete dog;
  dog = NULL;
  delete cat;
  cat = NULL;
  delete wrongCat;
  wrongCat = NULL;
  return 0;
}
