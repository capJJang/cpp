#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  Animal* dog = new Dog();
  Animal* cat = new Cat();
  Cat* deepCopyTest1 = new Cat();
  Cat* deepCopyTest2 = new Cat();

  std::cout << "----------------------------------------------" << std::endl;
  *deepCopyTest2 = *deepCopyTest1;
  delete dog;  // should not create a leak
  delete cat;
  delete deepCopyTest1;
  cat = NULL;
  dog = NULL;
  deepCopyTest1 = NULL;

  delete deepCopyTest2;
  deepCopyTest2 = NULL;
  //system("leaks a.out");
  return 0;
}
