#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T, typename L, typename F>
void iter(T* array, L length, F f) {
  for (L i = 0; i < length; ++i) f(array[i]);
}

template <typename T>
void f(const T& element) {
  std::cout << element << " ";
}
#endif