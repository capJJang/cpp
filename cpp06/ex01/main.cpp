#include <iostream>

#include "Serializer.hpp"
int main(void) {
  Data test;

  test.intTest = 123;
  test.strintTest = "test";
  test.floatTest = 123.123;
  std::cout << "before serialize : " << &test << std::endl;

  uintptr_t serializeRet = Serializer::serialize(&test);
  std::cout << "after serialize :" << serializeRet << std::endl;
  Data* afterTest = Serializer::deserialize(serializeRet);

  std::cout << "after deserialize : " << afterTest << std::endl;
  std::cout << afterTest->intTest << std::endl;
  std::cout << afterTest->strintTest << std::endl;
  std::cout << afterTest->floatTest << std::endl;
}