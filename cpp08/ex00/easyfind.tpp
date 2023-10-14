#include "easyfind.hpp"

template <typename T>
int easyfind(T &v, int target) {
  typename T::iterator iter;

  iter = std::find(v.begin(), v.end(), target);
  if (iter == v.end()) throw std::runtime_error("Target not found");
  return *iter;
}