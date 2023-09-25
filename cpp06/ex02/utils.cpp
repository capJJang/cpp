#include "utils.h"

#include <exception>
#include <iostream>

Base *generate(void) {
  int seed = 0;
  Base *ret;

  switch (reinterpret_cast<unsigned long>(&seed) % 3) {
    case 0:
      ret = new A();
      break;
    case 1:
      ret = new B();
      break;
    case 2:
      ret = new C();
      break;
  }
  return ret;
}

void identify(Base *p) {
  A *a = dynamic_cast<A *>(p);
  B *b = dynamic_cast<B *>(p);
  C *c = dynamic_cast<C *>(p);

  if (a)
    std::cout << "A ptr" << std::endl;
  else if (b)
    std::cout << "B ptr" << std::endl;
  else if (c)
    std::cout << "C ptr" << std::endl;
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "Type is A" << std::endl;
  } catch (const std::exception &e) {
  }

  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "Type is B" << std::endl;
  } catch (const std::exception &e) {
  }

  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "Type is C" << std::endl;
  } catch (const std::exception &e) {
  }
}