#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <string>

struct Data {
  int intTest;
  std::string strintTest;
  float floatTest;
};

class Serializer {
 private:
  Serializer(/* args */);
  ~Serializer();
  Serializer(const Serializer &rhs);
  Serializer &operator=(const Serializer &rhs);
  /* data */
 public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif